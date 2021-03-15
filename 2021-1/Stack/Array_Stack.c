#include "Array_Stack.h"
#include <stdio.h>
#include <stdlib.h>

ArrayStack* CreateStack(int size)           // ���� ���� �� �ʱ�ȭ
{
	ArrayStack* pStack = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (pStack == NULL)
		return NULL;

	pStack->stack = (Element*)malloc(size * sizeof(Element));
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}

	pStack->size = size;
	pStack->top = -1;

	return pStack;
}
void Push(ArrayStack* pStack, Element item) // ���ÿ� ���� push
{
	if (IsFull(pStack)) {
		printf("Stack Overflow!!!");
		return;
	}

	pStack->stack[++pStack->top] = item;

	return;
}
Element Pop(ArrayStack* pStack)             // ������ ���� pop
{
	if (IsEmpty(pStack)) {
		printf("Stack Underflow!!!");
		return 0;
	}

	return pStack->stack[pStack->top--];
}
Element Peek(ArrayStack* pStack)            // ������ �� ���� ���� ����
{
	if (IsEmpty(pStack))
		printf("Stack is empty!!!");

	return pStack->stack[pStack->top];
}
void DestroyStack(ArrayStack* pStack)       // ���� ����
{
	if (!IsEmpty(pStack))
		free(pStack->stack);

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
void ClearStack(ArrayStack* pStack)         // ������ ��� ���� ����
{
	free(pStack->stack);

	return;
}
