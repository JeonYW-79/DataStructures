#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Array_Stack_2.h"

#define MAX_SIZE 8

// ���� ��ġ ���
void printBoard(int* board, int cnt) {
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

int solve(int* board) {
	ArrayStack* s = CreateStack();
	int* init_pos = (int*)malloc(sizeof(int) * 2);
	// ù��° ���� ��� �� �߰�
	for (int i = 0; i < MAX_SIZE; i++) { 
		init_pos[0] = 0; init_pos[1] = i;
		Push(s, init_pos);
	}

	int* pos = (int*)malloc(sizeof(int) * 2);
	int cnt = 0, flag = 0;
	// �� �̻� �ĺ����� ���� ������ ����
	while (!IsEmpty(s)) {
		pos = Pop(s);
		int row = pos[0], col = pos[1];
		board[row] = col;

		flag = 1;
		for (int i = 0; i < row; i++) {  // ���� �� ������
			// ���� �� �Ǵ� �밢���� queen�� �����ϸ� ���� �� �˻�
			if (col == board[i] || abs(row - i) == abs(col - board[i])) {
				flag = 0;
				break;
			}
		}
		// ���� ��ġ�� ���� �� �ִٸ�, 
		if (flag) {
			// ������ ���̶�� cnt++ �ϰ� ���� �ĺ��� �˻�
			if (row == MAX_SIZE - 1) {
				cnt++;
				printBoard(board, cnt);
				continue;
			}
			// �ƴ϶�� ���� ���� ��� �� �߰�
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
	int board[MAX_SIZE]; // idx��° �࿡ ��ġ�� ���� �� ��ġ ����
	printf("Answer: %d", solve(board));
}