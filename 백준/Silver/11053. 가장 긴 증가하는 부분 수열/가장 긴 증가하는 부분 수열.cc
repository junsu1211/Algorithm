#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[1001] = { 0 };
	int dp[1001] = { 0 };

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int tmpMAX = 0;

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
			else {
				tmpMAX = max(tmpMAX, dp[j]);
			}
		}
		tmpMAX = max(tmpMAX, dp[i]);
		//dp[i] = tmpMAX;
	}

	cout << tmpMAX;

	return 0;
}

 