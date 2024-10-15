#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
queue<pair<int,int>> q;
bool visited[501][501] = { false };

int a[4] = { 1, 0, -1 , 0 };
int b[4] = { 0, 1, 0, -1 };
int counts = 0;
int big = 0;
int result = 0;

void adj_bfs(int** pic, int n, int m, int x, int y) {
	q.push({ x, y });
	visited[q.front().first][q.front().second] = true;

	while (!q.empty()) {
		
		big++;
		//cout << " 현재 : " << q.front().first << " " << q.front().second << "방문\n";
		for (int i = 0; i < 4; i++) { // 상하좌우 검사
			if (pic[q.front().first + a[i]][q.front().second + b[i]] == 1 && visited[q.front().first + a[i]][q.front().second + b[i]] == false) {
				//cout << q.front().first + a[i] << " " << q.front().second + b[i] << "삽입\n";
				q.push({ q.front().first + a[i] , q.front().second + b[i] });
				visited[q.front().first + a[i]][q.front().second + b[i]] = true;
				// 큐에 삽입
				// 방문완료
			}
		}
		
		q.pop();
	}

}
void init(int** pic, int n, int m) {
	for (int i = 0; i <= n+1; i++) {
		for (int t = 0; t <= m+1; t++)
			pic[i][t] = 0;
	}
}
int main() {
	int n, m;
	cin >> n >> m;

	int** pic = new int* [n + 2];
	for (int i = 0; i <= n+1; i++) {
		pic[i] = new int[m + 2];
	}

	init(pic, n, m);
	for (int i = 1; i <= n; i++) {
		for (int t = 1; t <= m; t++) {
			cin >> pic[i][t];
		}
	}
	

	for (int i = 1; i <= n; i++) {
		for (int t = 1; t <= m; t++) {

			if (visited[i][t] == false && pic[i][t] == 1) {
				//cout << i << " " << t << "실행\n";
				adj_bfs(pic, n, m, i, t);
				counts++;
				result = max(result, big);
				big = 0;
			}

		}
	}
	cout << counts << "\n" << result;
}