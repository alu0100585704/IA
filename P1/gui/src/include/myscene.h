#pragma once
#include <QGraphicsScene>
#include <myitem.h>
class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MyScene(QObject * parent =nullptr);

public slots:
     void onUpdate();

private:
    MyItem *mImg_;
};

