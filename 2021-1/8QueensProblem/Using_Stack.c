#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Array_Stack_2.h"

#define MAX_SIZE 8

// 퀸의 배치 출력
void printBoard(int* board, int cnt) {
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

int solve(int* board) {
	ArrayStack* s = CreateStack();
	int* init_pos = (int*)malloc(sizeof(int) * 2);
	// 첫번째 행의 모든 열 추가
	for (int i = 0; i < MAX_SIZE; i++) { 
		init_pos[0] = 0; init_pos[1] = i;
		Push(s, init_pos);
	}

	int* pos = (int*)malloc(sizeof(int) * 2);
	int cnt = 0, flag = 0;
	// 더 이상 후보지가 없을 때까지 진행
	while (!IsEmpty(s)) {
		pos = Pop(s);
		int row = pos[0], col = pos[1];
		board[row] = col;

		flag = 1;
		for (int i = 0; i < row; i++) {  // 현재 행 전까지
			// 같은 열 또는 대각선에 queen이 존재하면 다음 열 검사
			if (col == board[i] || abs(row - i) == abs(col - board[i])) {
				flag = 0;
				break;
			}
		}
		// 현재 위치에 놓을 수 있다면, 
		if (flag) {
			// 마지막 행이라면 cnt++ 하고 다음 후보지 검사
			if (row == MAX_SIZE - 1) {
				cnt++;
				printBoard(board, cnt);
				continue;
			}
			// 아니라면 다음 행의 모든 열 추가
			for (int j = 0; j < MAX_SIZE; j++) {
				pos[0] = row + 1; pos[1] = j;
				Push(s, pos);
			}
		}
	}
	return cnt;
}

int main(void)
{
	int board[MAX_SIZE]; // idx번째 행에 배치된 퀸의 열 위치 저장
	printf("Answer: %d", solve(board));
}