#ifndef _BINARYTREE_H
#define _BINARYTREE_H

class Tree;
typedef class Tree* Position;
typedef class Tree* SearchTree;;

class Tree{
 public:
  SearchTree MakeEmpty();
  Position Find(ElementType X);
  Position FindMin();
  Position FindMax();
  SearchTree Insert(ElementType X,SearchTree T);
  SearchTree Delete(ElementType X,SearchTree T);
  ElementType Retrieve(Position P);
 Private:
  ElemenetType Element;
  PTree Left;
  PTree Right;
}

#endif /*_BINARYTREE_H*/
