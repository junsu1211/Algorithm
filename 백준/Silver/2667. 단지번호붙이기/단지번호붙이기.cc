#include <iostream>
#include <algorithm>

using namespace std;

int x, y; //초기 상황
int num;

void dfs(int row, int col, int** map, bool** visited, int* hmnum, int total) {
	visited[row][col] = true; // 방문 완료
	num++;

	if (visited[row][col + 1] == false && map[row][col+1] == 1) { // 방문 안한 곳
		dfs(row, col+1, map, visited, hmnum , total);
	}
	if (visited[row+1][col] == false && map[row+1][col] == 1) { // 방문 안한 곳
		dfs(row+1, col, map, visited, hmnum,  total);
	}
	if (visited[row-1][col] == false && map[row-1][col] == 1) { // 방문 안한 곳
		dfs(row-1, col, map, visited, hmnum, total);
	}
	if (visited[row][col - 1] == false && map[row][col - 1] == 1) { // 방문 안한 곳
		dfs(row, col - 1, map, visited, hmnum, total);
	}
}

int main() {
	int N;
	cin >> N;

	int** map = new int* [N + 1];
	for (int i = 1; i <= N; i++)
		map[i] = new int[N + 1];

	bool** visited = new bool*[N + 2];
	for (int i = 0; i <= N+1; i++)
		visited[i] = new bool[N + 2];
	
	char ch;
	
	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= N; t++) {
			cin >> ch;
			map[i][t] = (int)ch-48;
			visited[i][t] = false;
		}
		visited[i][0] = true;
		visited[0][i] = true;
		visited[i][N + 1] = true;
		visited[N + 1][i] = true;
	}

	int total = 0;
	int* hmnum = new int[550];

	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= N; t++) {

			if ( map[i][t] == 1 && visited[i][t] == false) {
				num = 0;
				dfs(i, t, map, visited, hmnum, total);
				hmnum[total] = num;
				total++;
			}
		}
	}
	
	cout << total << "\n";
	sort(hmnum, hmnum + total);

	for (int i = 0; i < total; i++)
		cout << hmnum[i] << "\n";
}