#include "BinHeap.h"
HeapStruct::HeapStruct(int MaxElements){
    if(MaxElements<MinPQSize)
        Error("Priority queue size is too small");
    
    Elements=malloc((MaxElements+1)*sizeof(ElementType));
    if(Elements==NULL)
        FatalError("Out of Space");

    Capacity=MaxElements;
    Size=0;
    Elements[0]=MinData;
}

void HeapStruct::Insert(ElementType X){
    int i;
    if(this->IsFull()){
        Error("Priority queue is full");
        return ;
    }

    for(i=++this->Size;H->Elements[i/2]>X;i/=2)
        H->Elements[i]=H->Elements[i/2];
    H->Elements[i]=X;
}