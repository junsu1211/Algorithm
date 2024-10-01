#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int N;
	cin >> N;

	int num;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	int right = 0;
	int Idx;
	int* result = new int[N+1];

	int flag = 0;
	vector<pair<int,int>> s;
	s.push_back(pair<int, int>(v[v.size() - 1], v.size()));

	for (int i = v.size() - 2; i >= 0; i--) {

		while (v[i] > s.back().first) {
			result[s.back().second] = i + 1;
			s.pop_back();
			if (s.size() == 0)
				break;
		}

		s.push_back(pair<int,int>(v[i], i + 1));

	}

	while (!s.empty()) {
		result[s.back().second]= 0;
		s.pop_back();
	}

	for (int i = 1; i <= v.size(); i++)
		cout << result[i] << " ";

}