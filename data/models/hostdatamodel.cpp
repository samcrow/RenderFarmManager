#include "hostdatamodel.hpp"
#include <QProcess>

HostDataModel::HostDataModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    hostSearchTimerId = startTimer(10000);
}

void HostDataModel::timerEvent(QTimerEvent *event) {
    if(event->timerId() == hostSearchTimerId) {
        startHostSearch();
    }
}

void HostDataModel::startHostSearch() {
    searchProcess = new QProcess(this);
    searchProcess->start(":/SSHSearch/SSHSearchExec/name");//TODO: Add the correct name
}

void HostDataModel::searchFinished() {
    QByteArray output = searchProcess->readAll();

    //TODO: parse output

    searchProcess->deleteLater();
}
