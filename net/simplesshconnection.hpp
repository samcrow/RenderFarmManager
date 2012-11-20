#ifndef SIMPLESSHCONNECTION_HPP
#define SIMPLESSHCONNECTION_HPP

#include <QObject>
#include <QHostAddress>

#include <libssh2.h>

/**
  A simple connection to an SSH host using libssh2
  */
class SimpleSSHConnection : public QObject
{
    Q_OBJECT
public:
    /**
      This constructor connects to the host synchronously and returns when a connection has been made successfully.
      @param address The address of the computer to connect to
      @param port The port to connect on
      @param username The username to log on as
      @param password The password to use to log on
      */
    explicit SimpleSSHConnection(QHostAddress address, quint16 port, QString username, QString password, QObject *parent = 0);

    /**
      Start a remote program on the remote host
      @param path The path to the program on the remote host. This can be absolute
      or it can refer to a program in the remote computer's PATH.
      @param args A set of arguments to provide to the command, separated by spaces
      */
    void startProgram(QString path, QString args);

    /**
      Start a remote program on the remote host as the superuser
      @param rootPassword The root password to provide to the remote sudo program
      @param path The path to the program on the remote host. This can be absolute
      or it can refer to a program in the remote computer's PATH.
      @param args A set of arguments to provide to the command, separated by spaces
      */
    void startSudoProgram(QString rootPassword, QString path, QString args);

private:
    LIBSSH2_SESSION * session;
    LIBSSH2_CHANNEL * channel;

signals:

public slots:

private slots:

    /**
      Close and free the SSH channel
      */
    void closeChannel();

};

#endif // SIMPLESSHCONNECTION_HPP
