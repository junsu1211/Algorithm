#include <iostream> // cpp
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int A[1001];
int dpGreater[1001], dpLess[1001]; // 증가하는 수열, 감소하는 수열

void INPUT()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
}

void SOLVE()
{
	// 초기 작업
	dpGreater[0] = 1; dpLess[n - 1] = 1;

	// Bottom Up Dynamic Programming
	for (int i = 1; i < n; i++)
	{
		int maxDP_greater = 1; int maxDP_less = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{// dpGreater
				maxDP_greater = max(maxDP_greater, dpGreater[j] + 1);
			}
			if (A[n - 1 - i] > A[n - 1 - j])
			{// dpLess
				maxDP_less = max(maxDP_less, dpLess[n - 1 - j] + 1);
			}
		}
		dpGreater[i] = maxDP_greater;
		dpLess[n - 1 - i] = maxDP_less;
	}

	// i번째 원소에서의 (증가하는 수열) + (감소하는 수열)의 최대값 찾기
	int ans = 1;
	for (int i = 0; i < n; i++)
		ans = max(ans, dpGreater[i] + dpLess[i]);

	// 기준 원소 중복 빼주기 (S_k)
	cout << ans - 1;
}

int main()
{
	INPUT();

	SOLVE();
}