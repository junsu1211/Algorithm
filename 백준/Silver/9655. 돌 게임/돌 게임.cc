#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int* dp = new int[7];
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 0;
	dp[5] = 1;
	dp[6] = 0;

	if (N <= 6) {
		if (dp[N] == 1) {
			cout << "SK";
		}
		else {
			cout << "CY";
		}
	}
	else {
		if (dp[N % 6] == 1)
			cout << "SK";
		else
			cout << "CY";
	}
}