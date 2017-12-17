#include "point.h"

Point::Point(QPointF position, Vertex* vertex, QGraphicsItem *parent)
    : position(position),
      vertex(vertex),
      QGraphicsPolygonItem(parent)
{
    QPainterPath path;

    myPolygon << QPointF(-50, -50) << QPointF(50, -50)
              << QPointF(50, 50) << QPointF(-50, 50)
              << QPointF(-50, -50);

    setPos(position);
    setPolygon(myPolygon);
}

Point::~Point()
{
    delete this->vertex;
}

//QRectF Point::boundingRect() const
//{
//    return QRectF(this->position.x(), this->position.y(), 50, 50);
//}

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
    pen.setWidth(5);
    pen.setColor(QColor(Qt::green));
    painter->setPen(pen);
    QBrush brush = painter->brush();
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawEllipse(this->boundingRect());

    QPointF textLocation = this->boundingRect().center();
                painter->drawText(textLocation.toPoint(), QString::fromStdString(vertex->getName()));
}

