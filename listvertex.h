#ifndef LISTVERTEX_H
#define LISTVERTEX_H

#include "list.h"
#include "vertex.h"

class ListVertex : public List<Vertex*> {
  public:
  ListVertex()
  {

  }

  using List<Vertex*>::equals;
  bool equals(Vertex* firstValue, Vertex* secondValue)
  {
    return firstValue->getName() == secondValue->getName();
  }
};

#endif // LISTVERTEX_H
