#ifndef SSHCONNECTION_HPP
#define SSHCONNECTION_HPP

#include <QIODevice>
#include <QHostAddress>

#include <libssh2.h>

/**
  An IO device that connects to a shell on a remote computer over SSH
  */
class SSHConnection : public QIODevice
{
    Q_OBJECT
public:

    explicit SSHConnection(QHostAddress address, quint16 port, QString username, QString password, QObject *parent = 0);

    bool open(OpenMode mode);

    bool isSequential() const;

    void readData(char *data, qint64 maxlen);

    void writeData(const char *data, qint64 len);

private:

    LIBSSH2_SESSION * session;

    LIBSSH2_CHANNEL * channel;

    QHostAddress address;

    quint16 port;

    QByteArray username;

    QByteArray password;

signals:

public slots:

};

#endif // SSHCONNECTION_HPP
