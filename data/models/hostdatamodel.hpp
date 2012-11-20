#ifndef HOSTDATAMODEL_HPP
#define HOSTDATAMODEL_HPP

#include <QAbstractTableModel>
#include <QTimerEvent>

//Forward-declare classes
class QProcess;

/**
  @brief A data model that maintains a list of render farm hosts

  It periodically invokes a seperate program to search for hosts using Bonjour
  */
class HostDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit HostDataModel(QObject *parent = 0);


private:

    /**
      The timer ID for the timer used to search for hosts
      */
    int hostSearchTimerId;

    /**
      The process used to search for hosts
      */
    QProcess * searchProcess;

    void timerEvent(QTimerEvent * event);

    /**
      Start the external process to search for hosts
      */
    void startHostSearch();

signals:

public slots:

private slots:

    /**
      Sent by the search process when it ends
      */
    void searchFinished();

};

#endif // HOSTDATAMODEL_HPP
