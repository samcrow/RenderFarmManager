#ifndef HOST_HPP
#define HOST_HPP

#include <QObject>
#include <QHostAddress>

/**
  Represents a render host on the network
  */
class Host : public QObject
{
    Q_OBJECT
public:
    explicit Host(QObject *parent = 0);

    /**
      Shut down this host (synchronously).
      This function SSHs to the host and gives the command "sudo shutdown -h now".
      It returns once the remote shutdown command has exit or the host has disconnected.
      */
    void shutDown();

    /**
      Shut down this host synchronously.
      This acts the shame as shutDown(), but returns immediately
      */
    void shutDownAsync();

    /**
      Restart this host (synchronously).
      This function SSHs to the host and gives the command "sudo reboot".
      It returns once the host has been restarted and an SSH connection has been re-established
      */
    void restart();

    /**
      Restart this host asynchronously.
      This acts the same as restart(), but returns immediately
      */
    void restartAsync();

    /**
      Comparison: Returns true if two hosts have equal names, otherwise returns false
      */
    bool operator == (Host& other);

    /**
      Get the host name
      */
    QString getName();

    /**
      Get the remote address
      */
    QHostAddress getAddress();

    /**
      Get the TCP port
      */
    quint16 getPort();

protected:

    /** The computer's name */
    QString name;
    /** The computer's IP address */
    QHostAddress address;
    /** The TCP port number to connect on */
    quint16 port;

signals:

public slots:

};

#endif // HOST_HPP
