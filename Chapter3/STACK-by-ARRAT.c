#include "STACK-by_ARRAY.h"

Stack CreateStack(int MaxElements){
  Stack S;

  if(MaxElements<MinStackSize)
    Error("Stack size is too small");

  S=malloc(sizeof(struct StackRecord));
  if(S==NULL)
    FatalError("Out of Space");

  S->Capacity=MaxElements;
  MakeEmpty(S);

  return S;
}

void DisposeStack(Stack S){
  if(S!=NULL){
    free(S->Array);
    free(S);
  }
}

