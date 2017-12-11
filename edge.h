#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge
{
public:
    Edge (Vertex* source, Vertex* destination, int weight);
    Vertex*& getSource();
    Vertex*& getDestination();
    int getWeight();
    virtual ~Edge ();

private:
    Vertex * source, * destination;
    int weight;
};

#endif
