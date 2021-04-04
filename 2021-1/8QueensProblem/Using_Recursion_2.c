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
	// �� ���� ���Ͽ�
	for (int idx = 0; idx < MAX_SIZE; idx++) { 
		// ���� ��ġ�� ���� �� �ִ� ���
		if (col[idx] == 0 && rightup[row + idx] == 0 && rightdown[row - idx + MAX_SIZE - 1] == 0) { 
			// ���� ��ġ�� ����
			col[idx] = rightup[row + idx] = rightdown[row - idx + MAX_SIZE - 1] = 1;
			// ���� �� Ž��
			cnt = solve(row + 1, cnt,col,rightup,rightdown);
			// Ž�� ���� �� ���� ��ġ���� ����. 
			col[idx] = rightup[row + idx] = rightdown[row - idx + MAX_SIZE - 1] = 0;
		}
	}
	return cnt;
}

int main(void)
{
	// ���� ����, ��������, ��������� ���� �̵� �������� üũ (0:����, 1:�Ұ���)
	int col[8] = { 0, }, rightup[15] = { 0, }, rightdown[15] = { 0, };
	printf("Answer: %d", solve(0,0,col,rightup,rightdown));
}
