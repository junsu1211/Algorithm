#include <iostream>
#define MAX_SIZE 1025

using namespace std;

typedef struct {
	int adj_mat[MAX_SIZE][MAX_SIZE];
}Table;

typedef struct {
	int sum_mat[MAX_SIZE][MAX_SIZE];
}Sum;

typedef struct {
	int x1, x2, y1, y2;
}Width;

void init(Width* w) {
	w->x1 = 0;
	w->x2 = 0;
	w->y1 = 0;
	w->y2 = 0;
}

int main() {
	int N, M;
	cin >> N >> M; // N은 표의 크기, M은 합을 구해야하는 횟수
	Table* T = (Table*)malloc(sizeof(Table));

	int* array = (int*)malloc(sizeof(int) * M); // 결과를 저장할 배열
	int sum = 0;
	Sum* S = (Sum*)malloc(sizeof(Sum));

	for (int i = 1; i <= N; i++) { // O(n) -> 10^3
		sum = 0;
		for (int t = 1; t <= N; t++) {
			cin >> T->adj_mat[i][t];
			sum = sum + T->adj_mat[i][t];
			S->sum_mat[i][t] = sum;
		}
	}
	Width* w = (Width*)malloc(sizeof(Width));
	init(w);
	int flag = 1;

	int summary;
	// 미리 전부 탐색해서 정보를 저장해놓을까?
	for (int i = 1; i <= M; i++) {
		summary = 0;
		cin >> w->x1 >> w->y1 >> w->x2 >> w->y2;

		if (w->y1 == 1 && w->y2 != 1) { // 시작점의 y좌표만 1인 경우
			for (int q = w->x1; q <= w->x2; q++) {
				summary = summary + S->sum_mat[q][w->y2];
			}
		}
		else if (w->y1 == 1 && w->y2 == 1) { // 둘다 y좌표가 1인 경우
			for (int q = w->x1; q <= w->x2; q++) {
				summary = summary + S->sum_mat[q][1];
			}
		}
		else { // 둘다 y좌표가 1이 아닌 경우
			for (int q = w->x1; q <= w->x2; q++) {
				summary = summary + (S->sum_mat[q][w->y2] - S->sum_mat[q][w->y1 - 1]);
			}
		}
		array[flag] = summary;
		flag++;
	}
	for (int i = 1; i < flag; i++) {
		cout << array[i] << "\n";
	}
	/*for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= N; t++) {
			cout << S->sum_mat[i][t] << endl;
		}
	}*/









	
}