#include "simplesshconnection.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <QDebug>

SimpleSSHConnection::SimpleSSHConnection(QHostAddress address, quint16 port, QString username, QString password, QObject *parent) :
    QObject(parent)
{
    //Make the connection
    //C stuff

    unsigned long cHostAddress;
    int sock, i, auth_pw = 0;
    struct sockaddr_in sin;
    const char * fingerprint;
    char * userAuthList;

    cHostAddress = address.toIPv4Address();

    if(libssh2_init(0) != 0) {
        qWarning() << "libssh2 init failed";
    }
    sock = socket(AF_INET, SOCK_STREAM, 0);

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = cHostAddress;

    if(::connect(sock, (struct sockaddr*)(&sin), sizeof(struct sockaddr_in)) != 0) {
        qWarning() << "Connection failed";
    }

    session = libssh2_session_init();

    if(libssh2_session_startup(session, sock)) {
        qWarning() << "Failure establishing session";
    }

    //Convert username and password to C strings
    QByteArray usernameBA = username.toUtf8();
    const char * username_cstr = usernameBA.data();
    QByteArray passwordBA = password.toUtf8();
    const char * password_cstr = passwordBA.data();

    //password auth
    auth_pw |= 1;

    libssh2_userauth_list(session, username_cstr, username.length());

    if(libssh2_userauth_password(session, username_cstr, password_cstr)) {
        qWarning() << "Password auth failed";
    } else {
        qDebug() << "Password auth successful";
    }

    if(!(channel = libssh2_channel_open_session(session))) {
        qDebug() << "Failed to open session";
    }

    if(libssh2_channel_request_pty(channel, "vanilla")) {
        qDebug() << "Failed to request channel PTY";
    }

    libssh2_channel_set_blocking(channel, 1); //enable blocking

    //Hook this up so that the SSH connection will be closed before this object is deleted
    connect(this, SIGNAL(destroyed()), this, SLOT(closeChannel()));
}

void SimpleSSHConnection::startProgram(QString path, QString args) {
    QString command = path + ' ' + args + '\n';

    QByteArray commandBA = command.toUtf8();
    libssh2_channel_write(channel, commandBA.data(), commandBA.length());
}

void SimpleSSHConnection::startSudoProgram(QString rootPassword, QString path, QString args) {
    QByteArray commandBA = "sudo " + path.toUtf8() + ' ' + args.toUtf8();
    //Wait for a colon to be output
    while(true) {
        //read 1 character
        char buffer[1];
        ssize_t readCount = libssh2_channel_read(channel, buffer, 1);

        if(readCount != 1) {
            qWarning() << "Waiting for password prompt: Read" << readCount << "bytes.";
        }

        if(buffer[1] == ':') {
            //Colon detected: password prompt done

            //Send the password
            QByteArray rootPasswordBA = rootPassword.toUtf8();

            libssh2_channel_write(channel, rootPasswordBA, rootPasswordBA.length());
            break;
        }
    }
}

void SimpleSSHConnection::closeChannel() {
    libssh2_session_disconnect(session, "Disconnecting");
    libssh2_session_free(session);
}
