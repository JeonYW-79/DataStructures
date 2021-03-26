/*
LinkedList based Queue
	Written by: wowo0709
	Date: 2021-03-26
*/
#ifndef __LINKED_LIST_QUEUE__
#define __LINKED_LIST_QUEUE__
#include <stdio.h>

// node
typedef struct _node {
	void* item;
	struct _node* next;
}Node;
// head node
typedef struct _lQueue {
	int count;
	Node* front, * rear;
}LQueue;

LQueue* CreateQueue();                // 원형 큐 생성
void Enqueue(LQueue* pq, void* item); // 큐에 원소 삽입
void* Dequeue(LQueue* pq);            // 큐에서 원소 삭제 및 반환
void* QPeek(LQueue* pq);              // 큐에서 원소 반환
int QIsEmpty(LQueue* pq);             // 큐가 텅 비었는지 검사
void DestroyQueue(LQueue* pq);        // 원형 큐 삭제
int CountQueueItem(LQueue* pq);       // 큐의 원소의 개수
void ClearQueue(LQueue* pq);          // 큐의 모든 원소 삭제


#endif