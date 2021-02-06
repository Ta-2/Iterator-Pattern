#include <stdio.h>
#include <string>
#include <vector>
#include "Iterator.hpp"
using namespace std;

class Item;
class Bag;
class BagIterator;

class Item{
public:
  void SetName (string name){ name_ = name; }
  string GetName (void){ return name_; }
private:
  string name_;
};

class Bag : public AggregateInterface <Item> {
public:
  Bag(int size){
    Items_.resize(size);
    nItems = 0;
  }
  Item GetItemAt (int index){ return Items_[index]; }
  IteratorInterface <Item> *Iterator(void);
  void AppendItem (Item item){
    Items_[nItems] = item;
    nItems++;
  }
  int GetItems (void){ return nItems; }
private:
  vector<Item> Items_;
  int nItems;
};

class BagIterator: public IteratorInterface<Item>{
public:
  BagIterator (Bag bag): index_(0), Bag_(bag){
  }
  bool IsLast(void){
    return index_<(Bag_.GetItems()) ? true: false;
  }
  Item Next(void){
    Item item = Bag_.GetItemAt(index_);
    index_++;
    return item;
  }

private:
  Bag Bag_;
  int index_;
};

IteratorInterface <Item> *Bag::Iterator(void){
  return new BagIterator(*this);
}

int main(){


  return 0;
}
