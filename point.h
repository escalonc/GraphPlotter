#ifndef POINT_H
#define POINT_H

#include <QtWidgets>
#include "vertex.h"

class Point : public QGraphicsPolygonItem
{
public:
    Point(QPointF position, Vertex* vertex, QGraphicsItem *parent = 0);
    ~Point();
    Vertex*& getVertex();
    QPointF getPosition();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPointF position;
    Vertex* vertex;
    //QRectF boundingRect() const;
    QPolygonF myPolygon;

signals:

public slots:
};

#endif // POINT_H
