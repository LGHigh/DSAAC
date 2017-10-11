#include "LeftistHeap.h"

PriorityQueue operator + (PriorityQueue H1, PriorityQueue H2){
    if(H1==NULL)
        return H2;
    if(H2==NULL)
        return H1;
    if(H1->Element < H2->Element)
        return Merge1(H1,H2);
    else 
        return Merge1(H2,H1);
}

static PriorityQueue Merge1(PriorityQueue H1,PriorityQueue H2){
    if(H1->left==NULL)
        H1->Left=H2;
    else{
        H1->Right=Merge(H1->Right,H2);
        if(H1->Left->Npl < H1->Right->Npl)
            H1->SwapChild();

            H1->Npl=H1->Right->Npl+1;
    }
    return H1;
}

PriorityQueue TreeNode::Insert1(ElementType X){
    PriorityQueue SingleNode;

    SingleNode=new TreeNode;
    if(SingleNode==NULL)
        FatalError("Out of Space");
    else{
        SingleNode->Element=X;
        SingleNode->Npl=0;
        SingleNode->Left=SingleNode->Right=NULL;
        this=Merge(SingleNode,this);
    }
    return this;
}

PriorityQueue TreeNode::DeleteMin1(){
    PriorityQueue LeftHeap,RightHeap;
    if(this->IsEmpty()){
        Error("Priority queue is empty");
        return H;
    }
    LeftHeap=H->Left;
    RightHeap=H->Right;
    free(H);
    return Merge(LeftHeap,RightHeap);
}