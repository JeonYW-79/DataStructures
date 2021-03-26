/*
LinkedList based Queue
	Written by: wowo0709
	Date: 2021-03-26
*/
#include "Linked_List_Queue.h"
#include <stdio.h>
#include <stdlib.h>

LQueue* CreateQueue()                // 원형 큐 생성
{
	LQueue* lQueue = (LQueue*)malloc(sizeof(LQueue));
	if (lQueue == NULL)
		return;
	lQueue->count = 0;
	lQueue->front = lQueue->rear = NULL;

	return lQueue;
}
void Enqueue(LQueue* pq, void* item) // 큐에 원소 삽입
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->item = item;

	if (QIsEmpty(pq)) {
		pq->front = pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	pq->count += 1;

	return;
}
void* Dequeue(LQueue* pq)            // 큐에서 원소 삭제 및 반환
{
	Node* delNode;
	void* ret;

	if (QIsEmpty(pq)) {
		printf("Queue Underflow!!");
		return;
	}

	delNode = pq->front;
	ret = pq->front->item;
	pq->front = pq->front->next;

	free(delNode);
	pq->count -= 1;

	return ret;
}
void* QPeek(LQueue* pq)              // 큐에서 원소 반환
{
	return pq->front->item;
}
int QIsEmpty(LQueue* pq)             // 큐가 텅 비었는지 검사
{
	return (pq->count == 0);
}
void DestroyQueue(LQueue* pq)        // 원형 큐 삭제
{
	Node* pCur = NULL;
	Node* pNext = NULL;

	for (pCur = pq->front; pCur != NULL; pCur = pNext) {
		pNext = pCur->next;
		free(pCur);
	}

	pq->count = 0;
	pq->front = pq->rear = NULL;

	free(pq);

	return;
}
int CountQueueItem(LQueue* pq)       // 큐의 원소의 개수
{
	return pq->count;
}
void ClearQueue(LQueue* pq)          // 큐의 모든 원소 삭제
{
	Node* pCur = NULL;
	Node* pNext = NULL;

	for (pCur = pq->front; pCur != NULL; pCur = pNext) {
		pNext = pCur->next;
		free(pCur);
	}

	pq->count = 0;
	pq->front = pq->rear = NULL;
}