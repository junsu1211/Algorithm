#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ars[9] = { 0 };

void show(vector<int> v, int N, int M, int depth, int cnt) {

	ars[depth] = v[cnt];

	if (depth == M) {
		for (int i = 1; i <= M; i++)
			cout << ars[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < v.size() - cnt; i++) {
		show(v, N, M, depth + 1, cnt + i);
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;
	int t;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		show(v, N, M, 1, i);
	}
}