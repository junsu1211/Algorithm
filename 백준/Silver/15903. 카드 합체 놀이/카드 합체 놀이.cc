#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;
	vector<long long> v;
	int cd;

	for (int i = 0; i < n; i++) {
		cin >> cd;
		v.push_back(cd);
	}

	sort(v.begin(), v.end());
	
	long long sum = 0;
	for (int i = 0; i < m; i++) {

		sum = v[0] + v[1];
		v[0] = sum;
		v[1] = sum;
		sum = 0;
		sort(v.begin(), v.end());
	}

	long long result = 0;
	for (int i = 0; i < v.size(); i++) {
		result = result + v[i];
	}
	cout << result;
}