#ifndef POINT_H
#define POINT_H

#include <QtWidgets>
#include "vertex.h"

class Point : public QGraphicsItem
{
public:
    Point(QPointF position, Vertex* vertex);
    ~Point();
    Vertex*& getVertex();
    QPointF getPosition();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPointF position;
    Vertex* vertex;
    QRectF boundingRect() const;

signals:

public slots:
};

#endif // POINT_H
