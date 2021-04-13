/*
Array_based Stack
	Written by: wowo0709
	Date: 2021-03-22
*/
#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__
// �迭 ����� ���� ����
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 20000000

// typedef int Element;

typedef struct _arrayStack
{
	int stack[MAX_SIZE][2];
	int size;
	int top;
}ArrayStack;

ArrayStack* CreateStack(int size);           // ���� ���� �� �ʱ�ȭ
void Push(ArrayStack* pStack, int* item); // ���ÿ� ���� push
int* Pop(ArrayStack* pStack);             // ������ ���� pop
int* Peek(ArrayStack* pStack);            // ������ �� ���� ���� ����
void DestroyStack(ArrayStack* pStack);       // ���� ����
int IsEmpty(ArrayStack* pStack);             // ������ �� ������� �˻�
int IsFull(ArrayStack* pStack);              // ������ �� á���� �˻�
int CountStackItem(ArrayStack* pStack);      // ������ ������ ����
void PrintStackItems(ArrayStack* pStack);    // ������ ��� ���� ���
void ClearStack(ArrayStack* pStack);         // ������ ��� ���� ����


#endif
