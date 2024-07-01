#include <iostream>
#include <algorithm>

using namespace std;
int* printed = new int[9];
int flag = 0;
bool* visited = new bool[10001];

void Combination(int Idx, int cnt, int N, int M, int* array) {
	printed[cnt] = Idx;
	visited[Idx] = true;

	if (cnt == M) {
		for (int r = 2; r <= M; r++) {
			if (printed[r] == printed[1])
				flag = 1;
		}
		if (flag == 0) {
			for (int t = 1; t <= M; t++)
				cout << printed[t] << " ";
			cout << "\n";
			visited[Idx] = false;
		}
		flag = 0;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[array[i]] != true) {
			Combination(array[i], cnt + 1, N, M, array);
			visited[array[i]] = false;
		}
	}
}

void reset() {
	for (int i = 1; i <= 10001; i++)
		visited[i] = false;
}

int main() {
	int N, M;

	cin >> N >> M;
	int* array = new int[N+1];

	for (int i = 1; i <= N; i++)
		cin >> array[i];

	sort(array, array + N+1);

	for (int i = 1; i <= N; i++) {
		Combination(array[i], 1, N, M, array);
		reset();
	}

}