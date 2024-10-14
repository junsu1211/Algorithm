#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long summ = 0;
int counts = 0;

void show(vector<long long> v, int S, int cnt) {
	summ = summ + v[cnt];
	//cout << "현재 sum : " << summ << " " << cnt << "\n";
	if (summ == S) {
		counts++;
	}
	
	for (int i = cnt + 1; i < v.size(); i++) {
		show(v, S, i);
		summ = summ - v[i];
	}

}

int main() {
	int N, S;
	cin >> N >> S;

	vector < long long > v;
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		show(v, S, i);
		summ = 0;
	}

	cout << counts;
}