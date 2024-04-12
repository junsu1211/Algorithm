#include <iostream>
#define MAX_SIZE 51
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct {
	int adj_mat[MAX_SIZE][MAX_SIZE];
}Table;

int visited[MAX_SIZE][MAX_SIZE] = { FALSE };

void init(Table* t){
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int w = 0; w < MAX_SIZE; w++) {
			t->adj_mat[i][w] = FALSE;
			visited[i][w] = FALSE;
		}
	}
}

void search(Table* t, int w, int c, int N, int M) {
	visited[w][c] = TRUE; // 방문완료 w는 행 c는 열
	//cout << w << "행" << c << "열 방문 완료" << endl;
	if (w < 0 || c < 0 || w > N || c > M) { // 범위 초과의 경우
		return;
	}
	if (w == 0 && c == 0) { // 행과 열 0인 경우 (  꼭짓점  )
		if (t->adj_mat[w + 1][c] == 1 && visited[w + 1][c] != TRUE) { 
			search(t, w + 1, c, N, M); // 남쪽 탐색
		}
		if (t->adj_mat[w][c + 1] && visited[w][c + 1] != TRUE) { //동쪽 탐색
			search(t, w, c + 1, N, M);
		}
		return;
	}
	else if (w == 0 && c == M - 1) { // 행이 0 열이 M인 경우 ( 꼭짓점 )
		if (t->adj_mat[w + 1][c] == 1 && visited[w + 1][c] != TRUE) {
			search(t, w + 1, c, N, M); //남쪽 탐색
		}
		if (t->adj_mat[w][c - 1] == 1 && visited[w][c - 1] != TRUE) {
			search(t, w, c - 1, N, M); // 서쪽 탐색
		}
		return;
	}
	else if (w == N - 1 && c == 0) { // 열이 0 행이 N인 경우 ( 꼭짓점 )
		if (t->adj_mat[w - 1][c] == 1 && visited[w - 1][c] != TRUE) {
			search(t, w - 1, c, N, M); // 북쪽 탐색
		}
		if (t->adj_mat[w][c + 1] && visited[w][c + 1] != TRUE) {
			search(t, w, c + 1, N, M);  //동쪽 탐색
		}
		return;
	}
	else if (w == N - 1 && c == M - 1) { // 행과 열이 모두 끝인 경우 ( 꼭짓점 )
		if (t->adj_mat[w][c - 1] == 1 && visited[w][c - 1] != TRUE) {
			search(t, w, c - 1, N, M); // 서쪽 탐색
		}
		if (t->adj_mat[w - 1][c] == 1 && visited[w - 1][c] != TRUE) {
			search(t, w - 1, c, N, M); // 북쪽 탐색
		}
		return;
	}
	else if (w == 0 && c != M - 1 && c != 0) { // 행은 0이지만 열이 0또는 M이 아닌 경우
		if (t->adj_mat[w + 1][c] == 1 && visited[w + 1][c] != TRUE) {
			search(t, w + 1, c, N, M); //남쪽 탐색
		}
		if (t->adj_mat[w][c - 1] == 1 && visited[w][c - 1] != TRUE) {
			search(t, w, c - 1, N, M); // 서쪽 탐색
		}
		if (t->adj_mat[w][c + 1] && visited[w][c + 1] != TRUE) {
			search(t, w, c + 1, N, M);  //동쪽 탐색
		}
		return;
	}
	else if (w == N - 1 && c != 0 && c != M - 1) { // 행은 N이지만 열이 0또는 M 이 아닌 경우
		if (t->adj_mat[w - 1][c] == 1 && visited[w - 1][c] != TRUE) {
			search(t, w - 1, c, N, M); // 북쪽 탐색
		}
		if (t->adj_mat[w][c - 1] == 1 && visited[w][c - 1] != TRUE) {
			search(t, w, c - 1, N, M); // 서쪽 탐색
		}
		if (t->adj_mat[w][c + 1] && visited[w][c + 1] != TRUE) {
			search(t, w, c + 1, N, M);  //동쪽 탐색
		}
		return;
	}
	
	else if (c == 0 && w != N - 1 && w != 0) { // 열이 0이지만 행이 0 또는 N이 아닌 경우
		if (t->adj_mat[w - 1][c] == 1 && visited[w - 1][c] != TRUE) {
			search(t, w - 1, c, N, M); // 북쪽 탐색
		}
		if (t->adj_mat[w + 1][c] == 1 && visited[w + 1][c] != TRUE) {
			search(t, w + 1, c, N, M); //남쪽 탐색
		}
		if (t->adj_mat[w][c + 1] && visited[w][c + 1] != TRUE) {
			search(t, w, c + 1, N, M);  //동쪽 탐색
		}
		return;
	}
	else if (c == M - 1 && w !=0 && w != N) { // 열이 M이지만 행이 0또는 N이 아닌 경우
		if (t->adj_mat[w - 1][c] == 1 && visited[w - 1][c] != TRUE) {
			search(t, w - 1, c, N, M); // 북쪽 탐색
		}
		if (t->adj_mat[w + 1][c] == 1 && visited[w + 1][c] != TRUE) {
			search(t, w + 1, c, N, M); //남쪽 탐색
		}
		if (t->adj_mat[w][c - 1] == 1 && visited[w][c - 1] != TRUE) {
			search(t, w, c - 1, N, M); // 서쪽 탐색
		}
		return;
	}
	else { // 테두리 이외의 모든 점
		if (t->adj_mat[w][c + 1] && visited[w][c + 1] != TRUE) {
			search(t, w, c + 1, N, M);  //동쪽 탐색
		}
		if (t->adj_mat[w - 1][c] == 1 && visited[w - 1][c] != TRUE) {
			search(t, w - 1, c, N, M); // 북쪽 탐색
		}
		if (t->adj_mat[w + 1][c] == 1 && visited[w + 1][c] != TRUE) {
			search(t, w + 1, c, N, M); //남쪽 탐색
		}
		if (t->adj_mat[w][c - 1] == 1 && visited[w][c - 1] != TRUE) {
			search(t, w, c - 1, N, M); // 서쪽 탐색
		}
		return;
	}
}
int main() {
	int X, Y;
	int T; // 테스트 케이스의 개수
	cin >> T;

	int* count = (int*)malloc(sizeof(int) * MAX_SIZE); // 테스트 케이스 개수만큼
	
	int flag = 0;
	for (int i = 1; i <= T; i++) {
		int tag = 0;
		int M = 0;
		int N = 0;
		int K;
		cin >> M >> N >> K; //M은 가로길이 N은 세로길이이다.

		Table* t = (Table*)malloc(sizeof(Table));
		init(t); // 초기화

		for (int q = 1; q <= K; q++) {
			cin >> X >> Y;
			t->adj_mat[Y][X] = TRUE;
		}

		/*for (int w = 0; w < N; w++) {
			for (int c = 0; c < M; c++) {
				cout << t->adj_mat[w][c];
			}
			cout << endl;
		}*/

		for (int w = 0; w < N; w++) {
			for (int c = 0; c < M; c++) {
				if (t->adj_mat[w][c] == TRUE && visited[w][c] != TRUE) {
					tag++;
					search(t, w, c, N, M);
					//cout << "다음 검색" << endl;
				}
			}
		}
		count[flag] = tag;
		flag++;
		free(t); // 메모리 해제
	}

	for (int z = 0; z < T; z++) {
		cout << count[z] << "\n";
	}

}