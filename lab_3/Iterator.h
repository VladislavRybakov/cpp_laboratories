#pragma once
#include "List.h"

template<typename abstracted>
class List;

template<typename abstracted>
class Iterator
{
  Node<abstracted>* container;
public:
  Iterator(Node<abstracted>* ptr):  container(ptr) {}

  friend class List<abstracted>;

  bool operator==(const Iterator a) const {
    return this->container == a.container;
  }
  bool operator!=(const Iterator a) const {
    return this->container != a.container;
  }
  abstracted& operator*() {
    return container->data;
  }
  Iterator& operator++()
  {
    if (container != NULL) container = container->next;
    return *this;
  }
  Iterator operator++(int)
  {
    Iterator* prev = this;
    if(container != NULL) container = container->next;
    return *prev;
  }
  Iterator& operator=(const Iterator& a) {
    container = a.container;
    return *this;
  }
};
