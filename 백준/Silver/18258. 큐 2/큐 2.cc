#include <iostream>

using namespace std;

typedef struct Queue {
	int N;
	int* Queue;
	int front;
	int rear;
}QueueType;

bool isempty(QueueType* Q) {
	if (Q->front == Q->rear)
		return true; // 비어있다
	else
		return false;
}

bool isfull(QueueType* Q) {
	if (Q->rear == Q->N) { // 큐가 꽉참
		return true;
	}
}

void init(QueueType* Q) {
	Q->front = 0;
	Q->rear = 0;
} // 큐가 비어 있는 상태

void push(int A, QueueType* Q) {

	Q->rear++;
	Q->Queue[Q->rear] = A;
}

int size(QueueType* Q) {
	return Q->rear - Q->front;
}
int pop(QueueType* Q) {
	if (isempty(Q) == true) { // 큐가 비어있다면
		return -1;
	}
	else {
		Q->front++;
		return Q->Queue[Q->front];
	}
}

int front(QueueType* Q) {
	if (isempty(Q) == true) { // 큐가 비어있다면
		return -1;
	}
	else
		return Q->Queue[Q->front + 1];
}

int back(QueueType* Q) {
	if (isempty(Q) == true)
		return -1;
	else
		return Q->Queue[Q->rear];
}

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);

	int N; // 명령의 수
	cin >> N;

	string command;
	int* result = new int[N + 1];
	int pushnum = 0;

	QueueType* Q = new QueueType;
	Q->Queue = new int[N + 1];
	Q->N = N;
	init(Q);

	int count = 1;
	// push는 1, front는 2, back은 3, size는 4, empty는 5, pop은 6
	for (int i = 1; i <= N; i++) {
		cin >> command;

		if (command == "push") {
			cin >> pushnum;
			push(pushnum, Q);
		}
		else if (command == "front") {
			result[count++] = front(Q);
		}
		else if (command == "pop") {
			result[count++] = pop(Q);
		}
		else if (command == "back") {
			result[count++] = back(Q);
		}
		else if (command == "size") {
			result[count++] = size(Q);
		}
		else if (command == "empty") {
			if (isempty(Q) == true)
				result[count++] = 1;
			else
				result[count++] = 0;
		}
	}

	for (int i = 1; i <= count-1; i++) {
		cout << result[i] << "\n";
	}
}