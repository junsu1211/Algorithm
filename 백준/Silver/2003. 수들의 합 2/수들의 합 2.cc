#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;
	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		v.push_back(input);
	}

	int left=0 ,right = 0;
	int sum = v[0];
	int cnt = 0;

	while (1) {

		if (sum < M) {
			right++;
		}
		else if ( sum > M) {
			left++;
		}
		else if (sum == M) {
			cnt++;
			right++;
		}
		if (right == N)
			break;

		sum = 0;
		for (int i = left; i <= right; i++) {
			sum += v[i];
		}

	}

	cout << cnt;
}