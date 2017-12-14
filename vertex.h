#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include "list.h"

using namespace std;

class Edge;

class Vertex {
public:
    Vertex(string name);
    string getName() const;
    void setName(string name);
    List<Edge*> getEdges();
    Edge*& getEdge(string destinationName);
    Edge*& getEdge(Vertex* destination);
    void addEdge(string sourceName, string destinationName);
    void addEdge(Edge*);
    void addEdge(Vertex* source, Vertex* destination);

    void setEdges(List<Edge*>* edges);

    inline bool operator==(const Vertex &value) const
    {
         return name == value.getName();
    }

    //virtual ~Vertex();

private:
    string name;
    List<Edge*> edges;
};

#endif
