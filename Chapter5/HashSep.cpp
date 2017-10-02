#include "HashSep.h"

HashTbl::HashTbl(int TableSize){
  TableSize=NextPrime(TableSize);

  TheLists=new List[TableSize];
  if(TheLists==NULL)
    FatalError("Out of Space");

  for(int i=0;i<TableSize;i++){
    TheLists[i]=new ListNode;
    if(TheLists[i]==NULL)
      FatalError("Out of Space");
    else
      TheListsp[i]->Next=NULL;
  }
}

Position HashTbl::Find(ElementType Key){
  Position P;
  List L;

  L=this->TheLists[Hash(Key,this->TableSize)];
  P=L->Next;
  while(P!=NULL && P->Element!=Key)
    P=P->Next;
  return P;
}

void HashTbl::Insert(ElementType Key){
  Position Pos,NewCell;
  List L;

  Pos=Find(Key,H);
  if(Pos==NULL){
    NewCell=new HashTbl;
    if(NewCell==NULL)
      FatalError("Out of Space");
    else{
      L=this->TheLists[Hash(Key,this->TableSize)];
      NewCell->Next=L->Next;
      NewCell->Element=Key;
      L->Next=NewCell;
    }
  }
}
