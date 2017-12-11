#ifndef LINE_H
#define LINE_H

#include <QtWidgets>

class Line : public QGraphicsItem
{
private:
    QPointF source, destination;

protected:
    bool isDirected = true;

public:
    Line(QPointF source, QPointF destination);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // LINE_H
