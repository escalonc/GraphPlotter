#ifndef CONTAINER_H
#define CONTAINER_H

#include <QInputDialog>
#include <QPainter>
#include <QGraphicsItem>
#include "listpoint.h"
#include "line.h"
#include "graph.h"
#include "point.h"
#include <vector>

using namespace std;

class Container : public QGraphicsScene
{
private:
    QWidget* window;
    Graph graph;
    Point* findPoint(string name);

protected:
    //ListPoint points;
    vector<Point*> points;

public:
    explicit Container(QWidget *parent = 0);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void drawEdge(string firstPoint, string secondPoint, QString weight);

signals:

public slots:
};

#endif // CONTAINER_H
