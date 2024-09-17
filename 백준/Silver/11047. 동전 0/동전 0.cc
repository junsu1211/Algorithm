#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int* coin = new int[N + 1];
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	int mIdx = 0;
	int mval = 1;

	int goal = 0;
	int count = 0;

	if (K >= coin[N - 1]) {
		mval = coin[N - 1];
		mIdx = N - 1;
	}
	else {
		for (int i = N - 1; i >= 1; i--) {
			if (K < coin[i] && K >= coin[i-1]) {
				mval = coin[i - 1];
				mIdx = i - 1;
			}
		}
	}


	while (K != 0) {

		count = K / mval;
		goal = goal + count;
		K = K - (count * mval);

		mIdx--;
		mval = coin[mIdx];
	}

	cout << goal;

}