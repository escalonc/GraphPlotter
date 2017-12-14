#include "container.h"
#include <QDebug>

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
        qDebug() << event->scenePos();
        Point* point = new Point(event->scenePos(), vertex);
        this->graph.addVertex(vertex);
        this->points.push_back(point);
        this->addItem(point);
    }
}

Point*& Container::findPoint(string name)
{
    for (int i = 0; i < points.size(); ++i) {
       if(points[i]->getVertex()->getName() == name)
           return points[i];
    }
}

void Container::drawEdge(string firstPoint, string secondPoint, int weight)
{
    QPointF source, destination;
    Point* pointA, *pointB;

    pointA = findPoint(firstPoint);
    pointB = findPoint(secondPoint);

    source = pointA->getPosition();
    destination = pointB->getPosition();

//    source = QPointF(source.x() + 25, source.y() + 25);
//    destination = QPointF(destination.x() + 25, destination.y() + 25);

    this->addItem(new Line(source, destination, new Edge(pointA->getVertex(), pointB->getVertex(), weight)));
}
