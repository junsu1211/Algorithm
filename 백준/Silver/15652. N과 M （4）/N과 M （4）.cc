#include <iostream>

using namespace std;
int* printed = new int[8];
int flag = 0;

void Combination(int Idx, int cnt, int N, int M) {
	printed[cnt] = Idx;

	if (cnt == M) {
		for (int t = 2; t <= M; t++) {
			if (printed[t - 1] > printed[t])
				flag = 1;
		}
		if (flag == 0) {
			for (int i = 1; i <= M; i++) {
				cout << printed[i] << " ";
			}
			cout << "\n";
		}
		flag = 0;
		return;
	}

	for (int t = 1; t <= N; t++) {
		Combination(t, cnt + 1, N, M);
	}

}


int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		Combination(i, 1, N, M);
}