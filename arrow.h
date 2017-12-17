#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

#include "point.h"
#include "edge.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
QT_END_NAMESPACE

class Arrow : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };

    Arrow(Point *startItem, Point *endItem, int weight,
      QGraphicsItem *parent = 0);

    int type() const override { return Type; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) { myColor = color; }
    Point *startItem() const { return myStartItem; }
    Point *endItem() const { return myEndItem; }

    void updatePosition();

protected:
    Edge *edge;
    int weight;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    Point *myStartItem;
    Point *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif
