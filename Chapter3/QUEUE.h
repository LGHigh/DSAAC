#ifndef _Queue_h
#define _Queue_h

struct QueueRecord;
typedef struct QueueRecord* Queue;

bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(int MaxElements);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X,Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif

/*Place in implementation file*/
/*Queue implementation is a dynamically allocated array*/
#define MinQueueSize(S)

struct QueueRecord{
  int Capacity;
  int Front;
  int Rear;
  int Size;
  ElementType *Array;
}
