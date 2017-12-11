#include "vertex.h"

Vertex::Vertex(string name)
{
    this->name = name;
}

string Vertex::getName()
{
    return this->name;
}

void Vertex::setName(string name)
{
    this->name = name;
}

ListEdge Vertex::getEdges()
{
    return this->edges;
}

Edge*& Vertex::getEdge(string destinationName)
{
    int position = edges.find()
}
