#include "graph.h"

 Graph::Graph()
{
}

void Graph::addVertex(string name)
{
    this->vertices.add(new Vertex(name));
}

void Graph::addVertex(Vertex *vertex)
{
    this->vertices.add(vertex);
}
