#include "myitem.h"
#include <QPainter>
MyItem::MyItem(const QString &filename, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    mFilename_=filename;
}

QRectF MyItem::boundingRect() const
{
    return QRectF(mPos_.x(),mPos_.y(),mSize_.width(),mSize_.height());
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawPixmap(mPos_.x(),mPos_.y(),mSize_.width(),mSize_.height(),QPixmap(mFilename_));
}

QString MyItem::filename() const
{
return mFilename_;
}
void MyItem::setPosition(const QPointF &pos)
{
    mPos_=pos;
}

void MyItem::setVelocity(const QPointF &vel)
{
    mVel_=vel;
}

void MyItem::setSize(const QSizeF &size)
{
     mSize_=size;
}

QPointF MyItem::position() const
{
return mPos_;
}

QPointF MyItem::velocity() const
{
return mVel_;
}

QSizeF MyItem::size() const
{
return mSize_;
}
