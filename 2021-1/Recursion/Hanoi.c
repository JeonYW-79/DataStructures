#include <stdio.h>

int cnt = 0;

void Hanoi(int n, char from, char by, char to)
{
	if (n == 1) {
		printf("Move from %c to %c\n", from, to);
		cnt++;
		return;
	}
	Hanoi(n - 1, from, to, by);
	Hanoi(1, from, by, to);
	Hanoi(n - 1, by, from, to);
}

int main(void) 
{
	Hanoi(5,'A','B','C');
	printf("Total: %d times", cnt);
}