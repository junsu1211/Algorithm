#include <stdio.h>
#include <stdlib.h>

int main() {
	char getc[50];
	int Queue[100000] = { 0 };
	int N;
	int pointer = 0;
	int pnum;
	scanf("%d", &N); // 명령의 수
	
	for (int i = 0; i < N; i++) { //명령을 N번반복
		scanf("%s", getc);

		if (strcmp(getc, "push") == 0) { // push 연산
			scanf("%d", &pnum);
			Queue[pointer] = pnum;
			pointer++;
		}
		else if (strcmp(getc, "pop") == 0) {
			if (Queue[0] == 0) { // 데이터가 하나도 없으면
				printf("-1\n");
			}
			else { // 데이터가 하나라도 있으면
				printf("%d\n", Queue[0]);
				for (int i = 0; i < pointer; i++) { // 큐의 빈자리를 메꿈
					Queue[i] = Queue[i + 1];
				}
				Queue[pointer] = 0;
				pointer--;
			}
		}
		else if (strcmp(getc, "size") == 0) {
			if (pointer <= 0) {
				printf("0\n");
			}
			else {
				printf("%d\n", pointer);
			}
		}
		else if (strcmp(getc, "empty") == 0) {
			if (Queue[0] == 0) {
				printf("1\n");
			}
			else
				printf("0\n");
		}
		else if (strcmp(getc, "front") == 0) {
			if (Queue[0] == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", Queue[0]);
			}
		}
		else if (strcmp(getc, "back") == 0) {
			if (Queue[0] == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", Queue[pointer - 1]);
			}
		}

	}
	return 0;
}