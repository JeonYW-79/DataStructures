/*
Array_based Stack 2
	Written by: wowo0709
	Date: 2021-04-14
*/
#include "Array_Stack_2.h"
#include <stdio.h>
#include <stdlib.h>

ArrayStack* CreateStack()           // 스택 생성 및 초기화
{
	ArrayStack* pStack = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (pStack == NULL)
		return NULL;

	pStack->top = -1;

	return pStack;
}
void Push(ArrayStack* pStack, int* item) // 스택에 원소 push
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
int* Pop(ArrayStack* pStack)             // 스택의 원소 pop
{
	int* ret = (int*)malloc(sizeof(int) * 2);
	if (IsEmpty(pStack)) {
		printf("Stack Underflow!!!");
		return 0;
	}
	// 1. 배열(두 개 이상의 값)을 리턴할 때 인덱스에 --나 ++ 연산을 쓰면 안된다. 
	// 2. 리턴 값 ret에는 값을 넣어주고 리턴해야 한다. ret가 주소를 참조하도록 하면
	//    참조한 주소가 변하면 ret도 변한다. 
	ret[0] = pStack->stack[pStack->top][0];
	ret[1] = pStack->stack[pStack->top][1];
	pStack->top--;
	
	return ret;
}
int* Peek(ArrayStack* pStack)            // 스택의 맨 위의 원소 참조
{
	if (IsEmpty(pStack))
		printf("Stack is empty!!!");

	return pStack->stack[pStack->top];
}
void DestroyStack(ArrayStack* pStack)       // 스택 삭제
{

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
