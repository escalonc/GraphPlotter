#include "graph.h"
#include <climits>

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

int Graph::getWeigth(Vertex* startVertex, Vertex* endVertext)
{
    int startVertexPosition = vertices.find(startVertex);
    Vertex* currentVertex = vertices.get(startVertexPosition);

    Edge* edge = currentVertex->getEdge(endVertext);

    if (edge != nullptr) {
        return edge->getWeight();
    }
    else {
        return 9999999;
    }

}

Edge*& Graph::getEdge(Vertex* startVertex, Vertex* endVertext)
{
    int startVertexPosition = vertices.find(startVertex);
    Vertex* currentVertex = vertices.get(startVertexPosition);

    Edge* edge = currentVertex->getEdge(endVertext);

    return edge;

}

Graph* Graph::clone()
{
    Graph* graph = new Graph();
    List<Vertex*>* clonedVertices = this->vertices.clone();

    for (int i = 0; i < clonedVertices->getSize(); ++i) {
        clonedVertices->get(i)->setEdges(vertices.get(i)->getEdges().clone());
    }

    graph->setAdjacencies(clonedVertices);

    return graph;
}

List<Vertex*>* Graph::getAdjacencies()
{
    return &vertices;
}

void Graph::setAdjacencies(List<Vertex*> *vertices)
{
    this->vertices = *vertices;
}

Graph* Graph::floyd_warshall()
{
    Graph* graph = this->clone();
    List<Vertex*>* vertices = graph->getAdjacencies();

    for (int k = 0; k < vertices->getSize(); ++k) {
        for (int i = 0; k < vertices->getSize(); ++i) {
            for (int j = 0; k < vertices->getSize(); ++j) {
                int weigthPath = this->getWeigth(vertices->get(i), vertices->get(k)) + getWeigth(vertices->get(k), vertices->get(j));
                if (getWeigth(vertices->get(i), vertices->get(j)) > weigthPath) {
                    this->getEdge(vertices->get(k), vertices->get(i))->setWeigth(weigthPath);
                }
            }
        }
    }
}
