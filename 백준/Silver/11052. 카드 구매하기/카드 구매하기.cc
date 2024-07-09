#include <iostream>

using namespace std;

int bigger(int A, int B) {
	if (A > B) {
		return A;
	}
	else {
		return B;
	}
}


int main() {
	int N;
	cin >> N;

	int* Price = new int[N + 1];
	for (int i = 1; i <= N; i++)
		cin >> Price[i];

	int* dp = new int [N + 1];

	dp[0] = Price[0] = 0;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= r; c++) {
			dp[r] = bigger(dp[r],dp[r - c] + Price[c]);
		}
	}

	cout << dp[N];
}