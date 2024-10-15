#include <iostream>
#include <queue>

using namespace std;
queue<pair<int, int>> q;

int a[4] = { 0 , 1, 0, - 1 };
int b[4] = { 1, 0, -1, 0 };
int date = 0;

void init(int** box, int N, int M) {
	for (int i = 0; i <= N+1; i++) {
		for (int t = 0; t <= M+1; t++) {
			box[i][t] = -1;
		}
	}
}

void adj_bfs(int N, int M, int** box) {

	while (!q.empty()) {
		
		for (int i = 0; i < 4; i++) {
			if (box[q.front().first + a[i]][q.front().second + b[i]] == 0) {
				//익혀야함
				q.push({ q.front().first + a[i], q.front().second + b[i] });
				box[q.front().first + a[i]][q.front().second + b[i]] = box[q.front().first][q.front().second] + 1;
			}
		}
		q.pop();
	}
	
}

int main() {
	int M, N;

	cin >> M >> N;
	int** box = new int* [N + 2];
	for (int i = 0; i <= N+1; i++) {
		box[i] = new int[M + 2];
	}

	init(box, N, M);

	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= M; t++) {
			cin >> box[i][t]; // 토마토 입력
			if(box[i][t] == 1) {
				q.push({i,t }); // 시작점 
			}
		}
	}
	
	adj_bfs(N, M, box);
	int maxs = box[1][1];
	int flag = 0;

	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= M; t++) {
			if (box[i][t] == 0) {
				flag = 1;
			}
			maxs = max(maxs, box[i][t]);
		}
	}
	if (flag == 0) {
		cout << maxs - 1;
	}
	else {
		cout << -1;
	}
}