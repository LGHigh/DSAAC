#ifndef _HashWork_H
#define _HashWork_H

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
    
}

#endif /*_HashWork_H*/