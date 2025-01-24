#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n; //계단의 개수

	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int* dp = new int[n + 1];
	bool* flag = new bool[n + 1];

	// i 시점에서 i-2의 계단을 밟앗는가 안밟앗는가에 따라 값이 바뀜
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[n];
}