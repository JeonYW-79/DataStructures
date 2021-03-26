/*
Array based Circular Queue
	Written by: wowo0709
	Date: 2021-03-26
*/
#include "Array_Circular_Queue.h"
#include <stdio.h>
#include <stdlib.h>

CQueue* CreateQueue(int size)  // 원형 큐 생성
{
	CQueue* cQueue = (CQueue*)malloc(sizeof(CQueue));
	if (cQueue == NULL)
		return;

	cQueue->queue = (Element*)malloc(sizeof(Element) * size);
	if (cQueue->queue == NULL) {
		free(cQueue);
		return;
	}
	cQueue->size = size;
	cQueue->count = 0;
	cQueue->front = cQueue->rear = 0;

	return cQueue;
}
void Enqueue(CQueue* pq,Element item)  // 큐에 원소 삽입
{
	if (QIsFull(pq)) {
		printf("Queue Overflow!!");
		return;
	}
	pq->count += 1;

	pq->rear = (pq->rear + 1) % pq->size;   // 먼저 증가시키고,
	pq->queue[pq->rear] = item;             // 원소 삽입

	return;
}
Element Dequeue(CQueue* pq)           // 큐에서 원소 삭제 및 반환
{
	if (QIsEmpty(pq)) {
		printf("Queue Underflow!!");
		return;
	}
	pq->count -= 1;

	pq->front = (pq->front + 1) % pq->size; // 먼저 증가시키고,
	return pq->queue[pq->front];            // 원소 반환
}
Element QPeek(CQueue* pq)             // 큐에서 원소 반환
{
	if (QIsEmpty(pq)) {
		printf("Queue Underflow!!");
		return;
	}
	return pq->queue[(pq->front + 1) % pq->size];  // 원소 반환
}
int QIsFull(CQueue* pq)              // 큐에 꽉 찼는지 검사
{
	if ((pq->rear + 1) % pq->size == pq->front)
		return 1;
	else
		return 0;
}
int QIsEmpty(CQueue* pq)             // 큐가 텅 비었는지 검사
{
	if (pq->rear == pq->front)
		return 1;
	else
		return 0;
}
void DestroyQueue(CQueue* pq)        // 원형 큐 삭제
{
	free(pq);

	return;
}
int CountQueueItem(CQueue* pq)      // 큐의 원소의 개수
{
	return pq->count;
}
void PrintQueueItems(CQueue* pq)    // 큐의 모든 원소 출력
{
	int cur = 0;

	printf("Queue Items: ");
	while (cur < pq->count)
	{
		printf("%d ", pq->queue[cur++]);
	}
	printf("\n");

	return;
}
void ClearQueue(CQueue* pq)         // 큐의 모든 원소 삭제
{
	free(pq->queue);

	pq->queue = (Element*)malloc(sizeof(Element) * pq->size);

	return;
}