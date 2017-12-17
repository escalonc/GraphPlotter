#include "container.h"
#include <QDebug>
#include "arrow.h"

Container::Container(QWidget *parent) :
    parent(parent),
    QGraphicsScene(parent)
{
}

Container::Container(Graph graph, vector<Point*> points, QWidget *parent) :
    graph(graph),
    points(points),
    parent(parent),
    QGraphicsScene(parent)
{
}

void Container::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QString text = QInputDialog::getText(this->parent, "Chris Graph Plotter", "Nombre del vértice");
    if (!text.isEmpty())
    {
        Vertex* vertex = new Vertex(text.toStdString());
        Point* point = new Point(event->scenePos(), vertex);
        this->graph.addVertex(vertex);
        this->points.push_back(point);
        this->addItem(point);
    }
}

Point*& Container::findPoint(string name)
{
    for (unsigned int i = 0; i < points.size(); ++i) {
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

    source = pointA->pos();
    destination = pointB->pos();

    this->addItem(new Arrow(pointA, pointB, weight));
}
