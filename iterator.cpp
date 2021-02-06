#include "Iterator.hpp"

template <class Elem>
class IteratorInterface{
public:
  virtual IsLast(void) = 0;
  virtual Elem Next(void) = 0;
};

template <class Elem>
class AggregateInterface{
public:
  virtual IteratorInterface<Elem> *Iterator(void) = 0;
};
