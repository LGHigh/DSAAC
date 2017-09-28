#ifndef _TREE_H
#define _TREE_H

typedef struct Tree* PtrToNode;

struct Tree{
  ElementType Element;
  PtrToNode FirstChild;
  PtrToNode NextSibling;
}

#endif /*_TREE_H*/
