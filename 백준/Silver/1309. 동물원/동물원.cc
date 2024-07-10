#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	
	int* dp = new int[N + 1];
	dp[1] = 3;
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i + 1] = 2 *( dp[i]%9901 ) + ( dp[i-1]%9901 );
	}

	cout << dp[N] % 9901;
}