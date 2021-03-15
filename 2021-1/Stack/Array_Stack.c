#include "Array_Stack.h"
#include <stdio.h>
#include <stdlib.h>

ArrayStack* CreateStack(int size)           // 스택 생성 및 초기화
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
void Push(ArrayStack* pStack, Element item) // 스택에 원소 push
{
	if (IsFull(pStack)) {
		printf("Stack Overflow!!!");
		return;
	}

	pStack->stack[++pStack->top] = item;

	return;
}
Element Pop(ArrayStack* pStack)             // 스택의 원소 pop
{
	if (IsEmpty(pStack)) {
		printf("Stack Underflow!!!");
		return 0;
	}

	return pStack->stack[pStack->top--];
}
Element Peek(ArrayStack* pStack)            // 스택의 맨 위의 원소 참조
{
	if (IsEmpty(pStack))
		printf("Stack is empty!!!");

	return pStack->stack[pStack->top];
}
void DestroyStack(ArrayStack* pStack)       // 스택 삭제
{
	if (!IsEmpty(pStack))
		free(pStack->stack);

	free(pStack);

	return;
}
int IsEmpty(ArrayStack* pStack)             // 스택이 텅 비었는지 검사
{
	return (pStack->top == -1);
}
int IsFull(ArrayStack* pStack)              // 스택이 꽉 찼는지 검사
{
	return (pStack->top == pStack->size - 1);
}
int CountStackItem(ArrayStack* pStack)      // 스택의 원소의 개수
{
	return pStack->top + 1;
}
void PrintStackItems(ArrayStack* pStack)    // 스택의 모든 원소 출력
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
void ClearStack(ArrayStack* pStack)         // 스택의 모든 원소 삭제
{
	free(pStack->stack);

	return;
}
