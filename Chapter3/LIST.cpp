#include "LIST.h"

List::List(){
    Element=NULL;
    Next=NULL;
}

/*Return true if L is empty*/
bool IsEmpty(PList L){
    return L->Next==NULL;
}

/*Return true if P is the last Position in List L*/
/*Parameter L is unused in this implementation*/
bool IsLast(Position P,PList L){
    return P->Next==NULL;
}

/*Return Position of X in L, NULL if not found*/
Position Find(ElementType X, PList L){
    Position P;

    P=L->Next;
    while(P!=NULL && P->Element!=X){
        P=P->Next;
    }
    return P;
}

/*If X is not found, then Next field of returned*/
/*Position is NULL*/
/*Assume a header*/
Position FindPrevious(ElementType X, PList L){
    Position P=L;

    while(P->Next!=NULL && P->Next->Element!=X)
        P=P->Next;

    return P;
}

/*Delete first occurrence of X from a list*/
/*Assume use of a header node*/
void Delete(ElementType X,PList L){
    Position P,TmpCell;

    P=FindPrevious(X,L);

    if(!IsLast(P,L)){
        TmpCell=P->Next;
	P->Next=TmpCell->Next;
	delete TmpCell;
    }
}

/*Insert (after legal position P)*/
/*Header implementation assumed*/
/*Parameter L is unused in this implementation*/
void Insert(ElementType X,PList L,Position P){
    Position TmpCell;

    TmpCell=new List;
    if(TmpCell==NULL)
        FatalError("Out of Space!");

    TmpCell->Element=X;
    TmpCell->Next=P->Next;
    P->Next=TmpCell;
}

void DeleteList(PList L){
    Position P,Tmp;

    P=L->Next;
    L->Next=NULL;
    while(P!=NULL){
        Tmp=P->Next;
        delete P;
	P=Tmp;
    }
}

void List::PrintList(PList L){
    Position P=L->Next;
    while(P!=NULL){
        PrintElement(P);
	P=P->Next;
    }
}

void List::PrintElement(Position P){
    printf("%d",P->Element);
}

void List::PrintLots(PList L,PList P){
    Position N=P->Next,M=L->Next;
    int i=1;
    while(N!=NULL && M!=NULL){
        if(N->Element==i){
       	  PrintElement(M);
	  N=N->Next;
        }
        i++;
        M=M->Next;
    }
}

void List::Swap(Position N,Position M){
  Position T=Advance(N);
  T->Next=M;
  N->Next=M->Next;
  M->Next=N;
}

PList List::And(PList N,PList M){
  PList T=new List;
  Position J=N->Next,K=M->Next,TN=T;
  while(J!=NULL || K!=NULL){
    if(J!=NULL && K!=NULL){
      if(J->Element>K->Element){
	TN->Next=K;
	TN=K;
	K=K->Next;
      }
      else if(J->Element<K->Element){
	TN->Next=J;
	TN=J;
	J=J->Next;
      }
      else{
	TN->Next=K;
	TN=K;
	J=J->Next;
	K=K->Next;
      }
    }
    else if(J==NULL){
      TN->Next=K;
      TN=K;
      K=K->Next;
    }
    else {
      TN->Next=J;
      TN=J;
      J=J->Next;
    }
  }
  return T;
}

PList List::Or(PList N,PList M){
  PList T=new List;
  Position J=N->Next,K=M->Next,TN=T;
  while(J!=NULL && K!=NULL){
    if(J->Element!=K->Element){
      if(J->Element>K->Element){
	K=K->Next;
      }
      else J=J->Next;
    }
    else {
      TN->Next=J;
      TN=J;
      J=J->Next;
      K=K->Next;
    }
  }
  return T;
}
