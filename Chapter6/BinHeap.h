#ifndef _BinHeap_H
#define MinPQSize 1
#define MinData 0

class HeapClass;
typedef class HeapClass* PriorityQueue;

class HeapClass {
public:
    HeapClass(int MaxElements);
    void Destory();
    void MakeEmpty();
    void Insert(ElementType X);
    ElementType DeleteMin();
    ElementType FindMin();
    int InEmpty();
    int InFull();
private:
    int Capacity;
    int Size;
    ElementType *Elements;
};

#endif /*_BinHeap_H*/