#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__
// �迭 ����� ���� ����
#include <stdio.h>

typedef int Element;

typedef struct _arrayStack
{
	Element* stack;
	int size;
	int top;
}ArrayStack;

ArrayStack* CreateStack(int size);           // ���� ���� �� �ʱ�ȭ
void Push(ArrayStack* pStack, Element item); // ���ÿ� ���� push
Element Pop(ArrayStack* pStack);             // ������ ���� pop
Element Peek(ArrayStack* pStack);            // ������ �� ���� ���� ����
void DestroyStack(ArrayStack* pStack);       // ���� ����
int IsEmpty(ArrayStack* pStack);             // ������ �� ������� �˻�
int IsFull(ArrayStack* pStack);              // ������ �� á���� �˻�
int CountStackItem(ArrayStack* pStack);      // ������ ������ ����
void PrintStackItems(ArrayStack* pStack);    // ������ ��� ���� ���
void ClearStack(ArrayStack* pStack);         // ������ ��� ���� ����


#endif
