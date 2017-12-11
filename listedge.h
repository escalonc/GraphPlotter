#ifndef LISTEDGE_H
#define LISTEDGE_H

#include <string>
#include "vertex.h"
#include "edge.h"
#include "list.h"

using namespace std;

class ListEdge : public List<Edge*>
{
public:
    ListEdge() {}

    using List<Edge*>::equals;
    bool equals(Edge* firstValue, Edge* secondValue)
    {
      return firstValue->getWeight() == secondValue->getWeight();
    }

    int findEdgeByVertex(string vertexName)
    {
        Node<Edge*>* currentNode = this->begin;

        for (int i = 0; i < this->elementsQuantity; i++) {
            if (currentNode->getValue()->getDestination()->getName() == vertexName) {
                return i;
            }

            currentNode = currentNode->getNext();
        }

        return -1;
    }
};

#endif // LISTEDGE_H
