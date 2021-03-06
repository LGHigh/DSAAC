#ifndef _AVLTREE_H
#define _AVLTREE_H

class Tree;
typedef class Tree* Position;
typedef class Tree* AvlTree;

class Tree{
 public:
  AvlTree MakeEmpty();
  Position Find(ElementType X);
  Position FindMin();
  Position FindMax();
  AvlTree Insert(ElementType X);
  AvlTree Delete(ElementType X);
  Position SingleRotateWithLeft();
  Position SingleRotateWithRight();
  Position DoubleRotateWithLeft();
  Position DoubleRotateWithRight();
  AvlTree Delete(ElementType X);
  ElementType Retrieve(Position P);
  int getHeight();
 private:
  ElementType Element;
  AvlTree Left;
  AvlTree Right;
  int Height;
}

#endif /*_AVLTREE_H*/
