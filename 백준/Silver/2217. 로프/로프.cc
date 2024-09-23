#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v;
	int line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		v.push_back(line);
	}
	sort(v.begin(), v.end());
	int maxs = 0;

	for (int i = N - 1; i >= 0; i--) {
		maxs = max( v[i]*(N-i), maxs);
	}
	cout << maxs;

	
}