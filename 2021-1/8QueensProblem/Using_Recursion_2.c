/*
8 Queens Problem using Recursion 2
	Written by: wowo0709
	Date: 2021-04-03
*/
#include <stdio.h>

#define MAX_SIZE 8

int solve(int row, int cnt,int col[], int rightup[], int rightdown[]) {
	if (row == MAX_SIZE) {
		return ++cnt;
	}
	// 각 열에 대하여
	for (int idx = 0; idx < MAX_SIZE; idx++) { 
		// 현재 위치에 놓을 수 있는 경우
		if (col[idx] == 0 && rightup[row + idx] == 0 && rightdown[row - idx + MAX_SIZE - 1] == 0) { 
			// 현재 위치에 놓고
			col[idx] = rightup[row + idx] = rightdown[row - idx + MAX_SIZE - 1] = 1;
			// 다음 줄 탐색
			cnt = solve(row + 1, cnt,col,rightup,rightdown);
			// 탐색 종료 시 현재 위치에서 뺀다. 
			col[idx] = rightup[row + idx] = rightdown[row - idx + MAX_SIZE - 1] = 0;
		}
	}
	return cnt;
}

int main(void)
{
	// 상하 방향, 우상향방향, 우하향방향 으로 이동 가능한지 체크 (0:가능, 1:불가능)
	int col[8] = { 0, }, rightup[15] = { 0, }, rightdown[15] = { 0, };
	printf("Answer: %d", solve(0,0,col,rightup,rightdown));
}
