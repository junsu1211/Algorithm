#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	long long* dp = new long long[N + 8];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 11;
	dp[5] = 0;

	for (int i = 6; i <= N; i++) {
		if (i % 2 == 0) {
			dp[i] = 4 * dp[i - 2] - 1 * dp[i - 4];
		}
		else {
			dp[i] = 0;
		}
	}

	cout << dp[N];
}