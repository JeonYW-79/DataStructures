#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Array_Stack.h"

#define MAX_SIZE 8

int solve(int board[]) {
	ArrayStack* s = CreateStack(pow(MAX_SIZE,MAX_SIZE));
	int* init_pos = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < MAX_SIZE; i++) {
		init_pos[0] = 0; init_pos[1] = i;
		Push(s, init_pos);
	}
	int* pos;
	int cnt = 0;
	// int visited[MAX_SIZE][MAX_SIZE] = { 0, };
	while (!IsEmpty(s)) {
		pos = Pop(s);
		int row = pos[0], col = pos[1];
		board[row] = col;
		// visited[row][col] = 1;
		printf("%d %d\n", row,col);
		if (row == MAX_SIZE) {
			cnt++;
			continue;
		}
		// visited[row][col] = 1;
		int flag = 1;
		for (int j = 0; j < row; j++) {  // ���� �� ������
			// ���� �� �Ǵ� �밢���� queen�� �����ϸ� ���� �� �˻�
			if (row == board[j] || abs(row - j) == abs(row - board[j])) {
				flag = 0;
				break;
			}
		}
			
		if (flag) {
			board[row] = col;
			for (int i = 0; i < MAX_SIZE; i++) {
				pos[0] = row+1; pos[1] = i;
				Push(s, pos);
			}
		}
		
	}
	return cnt;
}

int main(void)
{
	int board[MAX_SIZE]; // idx��° �࿡ ��ġ�� ���� �� ��ġ ����
	printf("Answer: %d", solve(board));
}