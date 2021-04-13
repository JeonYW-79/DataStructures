/*
Array_based Stack
	Written by: wowo0709
	Date: 2021-03-22
*/
#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__
// 배열 기반의 스택 구현
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

ArrayStack* CreateStack(int size);           // 스택 생성 및 초기화
void Push(ArrayStack* pStack, int* item); // 스택에 원소 push
int* Pop(ArrayStack* pStack);             // 스택의 원소 pop
int* Peek(ArrayStack* pStack);            // 스택의 맨 위의 원소 참조
void DestroyStack(ArrayStack* pStack);       // 스택 삭제
int IsEmpty(ArrayStack* pStack);             // 스택이 텅 비었는지 검사
int IsFull(ArrayStack* pStack);              // 스택이 꽉 찼는지 검사
int CountStackItem(ArrayStack* pStack);      // 스택의 원소의 개수
void PrintStackItems(ArrayStack* pStack);    // 스택의 모든 원소 출력
void ClearStack(ArrayStack* pStack);         // 스택의 모든 원소 삭제


#endif
