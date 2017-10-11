#include "BinHash.h"

HeapClass::HeapClass(int MaxElements){
    if(MaxElements<MinPQSize)
        Error("Priority queue size is too small");

    Elemenets=new ElementType[MaxElements+1];
    if(Elements==NULL)
        FatalError("Out of Space");

    Capacity=MaxElements;
    Size=0;
    Elements[0]=MinData;
}

/*H->Element[0] is a sentinel*/

void HeapClass::Insert(ElementType X){
    int i;
    if(this->IsFull()){
        Error("Priority queue is full");
        return ;
    }

    for(i=++this->Size;this->Elements[i/2]>X;i/=2)
        this->Elements[i]=this->Elements[i/2];
    this->Elements[i]=X;
}

ElementType HeapClass::DeleteMin(){
    int i,Child;
    ElementType MinElement,LastElement;

    if(this->IsEmpty()){
        Error("Priority queue is empty");
        return this->Elements[0];
    }

    MinElement=this->Elements[1];
    LastElement=this->Elements[this->Size--];

    for(i=1;i*2<=this->Size;i=Child){
        Child=i*2;
        if(Child!=this->Size && this->Elements[Child+1]<this->Elements[Child])
            Child++;

        if(LastElement>this->Elements[Child])
            this->Elements[i]=this->Elements[Child];
        else break;
    }

    this->Elements[i]=LastElemet;

    return MinElement;
}