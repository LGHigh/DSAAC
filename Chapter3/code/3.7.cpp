#include <iostream>
#ifndef _LIST_H
#define _LIST_H

class List;
typedef List* Position;
typedef List* PList;

class List {
public:
  List();
  PList Insert(int Pow, double Constant);
  PList Insert(Position P);
  PList Combine(PList L);
  
  void DeleteList();
  PList Delete(int Pow);
  
  PList Multi(PList L);                      //O(M^2*N^2)
  void Multi(int Pow, double Constant);
  
  int getPow() { return Pow; }
  double getConstant() { return Constant; }
  
  void Print();
private:
  int Pow;
  double Constant;
  Position Next;
};

#endif /*_LIST_H*/

List::List() {
  Pow = NULL;
  Constant = NULL;
  Next = NULL;
}

PList List::Insert(int Pow, double Constant) {
  PList Tmp = this;
  while (Tmp->Next != NULL && Tmp->Next->Pow>Pow)
    Tmp = Tmp->Next;
  
  if (Tmp->Next == NULL) {
    PList TmpCell = new List;                            //init a new cell
    TmpCell->Pow = Pow;
    TmpCell->Constant = Constant;
    Tmp->Next = TmpCell;
  }
  
  else if (Tmp->Next->Pow == Pow)
    Tmp->Next->Constant += Constant;
  
  else {
    Position TmpCell = new List;                            
    TmpCell->Pow = Pow;
    TmpCell->Constant = Constant;
    TmpCell->Next = Tmp->Next;
    Tmp->Next=TmpCell;
  }
  
  return this;
}

PList List::Insert(Position P) {
  return this->Insert(P->getPow(), P->getConstant());
}

PList List::Combine(PList L) {
  Position Tmp = L->Next;
  while (Tmp != NULL) {
    this->Insert(Tmp);
  }
  return this;
}

void List::DeleteList() {
  Position Tmp = this->Next;
  while (Tmp != NULL) {
    Position P = Tmp->Next;
    delete Tmp;
    Tmp = P;
  }
  delete this;
}

PList List::Delete(int Pow) {
  PList TmpCell = this;
  while (TmpCell->Next != NULL && TmpCell->Next->Pow != Pow)
    TmpCell = TmpCell->Next;
  
  if (TmpCell->Next != NULL) {
    PList Tmp = TmpCell->Next;
    TmpCell->Next = Tmp->Next;
    delete Tmp;
  }
  
  return this;
}

void List::Multi(int Pow, double Constant) {
  Position Tmp = this->Next;
  while (Tmp != NULL) {
    Tmp->Pow += Pow;
    Tmp->Constant *= Constant;
  }
}

PList List::Multi(PList L) {
  PList Tmp = new List;
  Position M = this->Next;
  while (M != NULL) {
    Position N = L->Next;
    while (N != NULL) {
      Tmp->Insert(M->Pow + N->Pow, M->Constant*N->Constant);
      N = N->Next;
    }
    M = M->Next;
  }
  return Tmp;
}

void List::Print() {
  Position Tmp = this->Next;
  while (Tmp != NULL) {
    std::cout << Tmp->Pow << " " << Tmp->Constant << std::endl;
    Tmp = Tmp->Next;
  }
}
