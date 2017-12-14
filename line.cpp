#include "line.h"

Line::Line(QPointF source, QPointF destination, Edge* edge)
    : source(source),
      destination(destination),
      edge(edge)
{
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF textPosition;

    if(destination.x() > source.x())
    {
        textPosition = QPointF(destination.x() + source.x(), (destination.y() + source.y()) / 2);
    }
    else {

        textPosition = QPointF((source.x() + destination.x()) / 2, destination.y() + source.y());
    }

    QPen pen(QBrush(Qt::blue), 7);
    painter->setPen(pen);
    painter->drawEllipse(this->boundingRect());


    painter->setPen(QPen(Qt::black, 5));
    painter->drawLine(this->source, this->destination);
    painter->drawText(textPosition, QVariant(this->edge->getWeight()).toString());
}

QRectF Line::boundingRect() const
{
    return QRectF(this->destination.x(), this->destination.y(), 10, 10);
}
