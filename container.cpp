#include "container.h"

Container::Container(QWidget *parent) :
    QGraphicsScene(parent)
{
    this->window = parent;
}

void Container::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QString text = QInputDialog::getText(this->window, "Chris Graph Plotter", "Nombre del vertice");
    if (!text.isEmpty())
    {
        Vertex* vertex = new Vertex(text.toStdString());
        Point* point = new Point(event->scenePos(), vertex);
        this->graph.addVertex(vertex);
        this->points.push_back(point);
        this->addItem(point);
    }
}

Point* Container::findPoint(string name)
{
    for (int i = 0; i < points.size(); ++i) {
       if(points[i]->getVertex()->getName() == name)
           return points[i];
    }
}

void Container::drawEdge(string firstPoint, string secondPoint, QString weight)
{
    QPointF source, destination, textPosition;

    Point* pointA, *pointB;

    pointA = findPoint(firstPoint);
    pointB = findPoint(secondPoint);

    source = pointA->getPosition();
    destination = pointB->getPosition();

    if(destination.x() > source.x())
    {
        source = QPointF(source.x() + 50, source.y());
        textPosition = QPointF(destination.x() + source.x(), (destination.y() + source.y()) / 2);
    }
    else {

        textPosition = QPointF((source.x() + destination.x()) / 2, destination.y() + source.y());
    }


    if(source.y() > destination.y())
    {

    }

    source = QPointF(source.x(), source.y() + 23);
    destination = QPointF(destination.x() - 5, destination.y() + 23);

    this->addLine(source.x(), source.y(), destination.x(), destination.y(), QPen(Qt::black, 5));

    QGraphicsTextItem * text = this->addText(weight);
    QGraphicsEllipseItem* circle = this->addEllipse(QRectF(10, 10, 10, 10),  QPen(), QBrush(Qt::blue));
    circle->setPos(destination);
    text->setPos(textPosition);

    //this->addItem(new Line(source, destination));
}
