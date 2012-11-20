#include "sshconnection.hpp"

SSHConnection::SSHConnection(QHostAddress address, quint16 port, QString username, QString password, QObject *parent) {

}

bool SSHConnection::isSequential() {
    return true;
}
