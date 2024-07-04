#include <iostream>

using namespace std;

void dpf(int n,int* dp) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1]%10007 + dp[i - 2]%10007;
	}

	cout << dp[n]%10007;
}


int main() {
	int n;
	cin >> n;

	int* dp = new int[n+1];

	dpf(n,dp);

}