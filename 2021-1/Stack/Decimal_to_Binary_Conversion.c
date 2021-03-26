/*
Convert decimal to binary.
	Written by: wowo0709
	Date: 2021-03-22
*/
#include <stdio.h>
#include "Array_Stack.h" // Include Stack header file

#define STACK_SIZE 100   // Define Stack size

int main(void)
{
	ArrayStack* stack = CreateStack(STACK_SIZE);  // Create Stack (Memory allocation)
	int num, n;

	printf("*****Start Decimal to Binary Conversion Program*****\n\n");

	printf("Input Decimal number:");
	scanf(" %d", &num);                          // Input decimal number 

	while (num) {                                 // Convert to Binary
		n = num % 2;
		Push(stack, n);
		num = num / 2;

		printf("n: %d\t  num: %d\t", n, num);
		PrintStackItems(stack);
	}

	printf("Converted to Binary number: ");
	while (!IsEmpty(stack))                      // Display converted binary number
		printf("%d", Pop(stack));

	printf("\n\n*****End Decimal to Binary Conversion Program*****\n");

	DestroyStack(stack);                         // Destroy Stack (free allocated memory)

	return 0;
}