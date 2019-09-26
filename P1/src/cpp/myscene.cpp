#include "myscene.h"
#include <myitem.h>

#define XPOS 0.0
#define YPOS 0.0
#define WIDTH 600.0
#define HEIGHT 600.0

MyScene::MyScene(QObject *parent)
 : QGraphicsScene(XPOS,YPOS,WIDTH,HEIGHT,parent)
{
  mImg_= new MyItem(":/Recursos/Images/RMpixel ico 64x64.png");
  mImg_->setPosition(QPointF(0.0,0.0));
  mImg_->setVelocity(QPointF(1.0,1.0));
  mImg_->setSize(QSizeF(40.0,40.0));
  addItem(mImg_);

}

void MyScene::onUpdate()
{
  int x = mImg_->position().x();
  int y = mImg_->position().y();
  int vx= mImg_->velocity().x();
  int vy= mImg_->velocity().y();

  x=x+vx;
  y=y+vy;

  vy=vy+0.5;

 mImg_->setPosition(QPointF(x,y));
 mImg_->setVelocity(QPointF(vx,vy));

  update();

}
