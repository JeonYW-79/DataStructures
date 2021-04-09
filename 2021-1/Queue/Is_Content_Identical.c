/*
Check whether the contens of two queues are same. 
	Written by: wowo0709
	Date: 2021-04-09
*/
#include "Linked_List_Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	while (1) {
		int size;
		printf("\nEnter the size(0 to quit): "); // 생성할 큐의 크기
		scanf("%d", &size);
		// 0 이하의 숫자가 입력되면 프로그램 종료
		if (size < 1) {
			printf("Exit program");
			break;
		}

		LQueue* q1 = CreateQueue(), * q2 = CreateQueue(); // 큐 2개 생성

		// 난수를 큐에 Enqueue
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			Enqueue(q1, rand() % 5 + 1);
			Enqueue(q2, rand() % 5 + 1);
		}

		// 큐의 원소 확인
		printf("queue 1: ");
		PrintQueueItems(q1);
		printf("\nqueue 2: ");
		PrintQueueItems(q2);
		printf("\n");

		// 큐 안의 각 원소가 동일한 지 확인
		int n1, n2;
		int cnt = 0, cnt_same = 0;
		while (!QIsEmpty(q1)) {
			n1 = (int)Dequeue(q1), n2 = (int)Dequeue(q2);
			if (n1 == n2) {
				printf("Element[%d] is same!!(%d == %d)\n", cnt, n1, n2);
				cnt_same++;
			}
			else {
				printf("Element[%d] is different!!(%d != %d)\n", cnt, n1, n2);
			}
			cnt++;
		}

		// 최종 결과 출력
		if (cnt == cnt_same) printf("==>The contents of two queues are identical.");
		else printf("==>The contents of two queues are different.");
	}

	return 0;

}
