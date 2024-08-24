#include <iostream>

using namespace std;

int main() {
	int H, W, N, M; // H는 세로 , W는 가로, N은 세로, M은 가로
	cin >> H >> W >> N >> M;

	bool* row = new bool[W + 1];

	// 가로행 계산
	int count = 0;
	for (int i = 1; i <= W; i=i+M+1) {
		count++;
		row[i] = true;
	}

	int colcnt = 0;
	for (int i = 1; i <= H; i=i+N+1) {
		colcnt++;
	}

	cout << count * colcnt;

}