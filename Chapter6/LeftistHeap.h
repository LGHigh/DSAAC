#ifndef _LeftHeap_H
#define H->Insert(X) (H=H->Insert1(X))
#define H->DeleteMin() (H=H->DeleteMin1())

class TreeNode;
typedef class TreeNode* PriorityQueue;

/*Minimal set of priority queue operations*/
/*note that nodes will be shared among several*/
/*leftist heaps after a merge; the user must make sure to*/
/* not use the old leftist heaps*/

class TreeNode{
friend PriorityQueue operator + (PriorityQueue H1, PriorityQueue H2);
public:
    TreeNode();
    ElementType FindMin();
    int IsEmpty();
    PriorityQueue Insert1(ElementType X);
    PriorityQueue DeleteMin1(PriorityQueue H);
private:
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;        //null path length

};

#endif /*_LeftHeap_H*/