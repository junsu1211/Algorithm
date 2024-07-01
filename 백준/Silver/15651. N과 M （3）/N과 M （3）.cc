#include <iostream>

using namespace std;
bool* visited = new bool[8];
int* printed = new int[8];

void Combination(int Idx, int cnt, int N, int M) {
	visited[Idx] = true; // 방문
	printed[cnt] = Idx;

	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << printed[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int t = 1; t <= N; t++) {
		Combination(t, cnt + 1, N, M);
	}

}


int main() {
	int N, M;
	cin >> N >> M;

	for(int i=1; i<=N; i++)
		Combination(i, 1, N, M);
}