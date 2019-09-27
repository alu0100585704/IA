#pragma once

#include <QGraphicsItem>
#include <QPointF>
#include <QSizeF>

class MyItem : public QGraphicsItem
{
public:
    MyItem(const QString &filename,QGraphicsItem * parent=nullptr);
    QRectF	boundingRect() const;
    void	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) ;
    void setPosition(const QPointF &pos);
    void setVelocity(const QPointF &vel);
    void setSize(const QSizeF &size);
    QString filename() const;
    QPointF position() const;
    QPointF velocity() const;
    QSizeF size() const;
private:
    QPointF mPos_; //posx , posy
    QPointF mVel_; //velocidad x y velocidad y
    QSizeF mSize_; //ancho y alto
    QString mFilename_; //nombre archivo imagen item
};

