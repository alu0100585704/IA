#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <myscene.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 //   layout()->setMargin(0);
    mScene_=new MyScene(this);
    ui->graphicsView->setScene(mScene_);
}

MainWindow::~MainWindow()
{
    delete ui;
}
