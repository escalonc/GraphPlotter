#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"
#include "list.h"

class Graph
{
public:
    Graph ();
    void addVertex(string name);
    void addVertex(Vertex* vertex);
    void setAdjacencies(List<Vertex*>* vertices);
    int getWeigth(Vertex* startVertex, Vertex* endVertext);
    Edge*& getEdge(Vertex* startVertex, Vertex* endVertext);

    List<Vertex*>* getAdjacencies();
    Graph* clone();
    Graph* floyd_warshall();

private:
    List<Vertex*> vertices;

};

#endif
