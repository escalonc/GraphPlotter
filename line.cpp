#include "line.h"

Line::Line(QPointF source, QPointF destination)
{
    this->source = source;
    this->destination = destination;
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    if (this->isDirected) {
//        painter->setBrush(QBrush(Qt::blue));
//        painter->drawEllipse(QRectF(this->destination.x(), this->destination.y(), 5, 5));
//        painter->setBrush(QBrush());
//    }

    QPen pen(Qt::black, 5);
    painter->setPen(pen);
    painter->drawLine(this->source, this->destination);
}

QRectF Line::boundingRect() const
{
    return QRectF();
}
