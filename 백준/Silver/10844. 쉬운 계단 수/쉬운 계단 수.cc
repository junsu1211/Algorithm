#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int dp[102][11];

	dp[1][0] = 0;

	for (int i = 0; i <= 100; i++)
		for (int t = 0; t <= 9; t++)
			dp[i][t] = 0;

	for (int t = 1; t <= 9; t++)
		dp[1][t]++;


	for (int i = 2; i <= N; i++) {

		dp[i][0] = dp[i - 1][1] % 1000000000; // i자리수의 0의 개수는 i-1자리수의 1의 개수와 같음
		dp[i][9] = dp[i - 1][8] % 1000000000; // i자리수의 9의 개수는 i-1자리수의 8의 개수와 같음
		for (int t = 1; t <= 8; t++) { // i자리수의 t의 개수
			dp[i][t] = ( dp[i - 1][t + 1] + dp[i - 1][t - 1] ) % 1000000000;
		}	
	}
	


	long long sum=0;

	for (int w = 0; w <= 9; w++) {
		sum += dp[N][w];
	}
	cout << sum % 1000000000;
}