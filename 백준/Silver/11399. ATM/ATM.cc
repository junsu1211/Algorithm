#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main() {
	int N;
	cin >> N;

	vector<int> v;
	int Pi;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> Pi;
		v.push_back(Pi);
		sum = sum + Pi;
	}

	sort(v.begin(), v.end(), compare);

	int result = 0;

	for (int i = N - 1; i >= 0; i--) {
		result = result + sum;
		sum = sum - v[i];
	}

	cout << result;
}