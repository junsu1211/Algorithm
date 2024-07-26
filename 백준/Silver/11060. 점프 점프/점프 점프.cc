#include <iostream>
#include <cmath>

using namespace std;

int main() {
	

	int N;
	cin >> N;

	int* dp = new int[N + 1];
	dp[0] = -1;

	int* array = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> array[i];
		dp[i] = -1;
	}

	for (int i = 2; i <= N; i++) {

		for (int k = 1; k <=i-1 ; k++) {

			if (k + array[k] >= i) {
				dp[i] = k;
				break;
			}

		}

	}
	int count = N;
	int result = 0;

	while (count != 1) {
		if (dp[count] == -1) {
			result = -1;
			break;
		}
		count = dp[count];
		result++;
	}

	cout << result;
}