#include <iostream>

using namespace std;

int min(int A, int B) {
	if (A < B)
		return A;
	else
		return B;
}

int main() {
	int N; // 수빈이의 현재 위치
	int K; // 동생의 위치
	int dp[200010];

	cin >> N >> K;
	int flag = 1;

	if (N == 0 && K != 0) {
		flag = 0;
		N = N + 1;
		for (int i = 1; i <= K; i++) {

			if (i <= N) {
				dp[i] = N - i;
				dp[i * 2] = dp[i] + 1;
				//cout << "dp[" << i << "] 는 " << N - i << " 입니다..\n";
			}
			else {
				if (i % 2 == 0) { //i 가 짝수인 경우
					dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
					dp[i * 2] = dp[i] + 1;
					//cout << "dp[" << i << "] 는 " << dp[i] << " 입니다..\n";
				}
				else { // i가 홀수인 경우
					dp[i] = min(dp[i - 1] + 1, dp[i + 1] + 1);
					dp[i * 2] = dp[i] + 1;
					//cout << "dp[" << i << "] 는 " << dp[i] << " 입니다..\n";
				}
			}
		}
		cout << dp[K] + 1;
	}
	else if (N != 0 && K == 0) {
		cout << N - K;
	}
	else if (N == 0 && K == 0) {
		cout << 0;
	}
	else if (N != 0 && K != 0) {
		for (int i = 1; i <= K; i++) {

			if (i <= N) {
				dp[i] = N - i;
				dp[i * 2] = dp[i] + 1;
				//cout << "dp[" << i << "] 는 " << N - i << " 입니다..\n";
			}
			else {
				if (i % 2 == 0) { //i 가 짝수인 경우
					dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
					dp[i * 2] = dp[i] + 1;
					//cout << "dp[" << i << "] 는 " << dp[i] << " 입니다..\n";
				}
				else { // i가 홀수인 경우
					dp[i] = min(dp[i - 1] + 1, dp[i + 1] + 1);
					dp[i * 2] = dp[i] + 1;
					//cout << "dp[" << i << "] 는 " << dp[i] << " 입니다..\n";
				}
			}
		}
		cout << dp[K];
	}
	
}