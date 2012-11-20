#ifndef RENDERFARMMANAGERWINDOW_HPP
#define RENDERFARMMANAGERWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class RenderFarmManagerWindow;
}

class RenderFarmManagerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RenderFarmManagerWindow(QWidget *parent = 0);
    ~RenderFarmManagerWindow();
    
private:
    Ui::RenderFarmManagerWindow *ui;
};

#endif // RENDERFARMMANAGERWINDOW_HPP
