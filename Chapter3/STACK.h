/*Dedication to public interests, Acquisition of all-round capability, Aspiration for progress with each passing day.*/
/*using List*/
#ifndef _Stack_h
#define _Stack_h

class Stack;
typedef class Stack* PStack;

typedef int ElementType;

class Stack{
 public:
  Stack();
  bool IsEmpty(PStack S);
  void DisposeStack(PStack S);
  void MakeEmpty(PStack S);
  void Push(ElementType X,PStack S);
  ElementType Top(PStack S);
  void Pop(PStack);
 private:
  ElementType Element;
  PStack Next;
};

#endif /*_Stack_h*/
