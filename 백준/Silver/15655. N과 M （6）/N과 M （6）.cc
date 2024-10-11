#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int s[9] = { 0 };

void comb(int N, int M, vector<int> v, int depth, int start) {
	s[depth] = v[start];
	if (depth == M) {
		for (int t = 1; t <= depth; t++)
			cout << s[t] << " ";
		cout << "\n";
		return;
	}

	for (int i = start+1; i < v.size(); i++) {
		comb(N, M, v, depth + 1, i);
	}

}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> v;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i <= N - M; i++) {
		comb(N, M, v, 1, i);
	}
}