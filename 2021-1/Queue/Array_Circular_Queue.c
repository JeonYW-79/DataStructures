/*
Array based Circular Queue
	Written by: wowo0709
	Date: 2021-03-26
*/
#include "Array_Circular_Queue.h"
#include <stdio.h>
#include <stdlib.h>

CQueue* CreateQueue(int size)  // ���� ť ����
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
void Enqueue(CQueue* pq,Element item)  // ť�� ���� ����
{
	if (QIsFull(pq)) {
		printf("Queue Overflow!!");
		return;
	}
	pq->count += 1;

	pq->rear = (pq->rear + 1) % pq->size;   // ���� ������Ű��,
	pq->queue[pq->rear] = item;             // ���� ����

	return;
}
Element Dequeue(CQueue* pq)           // ť���� ���� ���� �� ��ȯ
{
	if (QIsEmpty(pq)) {
		printf("Queue Underflow!!");
		return;
	}
	pq->count -= 1;

	pq->front = (pq->front + 1) % pq->size; // ���� ������Ű��,
	return pq->queue[pq->front];            // ���� ��ȯ
}
Element QPeek(CQueue* pq)             // ť���� ���� ��ȯ
{
	if (QIsEmpty(pq)) {
		printf("Queue Underflow!!");
		return;
	}
	return pq->queue[(pq->front + 1) % pq->size];  // ���� ��ȯ
}
int QIsFull(CQueue* pq)              // ť�� �� á���� �˻�
{
	if ((pq->rear + 1) % pq->size == pq->front)
		return 1;
	else
		return 0;
}
int QIsEmpty(CQueue* pq)             // ť�� �� ������� �˻�
{
	if (pq->rear == pq->front)
		return 1;
	else
		return 0;
}
void DestroyQueue(CQueue* pq)        // ���� ť ����
{
	free(pq);

	return;
}
int CountQueueItem(CQueue* pq)      // ť�� ������ ����
{
	return pq->count;
}
void PrintQueueItems(CQueue* pq)    // ť�� ��� ���� ���
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
void ClearQueue(CQueue* pq)         // ť�� ��� ���� ����
{
	free(pq->queue);

	pq->queue = (Element*)malloc(sizeof(Element) * pq->size);

	return;
}