/*
8 Queens Problem using Recursion 1
	Written by: wowo0709
	Date: 2021-04-03
*/
/*
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 8

// 퀸의 배치 출력
void printBoard(int board[], int cnt) {
	printf("NO.%d\n", cnt);
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (board[i] == j) printf("■");
			else printf("□"); 
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
	for (int i = 0; i < MAX_SIZE; i++) { // 모든 열에 대해
		flag = 1;
		for (int j = 0; j < row; j++) {  // 현재 행 전까지 검사 
			// 같은 열 또는 대각선에 queen이 존재하면 다음 열 검사
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
	int board[MAX_SIZE]; // idx번째 행에 배치된 퀸의 열 위치 저장
	printf("Answer: %d",solve(board, 0, 0));
}
*/