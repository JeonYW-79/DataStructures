/*
Array_based Stack 2
	Written by: wowo0709
	Date: 2021-04-14
*/
#include "Array_Stack_2.h"
#include <stdio.h>
#include <stdlib.h>

ArrayStack* CreateStack()           // ���� ���� �� �ʱ�ȭ
{
	ArrayStack* pStack = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (pStack == NULL)
		return NULL;

	pStack->top = -1;

	return pStack;
}
void Push(ArrayStack* pStack, int* item) // ���ÿ� ���� push
{
	if (IsFull(pStack)) {
		printf("Stack Overflow!!!");
		return;
	}

	// pStack->stack[++pStack->top] = item;
	pStack->top++;
	pStack->stack[pStack->top][0] = item[0];
	pStack->stack[pStack->top][1] = item[1];

	return;
}
int* Pop(ArrayStack* pStack)             // ������ ���� pop
{
	int* ret = (int*)malloc(sizeof(int) * 2);
	if (IsEmpty(pStack)) {
		printf("Stack Underflow!!!");
		return 0;
	}
	// 1. �迭(�� �� �̻��� ��)�� ������ �� �ε����� --�� ++ ������ ���� �ȵȴ�. 
	// 2. ���� �� ret���� ���� �־��ְ� �����ؾ� �Ѵ�. ret�� �ּҸ� �����ϵ��� �ϸ�
	//    ������ �ּҰ� ���ϸ� ret�� ���Ѵ�. 
	ret[0] = pStack->stack[pStack->top][0];
	ret[1] = pStack->stack[pStack->top][1];
	pStack->top--;
	
	return ret;
}
int* Peek(ArrayStack* pStack)            // ������ �� ���� ���� ����
{
	if (IsEmpty(pStack))
		printf("Stack is empty!!!");

	return pStack->stack[pStack->top];
}
void DestroyStack(ArrayStack* pStack)       // ���� ����
{

	free(pStack);

	return;
}
int IsEmpty(ArrayStack* pStack)             // ������ �� ������� �˻�
{
	return (pStack->top == -1);
}
int IsFull(ArrayStack* pStack)              // ������ �� á���� �˻�
{
	return (pStack->top == pStack->size - 1);
}
int CountStackItem(ArrayStack* pStack)      // ������ ������ ����
{
	return pStack->top + 1;
}
void PrintStackItems(ArrayStack* pStack)    // ������ ��� ���� ���
{
	int cur = 0;

	printf("Stack Items: ");
	while(cur < pStack->top + 1)
	{
		printf("%d ", pStack->stack[cur++]);
	}
	printf("\n");

	return;
}
