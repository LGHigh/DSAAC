#ifndef _HashSep_H
#define _HashSep_H

struct ListNode;
typedef struct ListNode* Position;
class HashTbl;
typedef class HashTbl* HashTable;

class HashTbl{
 public:
  HashTbl(int TableSize);
  void DestoryTable();
  Position Find(ElementType Key);
  void Insert(ElementType Key);
  ElementType Retrieve(Position P);
 private:
  int TableSize;
  List* TheLists;
};

/*List* TheList will be an array of lists, allocated later*/
/*The list use headers (for simplicity)*/
/*though this wastes space*/
struct ListNode{
  ElementType Element;
  Position Next;
}

#endif /*_HashSep_H*/
