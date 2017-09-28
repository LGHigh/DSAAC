#include "BinaryTree.cpp"

SearchTree Tree::MakeEmpty(){
  if(this!=NULL){
    this->Left->MakeEmpty();
    this->Right->MakeEmpty();
    free(T);
  }
  return NULL;
}

Position Tree::Find(ElementType X){
  if(this==NULL)return NULL;
  if(X<this->Element)
    return this->Left->Find(X);
  else if(X>this->Element)
    return this->Right->Find(X);
  else
    return this;
}

Position Tree::FindMin(){
  if(this==NULL)
    return NULL;
  else if(this->Left==NULL)
    return this;
  else this->Left->FindMin();
}

Position Tree::FindMax(){
  if(this!=NULL)
    while(this->Right!=NULL)
      this=this->Right;
  return this;
}

SearchTree Tree::Insert(ElementType X){
  if(this==NULL){
    this=new Tree;
    if(this==NULL)
      FatalError("Out of Space");
    else{
      this->Element=X
	this->Left=this->Right=NULL;
    }
  }

  else if(X<this->Element)
    this->Left=this->Left->Insert(X);
  else if(X>this->Element)
    this->Right=this->Right->Insert(X);
  return T;
}

SearchTree Tree::Delete(ElementType X){
  Position TmpCell;
  if(this==NULL)
    Error("Element not Found");
  else if(X<this->Element)
    this->Left=this->Left->Delete(X);
  else if(X>this->Element)
    this->Right=this->Right->Delete(X);
  else if(this->Left && this->Right){
    TmpCell=this->Right->FindMin();
    this->Element=TmpCell->Element;
    this->Right=this->Right->Delete(T->Element);
  }
  else{
    TmpCell=this;
    if(this->Left==NULL)
      this=this->Right;
    else if(this->Right==NULL)
      this=this->Left;
    delete(TmpCell);
  }
}
