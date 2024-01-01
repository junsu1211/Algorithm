#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define End 0

int main() {
	int N=0; // 명령의 수
	int t = 0; // 스택 포인터
	char* b = "pop";
	char* c = "size";
	char* d = "empty";
	char* e = "top";
	char command[2000] = { '\0' };
	int qw = 0;
	int num=0;
	int stack[10001] = { 0 }; // 0으로 초기화

	scanf("%d", &N);
	if (N > 10000 || N < 1) {
		perror("범위 초과");
		return 1;
	}
	
	int q = 0; // 들어온 정수의 개수

	for (int i = 0; i < N; i++) {
		
		scanf("%s", command);

		if (strcmp(b, command) == 0) { //pop 연산
			if (stack[End] == 0) { // 스택의 가장 밑바닥이 비어있는 경우
				printf("-1\n");
			}
			else {
				t = t - 1;
				printf("%d\n", stack[t]); // 현재 스택 포인터의 위치에 있는 것을 뽑아냄
				q--;
				stack[t] = 0;
			}
		}
		else if (strcmp(c, command) == 0) { // size연산
				printf("%d\n", q);
			}
		else if (strcmp(d, command) == 0) { // empty연산
				if (stack[End] == 0) { // 스택의 가장 밑바닥이 비어있는 경우
					printf("1\n");
				}
				else {
					printf("0\n");
				}
			}
		else if (strcmp(e, command) == 0) { // top연산
			if (stack[End] == 0) { // 스택의 가장 밑바닥이 비어있는 경우
				printf("-1\n");
			}
			else {
				t = t - 1;
				printf("%d\n", stack[t]);
				t = t + 1;
			}
		}
		else  {
			scanf("%d", &num);
			stack[t] = num;
			t = t + 1;
			q++;
		}
	}
	return 0;
} 