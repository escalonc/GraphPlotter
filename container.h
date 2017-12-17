#ifndef CONTAINER_H
#define CONTAINER_H

#include <QInputDialog>
#include <QPainter>
#include <QGraphicsItem>
#include "line.h"
#include "graph.h"
#include "point.h"
#include <vector>

using namespace std;

class Container : public QGraphicsScene
{
private:
    QWidget *parent;
    Graph graph;
    Point*& findPoint(string name);

protected:
    vector<Point*> points;

public:
    explicit Container(QWidget *parent = 0);
    Container(Graph graph , vector<Point*> points, QWidget *parent = 0);
    void drawEdge(string firstPoint, string secondPoint, int weight);

public slots:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
};

#endif
