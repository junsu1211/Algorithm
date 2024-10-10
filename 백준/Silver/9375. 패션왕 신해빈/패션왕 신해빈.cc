#include<iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int TC = 0;
	cin >> TC;
	string name, kind;
	int sum = 1;
	int* result = new int[TC + 1];

	for (int i = 0; i < TC; i++) {
		int n;
		sum = 1;
		cin >> n; // 해빈이가 가진 의상의 수
		unordered_map<string, int> m;

		for (int z = 0; z < n; z++) {
			cin >> name >> kind;
			auto a = m.find(kind);
			if (a == m.end()) {
				// 다른 종류가 들어오면
				m.insert({kind, 1});
			}
			else {
				// 같은 종류가 들어오면
				a->second++; //개수만 증가
			}
		}

		// 각 의상의 개수 +1 을 다 곱하고 알몸인 경우 -1
		for (auto t = m.begin(); t != m.end(); t++) {
			sum = sum * (t->second + 1);
		}
		result[i] = sum - 1;

	}
	for (int i = 0; i < TC; i++)
		std::cout << result[i] << "\n";
}