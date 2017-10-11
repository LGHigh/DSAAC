#ifndef _BinHeap_H
#define MinPQSize 2
class HeapStruct;
typedef class HeapStruct* PriorityQueue;

class HeapStruct{
public:
    HeapStruct(int MaxElements);
    void Destory();
    void MakeEmpty();
    void Insert(ElementType X);
    ElementType DeleteMin();
    ElementType FindMin();
    int IsEmpty();
    int IsFull();
private:
    int Capacity;
    int Size;
    ElementType* Elements;
};

#endif /*_BinHeap_H*/