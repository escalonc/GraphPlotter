#include "point.h"

Point::Point(QPointF position, Vertex* vertex)
    : position(position),
      vertex(vertex)
{
}

Point::~Point()
{
    delete this->vertex;
}

QRectF Point::boundingRect() const
{
    return QRectF(this->position.x(), this->position.y(), 50, 50);
}

Vertex*& Point::getVertex()
{
    return this->vertex;
}

QPointF Point::getPosition()
{
    return this->position;
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen = painter->pen();
    pen.setCosmetic(true);
    pen.setWidth(2);
    pen.setColor(QColor(Qt::green));
    painter->setPen(pen);
    QBrush brush = painter->brush();
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawEllipse(this->boundingRect());

    QPoint textLocation(position.x() + 20, position.y() + 20);
                painter->drawText(textLocation, QString::fromStdString(vertex->getName()));
}
