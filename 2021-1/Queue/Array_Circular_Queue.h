/*
Array based Circular Queue
	Written by: wowo0709
	Date: 2021-03-26
*/
#ifndef __ARRAY_CIRCULAR_QUEUE__
#define __ARRAY_CIRCULAR_QUEUE__
#include <stdio.h>

typedef int Element;
// Head node (size-1 elements can be stored)
typedef struct _cQueue {
	Element* queue;
	int size;
	int count;
	int front, rear;
}CQueue;

CQueue* CreateQueue(int size);         // 원형 큐 생성
void Enqueue(CQueue* pq,Element item); // 큐에 원소 삽입
Element Dequeue(CQueue* pq);           // 큐에서 원소 삭제 및 반환
Element QPeek(CQueue* pq);             // 큐에서 원소 반환
int QIsFull(CQueue* pq);               // 큐에 꽉 찼는지 검사
int QIsEmpty(CQueue* pq);              // 큐가 텅 비었는지 검사
void DestroyQueue(CQueue* pq);         // 원형 큐 삭제
int CountQueueItem(CQueue* pq);        // 큐의 원소의 개수
void PrintQueueItems(CQueue* pq);      // 큐의 모든 원소 출력
void ClearQueue(CQueue* pq);           // 큐의 모든 원소 삭제



#endif
