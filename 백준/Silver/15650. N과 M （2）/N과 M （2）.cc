#include <iostream>

using namespace std;
bool* visited = new bool[9];
int* print = new int[9];
int flag = 0;

void Permutation(int Idx, int cnt, int N, int M, int* array) {

	for (int t = 1; t <= M; t++) { // 앞에서부터 방문하지 않은 인덱스를 발견하면 프린트에 넣고 종료

		if (visited[t] != true) {
			print[cnt] = Idx; // cnt 는 순서
			visited[Idx] = true; // 방문 완료
			break;
		}

	}

	if (cnt == M) { // M이 Depth잖아

		for (int w = 1; w < M; w++) {
			for (int r = w + 1; r <= M; r++) {
				if (print[w] >= print[r])
					flag = 1;
			}
		}

		if (flag == 0) {
			for (int q = 1; q <= M; q++) {
				cout << print[q] << " ";
			}
			cout << "\n";
		}
		flag = 0;
		visited[Idx] = false; //  방문 초기화 
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] != true) { // 방문하지 않은 곳만
			Permutation(i, cnt + 1, N, M, array);
			visited[Idx] = false;
		}
	}

}

int main() {
	int N, M;
	cin >> N >> M;

	int* array = new int[M + 1];
	for (int i = 1; i <= M; i++)
		array[i] = i;

	if (M == 1) {
		for (int g = 1; g <= N; g++) {
			cout << g << "\n";
		}
	}
	else {
		for (int t = 1; t <= N; t++) {
			Permutation(t, 1, N, M, array);
		}
	}
}