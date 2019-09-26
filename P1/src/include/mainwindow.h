#pragma once
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MyScene;
class MyItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MyScene * mScene_;

};

