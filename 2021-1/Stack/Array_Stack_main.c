// 스택 테스트

#include "Array_Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 5

int main(void)
{
	int item = 0;
	// char* cmd; ->문자열 리터럴이 할당된 포인터 변수는 쓰기가 불가능(읽기 전용 메모리)

	ArrayStack* pStack = CreateStack(STACK_SIZE);

	while (1) {

		char* cmd = malloc(sizeof(char)*10);
		printf("\nEnter the command(push/pop/q(to quit)):");
		scanf("%s", cmd); 
		if (strcmp(cmd, "push") == 0) {
			printf("Input an integer:");
			scanf(" %d", &item);
			Push(pStack, item);
		}
		else if (strcmp(cmd, "pop") == 0) {
			item = Pop(pStack);
			printf("item: %d", item);
		}
		else if (strcmp(cmd, "q") == 0) {
			printf("Exit program");
			break;
		}
		else {
			printf("Wrong command");
		}

		printf("\nNumber of items: %d\n", CountStackItem(pStack));
		PrintStackItems(pStack);
		free(cmd);
	}

	DestroyStack(pStack);
	
	return 0;

}