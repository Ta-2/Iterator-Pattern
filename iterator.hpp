#ifndef ITR_HPP
#define ITR_HPP

template <class Elem> class IteratorInterface;
template <class Elem> class AggregateInterface;

template <class Elem>
class IteratorInterface{
public:
  virtual bool IsLast(void) = 0;
  virtual Elem Next(void) = 0;
};

template <class Elem>
class AggregateInterface{
public:
  virtual IteratorInterface<Elem> *Iterator(void) = 0;
};

#endif
