#ifndef NODE_H
#define NODE_H

#include <cstddef>

template <typename T>
class Node {
  public:
  Node(T value)
      : value(value)
      , next(nullptr)
      , previous(nullptr)
  {
  }

  ~Node()
  {
      delete next;
      delete previous;
  }

  Node*& getNext()
  {
    return this->next;
  }

  Node*& getPrevious()
  {
    return this->previous;
  }

  T getValue()
  {
    return this->value;
  }

  void setNext(Node* node)
  {
    this->next = node;
  }

  void setPrevious(Node* node)
  {
    this->previous = node;
  }

  void setValue(T value)
  {
    this->value = value;
  }

  private:
  T value;
  Node* next;
  Node* previous;
};

#endif // NODE_H
