#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"
#include "listvertex.h"

class Graph
{
public:
    Graph ();
    void addVertex(string name);
    void addVertex(Vertex* vertex);

private:
    ListVertex vertices;

};

#endif
