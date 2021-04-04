/*
8 Queens Problem using Recursion 1
	Written by: wowo0709
	Date: 2021-04-03
*/
/*
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 8

// ���� ��ġ ���
void printBoard(int board[], int cnt) {
	printf("NO.%d\n", cnt);
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (board[i] == j) printf("��");
			else printf("��"); 
		}
		printf(" %d ", board[i]);
		printf("\n");
	}
	printf("\n");
}

int solve(int board[],int row, int cnt) {
	if (row == MAX_SIZE) {
		printBoard(board, cnt+1);
		return ++cnt;
	}
	int flag;
	for (int i = 0; i < MAX_SIZE; i++) { // ��� ���� ����
		flag = 1;
		for (int j = 0; j < row; j++) {  // ���� �� ������ �˻� 
			// ���� �� �Ǵ� �밢���� queen�� �����ϸ� ���� �� �˻�
			if (i == board[j] || abs(row - j) == abs(i - board[j])) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			board[row] = i;
			cnt = solve(board, row + 1, cnt);
		}
	}
	return cnt;
}

// main
int main(void)
{
	int board[MAX_SIZE]; // idx��° �࿡ ��ġ�� ���� �� ��ġ ����
	printf("Answer: %d",solve(board, 0, 0));
}
*/