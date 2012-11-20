#include "renderfarmmanagerwindow.hpp"
#include "ui_renderfarmmanagerwindow.h"

RenderFarmManagerWindow::RenderFarmManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenderFarmManagerWindow)
{
    ui->setupUi(this);
}

RenderFarmManagerWindow::~RenderFarmManagerWindow()
{
    delete ui;
}
