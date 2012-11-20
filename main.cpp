#include <QtGui/QApplication>
#include "renderfarmmanagerwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RenderFarmManagerWindow w;
    w.show();
    
    return a.exec();
}
