#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable :4996)

typedef struct {
	int front, rear;
	int* card;
	int size;
}queuetype;

void enqueue(queuetype* p, int input) {
	p->rear = (p->rear + 1) % p->size;
	p->card[p->rear] = input;
}

int dequeue(queuetype* p) {
	p->front = (p->front + 1) % p->size;
	return p->card[p->front];
}

int main() {
	int N;
	scanf("%d", &N);
	queuetype Q = { 0, N - 1, (int*)malloc((N * 4) * sizeof(int)), N * 4 };
	
	queuetype* p = &Q;
	for (int i = 0; i < N; i++) {
		Q.card[i] = i + 1;
	}
	while (p->front != p->rear) {
		enqueue(p, dequeue(p));
		Q.front++;
	}
	printf("%d", p->card[p->rear]);
}