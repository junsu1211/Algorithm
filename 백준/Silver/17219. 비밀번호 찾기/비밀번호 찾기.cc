#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N, M; // N : 저장된 사이트의 수 , M : 찾는 사이트 수
	cin >> N >> M;

	unordered_map<string,string> m;
	string a, b;

	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		m.insert({ a, b });
	}

	string input;
	vector<string> v;

	for (int t = 1; t <= M; t++) {
		cin >> input;
		auto it = m.find(input);
		v.push_back(it->second);
	}

	for (int at = 0; at < v.size(); at++) {
		cout << v[at] << "\n";
	}
}