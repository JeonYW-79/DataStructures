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

CQueue* CreateQueue(int size);         // ���� ť ����
void Enqueue(CQueue* pq,Element item); // ť�� ���� ����
Element Dequeue(CQueue* pq);           // ť���� ���� ���� �� ��ȯ
Element QPeek(CQueue* pq);             // ť���� ���� ��ȯ
int QIsFull(CQueue* pq);               // ť�� �� á���� �˻�
int QIsEmpty(CQueue* pq);              // ť�� �� ������� �˻�
void DestroyQueue(CQueue* pq);         // ���� ť ����
int CountQueueItem(CQueue* pq);        // ť�� ������ ����
void PrintQueueItems(CQueue* pq);      // ť�� ��� ���� ���
void ClearQueue(CQueue* pq);           // ť�� ��� ���� ����



#endif
