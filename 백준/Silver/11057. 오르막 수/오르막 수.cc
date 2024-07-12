#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int* dp = new int[10];

	for (int q = 0; q <= 9; q++) {
		dp[q] = 1;
	}
	int sum = 0;
	for (int i = 2; i <= N; i++) {
		for (int r = 0; r <= 9; r++) {
			for (int c = r; c <= 9; c++) {
				sum += dp[c]%10007;
				dp[r] = sum%10007;
			}
			sum = 0;
			//cout << "현재 N =" << i << " : dp[" << r << "] : " << dp[r] << endl;
		}
		dp[9] = 1;
	}


	for (int i = 0; i <= 9; i++) {
		sum += dp[i]%10007;
	}

	cout << sum%10007;
}