#include <iostream>

using namespace std;

int minimum(int A, int B) { // 더 작은 값 반환
	if (A < B)
		return A;
	else if (A > B)
		return B;
	else if (A == B) {
		return A;
	}
}

void dpf(int N, int* dp) { 
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0) {
			dp[i] = minimum(dp[i / 3] + 1, dp[i]);
		}
		if (i % 2 == 0) {
			dp[i] = minimum(dp[i], dp[i / 2] + 1);
		}

	}

	cout << dp[N];
	
}
	


int main() {
	int N;
	cin >> N;

	int dp[N+1];
	
	dpf(N, dp);


}