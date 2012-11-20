#include "host.hpp"

Host::Host(QObject *parent) :
    QObject(parent)
{
}

void Host::shutDown() {

}

void Host::shutDownAsync() {

}

void Host::restart() {

}

void Host::restartAsync() {

}

bool Host::operator == (Host& other) {
    return this->name == other.name;
}
