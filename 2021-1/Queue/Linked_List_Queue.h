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

LQueue* CreateQueue();                // ���� ť ����
void Enqueue(LQueue* pq, void* item); // ť�� ���� ����
void* Dequeue(LQueue* pq);            // ť���� ���� ���� �� ��ȯ
void* QPeek(LQueue* pq);              // ť���� ���� ��ȯ
int QIsEmpty(LQueue* pq);             // ť�� �� ������� �˻�
void DestroyQueue(LQueue* pq);        // ���� ť ����
int CountQueueItem(LQueue* pq);       // ť�� ������ ����
void ClearQueue(LQueue* pq);          // ť�� ��� ���� ����


#endif