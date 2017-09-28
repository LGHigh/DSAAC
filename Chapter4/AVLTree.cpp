#include "AVLTree.h"

int Tree::getHeight(){
  if(this==NULL)return -1;
  return this->Height;
}

AvlTree Tree::Insert(ElementType X){
  if(this==NULL){
    this=new Tree;
    if(this==NULL)
      FatalError("Out of Space");
    else{
      this->Element=X;
      this->Height=0;
      this->Left=this->Right=NULL;
    }
  }
  else if(X<this->Element){
    this->Left=this->Left->Insert(X);
    if(this->Left->Height-this->Right->Height==2){
      if(X<this->Left->Element)
	this=this->SingleRotateWithLeft();
      else
	this=this->DoubleRotateWithRight();
    }
  }
  else if(X>this->Element){
    this->Right=this->Right->Insert(X);
    if(this->Right->Height-this->Left->Height==2){
      if(X>this->Right->Element)
	this=this->SingleRotateWithRight();
      else
	this=this->DoubleRotateWithLeft();
    }
  }

  this->Height=max(this->Left->Height,this->Right->Height)+1;
  return this;
}

Position Tree::SingleRotateWithLeft(){
  Position K1;
  
  K1=this->Left;
  this->Left=K1->Right;
  K1->Right=this;

  this->Height=max(this->Left->Height,this->Right->Height)+1;
  K1->Height=max(K1->Left->Height,this->Height)+1;
  return K1;
}

Position Tree::SingleROtateWithRight(){
  Position K1;

  K1=this->Right;
  this->Right=K1->Left;
  K1->Left=this;

  this->Height=max(this->Right->Height,this->Left->Height)+1;
  K1->Height=max(K1->Right->Height,this->Height)+1;
  return K1;
}

Position Tree::DoubleRotateWithLeft(){
  this->Left=this->Left->SingleRotateWithRight();
  return this->SingleRotateWithLeft();
}

Position Tree::DoubleRotateWithRight(){
  this->Right=this->Right->SingleRotateWithLeft();
  return this->SingleRotateWithRight();
}
