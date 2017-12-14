#include "vertex.h"

Vertex::Vertex(string name)
{
    this->name = name;
}

string Vertex::getName() const
{
    return this->name;
}

void Vertex::setName(string name)
{
    this->name = name;
}

List<Edge*> Vertex::getEdges()
{
    return this->edges;
}

Edge*& Vertex::getEdge(Vertex *destination)
{
    int position = this->edges.find(destination);

    if (position == -1) {
        return nullptr;
    }

    return this->edges.get(position);
}

void Vertex::setEdges(List<Edge *>* edges)
{
    this->edges = *edges;
}
