#include <iostream>

using namespace std;

void dfs(bool** visited, int** array, int N, int startx, int starty) {
	visited[startx][starty] = false; // 탐색 완료 
	
	if (visited[startx + 1][starty] != false) {
		dfs(visited, array, N, startx+1, starty); // 우측 탐색 
	}
	if (visited[startx][starty + 1] != false) {
		dfs(visited, array, N, startx, starty + 1); // 아래 탐색
	}
	if (visited[startx - 1][starty] != false) {
		dfs(visited, array, N, startx - 1, starty);// 좌측 탐색
	}
	if (visited[startx][starty - 1] != false) {
		dfs(visited, array, N, startx, starty - 1); // 위 탐색
	}


}

int main() {
	int N;
	cin >> N;

	int** array = new int* [N + 2];
	bool** visited = new bool* [N + 2];

	for (int i = 0; i <= N+1; i++) {
		array[i] = new int[N + 2];
		visited[i] = new bool[N + 2];
	}


	visited[0][0] = false;
	visited[N + 1][N + 1] = false;
	int minheight = 0;
	int maxheight = 0;
	int count = 0;

	for (int i = 1; i <= N; i++) {
		visited[0][i] = false;
		visited[i][0] = false;
		visited[N + 1][i] = false;
		visited[i][N + 1] = false;
		for (int t = 1; t <= N; t++) {
			cin >> array[i][t];
			if (array[i][t] > maxheight) // 최고 높이
				maxheight = array[i][t];
		}
	}
	int result = 0;
	while (minheight <= maxheight) {

		count = 0;
		for (int i = 1; i <= N; i++) {
			for (int t = 1; t <= N; t++) {
				if (array[i][t] <= minheight)
					visited[i][t] = false; //침수
				else {
					visited[i][t] = true; // 침수X
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int t = 1; t <= N; t++) {
				if (visited[i][t] != false) { // 침수되지 않은곳을 발견하면
					dfs(visited, array, N, i, t); // 탐색 시작
					count++;
				}
			}
		}

		result = max(count, result);
		minheight++;
	}

	cout << result;
}