#include <iostream>

using namespace std;

int max(int A, int B, int C) {
	if (A >= B && A >= C)
		return A;
	else if (B > A && B > C) {
		return B;
	}
	else if (C > A && C >= B) {
		return C;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	int** miro = new int* [N + 1];
	for (int i = 1; i <= N; i++)
		miro[i] = new int[M + 1];

	for (int r = 1; r <= N; r++) {
		for (int q = 1; q <= M; q++)
			cin >> miro[r][q];
	}

	int** dp = new int* [N + 1];
	for (int t = 1; t <= N; t++)
		dp[t] = new int[M + 1];
	
	
	for (int i = 1; i <= N; i++)
		dp[i][0] = 0;

	for (int q = 1; q <= N; q++) {
		for (int w = 1; w <= M; w++) {

			if (q == 1) {
				dp[q][w] = dp[q][w - 1] + miro[q][w];
			}
			else {
				dp[q][w] = max(dp[q - 1][w], dp[q - 1][w - 1], dp[q][w - 1]) + miro[q][w];
			}

			//cout << "현재 : dp[" << q << "][" << w << "]는 " << dp[q][w] << "이다 \n";
		}
	}

	cout << dp[N][M];
}