#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> card;
	int cd;
	unordered_map<int, int> m;

	for (int i = 0; i < N; i++) {
		cin >> cd;
		auto it = m.find(cd);
		if (it == m.end()) { //map에 없으면
			m.insert({ cd, 1 });
		}
		else { // 있으면
			it->second++;
		}
	}

	int M;
	cin >> M;

	vector<int> find;
	int fd;
	for (int i = 0; i < M; i++) {
		cin >> fd;
		find.push_back(fd);
	}

	for (int i = 0; i < M; i++) {
		auto it = m.find(find[i]);
		if (it == m.end()) {
			cout << "0 ";
		}
		else {
			cout << it->second << " ";
		}
	}
}