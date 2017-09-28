#ifndef _LIST_H
#define _LIST_H

class List;
typedef class List* PList;
typedef class List* Position;

typedef int ElementType;

class List{
 Public:
  List();
  PList MakeEmpty(PList L);
  bool IsEmpty(PList L);
  bool IsLast(Position P,PList L);
  Position Find(ElementType X,PList L);
  void Delete(ElementType X,PList L);
  Position FindPrivious(ElementType X,PList L);
  void Insert(ElementType X,PList L,Position P);
  void DeleteList(PList L);
  Position Header(PList L);
  Position First(PList L);
  Position Advance(Position P);
  ElementType Retrieve(Position P);
  void PrintList(PList L);
  void PrintElement(Position P);
  void PrintLots(PList L,PList P);
  void Swap(Position N,Position M);
  PList And(PList N,PList M);
  PList Or(PList N,PList M);
 private:
  ElementType Element;
  Position Next;
};

#endif /*_LIST_H*/
