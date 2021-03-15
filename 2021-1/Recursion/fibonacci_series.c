/*
Calculate the fibonacci number.
	Written by: wowo0709
	Date: 2021-03-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibo_iter(int n);  // iteration
int fibo_recur(int n); // recursion

int main(void)
{
	clock_t start, end;
	for (int n = 0; n <= 40; n += 5) {
		printf("Calculate fibonacci(%d)...\n", n);
		// iteration
		printf("==========Iteration==========\n");
		start = clock();
		printf("Fibonacci(%d) = %d\n", n, fibo_iter(n));
		end = clock();
		printf("Time elapsed: %.2f ms\n", (float)(end - start / CLOCKS_PER_SEC));
		// recursion
		printf("==========Recursion==========\n");
		start = clock();
		printf("Fibonacci(%d) = %d\n", n, fibo_recur(n));
		end = clock();
		printf("Time elapsed: %.2f ms\n\n", (float)(end - start / CLOCKS_PER_SEC));
	}
}

int fibo_iter(int n) // bottom-top approach(dynammic programming)
{
	int *fibo = malloc(sizeof(int) * (n+1));
	for (int i = 0; i <= n; i++) {
		if (i <= 1) fibo[i] = i; // fibonacci(0) = 0, fibonacci(1) = 1
		else fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int ret = fibo[n]; // return value
	free(fibo);        // release allocated memory
	return ret;        // fibo[n]
}

int fibo_recur(int n) // top-bottom approach(divide and conquer)
{
	if (n <= 1) return n; // fibonacci(0) = 0, fibonacci(1) = 1
	return fibo_recur(n - 1) + fibo_recur(n - 2);
}