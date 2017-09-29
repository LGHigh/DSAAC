#ifndef _LIST_H
#define _LIST_H

class List;
typedef List* Position;
typedef List* PList;

class List{
  List();
  PList Insert(int Pow,double Constant);
  PList Delete(Position P);
  PList Delete(int Pow);
private:
  int Pow;
  double Constant;
  Position Next;
};

#endif /*_LIST_H*/

List::List(){
  Pow=NULL;
  Constant=NULL;
  Next=NULL;
}

PList List::Insert(int Pow,double Constant){
  PList Tmp=this;
  while(Tmp->Next!=NULL && Tmp->Next->Pow>Pow)
    Tmp=Tmp->Next;

  if(Tmp->Next==NULL){
    PList TmpCell=new List;                            //init a new cell
    TmpCell->Pow=Pow;
    TmpCell->Constant=Constant;
    Tmp->Next=TmpCell;
  }

  else if(Tmp->Next->Pow==Pow)
    this->Next->Constant+=Constant;

  else{
    PList TmpCell=new List;                            //init a new cell
    TmpCell->Pow=Pow;
    TmpCell->Constant=Constant;
    Tmp->Next=TmpCell->Next;
    TmpCell->Next=Tmp;
  }

  return this;
}

PList List::Delete()
