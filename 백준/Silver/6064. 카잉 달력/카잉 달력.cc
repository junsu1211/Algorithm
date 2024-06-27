#include <iostream>

using namespace std;

int count(int M, int N, int x, int y, int* result) {
	int A=0;
	int i = 0;
	while (A <= M*N) {
		A = M*i + x;
		i++;
		// 이때 A를 N으로 나눈게 y이면 되지않나?
		if (A % N == y%N)
			return A;
	}
	return -1;
}


int main() {
	int T; // 테스트 케이스 수
	cin >> T;
	int M, N, x, y;
	int* result = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;
		result[i] = count(M, N, x, y, result);
	}

	for (int q = 0; q < T; q++)
		cout << result[q] << "\n";

}