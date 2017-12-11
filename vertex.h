#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include "listedge.h"

using namespace std;

class Edge;

class Vertex {
public:
    Vertex(string name);
    string getName();
    void setName(string name);
    ListEdge getEdges();
    Edge*& getEdge(string destinationName);
    Edge*& getEdge(Vertex* destination);
    void addEdge(string sourceName, string destinationName);
    void addEdge(Edge*);
    void addEdge(Vertex* source, Vertex* destination);
    //virtual ~Vertex();

private:
    string name;
    ListEdge edges;
};

#endif
