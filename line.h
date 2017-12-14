#ifndef LINE_H
#define LINE_H

#include <QtWidgets>
#include "edge.h"

class Line : public QGraphicsItem
{
private:
    QPointF source, destination;

protected:
    bool isDirected = true;
    Edge* edge;

public:
    Line(QPointF source, QPointF destination, Edge* edge);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // LINE_H
