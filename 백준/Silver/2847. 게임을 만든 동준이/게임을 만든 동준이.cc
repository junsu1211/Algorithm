#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; // 레벨 수
	cin >> N;

	vector<int> v;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	int res = v[N - 1];
	int count = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (res <= v[i]) {
			count = count + ( v[i] - (res - 1) );
			v[i] = res - 1;
		}
		res = v[i];
	}
	cout << count;
}