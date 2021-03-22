#include <stdio.h>
#include "Array_Stack.h"

#define STACK_SIZE 100

int main(void)
{
	ArrayStack* stack = CreateStack(STACK_SIZE);
	int num,n;

	printf("*****Start Decimal to Binary Conversion Program*****\n\n");

	printf("Input Decimal number:");
	scanf(" %d", &num);

	while(num) {
		n = num % 2;
		Push(stack, n);
		num = num / 2;
	}

	printf("Converted to Binary number: ");
	while (!IsEmpty(stack))
		printf("%d", Pop(stack));

	printf("\n\n*****End Decimal to Binary Conversion Program*****\n");

	return 0;
}