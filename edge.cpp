#include "edge.h"

Edge::Edge(Vertex* source, Vertex* destination, int weight)
{
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

Edge::~Edge()
{
    delete source;
    delete destination;
}

Vertex*& Edge::getSource()
{
    return this->source;
}

Vertex*& Edge::getDestination()
{
    return this->destination;
}

void Edge::setWeigth(int value)
{
    this->weight = value;
}

int Edge::getWeight()
{
    return this->weight;
}
