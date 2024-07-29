#include <iostream>

using namespace std;

int maxd(int A, int B) {
	if (A > B)
		return A;
	else
		return B;
}

int main() {
	int T;
	cin >> T;
	int* array = new int[T + 1];
	int maxs = 0;

	for (int i = 1; i <= T; i++) {
		cin >> array[i];
		maxs = maxd(maxs, array[i]);
	}
	int n;
	int dp[10000];
	int noto[10000];

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	noto[3] = 1;
	dp[4] = 4;
	noto[4] = 1;
	noto[5] = 1;

	for (int i = 5; i <= maxs; i++) {
		if (i % 3 == 0) { // 3의 배수인 경우
			noto[i] = noto[i - 2] + 1;
			dp[i] = dp[i - 1] + noto[i];
		}
		else {
			noto[i] = noto[i - 2];
			dp[i] = dp[i - 1] + noto[i];
		}
	}
	
	for (int i = 1; i <= T; i++) {
		cout << dp[array[i]] << "\n";


	}
}