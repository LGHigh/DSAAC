#include "STACK.h"

bool Stack::IsEmpty(PStack S){
    return S->Next==NULL;
}

Stack::Stack(){
   Element=NULL;
   Next=NULL;
}

void Stack::MakeEmpty(PStack S){
  if(S==NULL)
      Error("Must use constructor first");
  else while(!IsEmpty(S))
      Pop(S);
}

void Stack::Push(ElementType X,PStack S){
    PStack TmpCell;

    TmpCell=new Stack;
    if(TmpCell==NULL)
        FatalError("Out of Space");
    else {
        TmpCell->Element=X;
        TmpCell->Next=S->Next;
	S->Next=TmpCell;
    }
}

ElementType Stack::Top(PStack S){
    if(!IsEmpty(S))
        return S->Next->Element;
    Error("Empty Stack");
    return -1;
}

void Stack::Pop(PStack S){
    PStack FirstCell;

    if(IsEmpty(S))
        Error("Empty Stack");
    else {
        FirstCell=S->Next;
        S->Next=FirstCell;
        delete FirstCell;
    }
}

