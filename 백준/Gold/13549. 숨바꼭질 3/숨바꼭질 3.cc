#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
queue<pair<int,int>> q;
unordered_map<int, int> m;

void adj_bfs(int N, int K) {
	
	while (!q.empty()) {
		//cout << "현재 위치 : " << q.front().first << " 초 : " << q.front().second << "\n";
		if (q.front().first <= 100000 && q.front().first >= 0) {

		if ( m.find( 2 * q.front().first ) == m.end()) {
			q.push({ 2 * q.front().first , q.front().second });
			m.insert({2 * q.front().first, q.front().second});
		}
		else { // 만약 이미 있고
			auto a = m.find(2 * q.front().first);
			if (a->second > q.front().second) { // 이미 저장되어 있는 초 보다 지금 넣으려는 값이 더 작다면 교환
				a->second = q.front().second;
			}
		}
		if (m.find(q.front().first -1) == m.end()) {
			q.push({ q.front().first - 1, q.front().second + 1 });
			m.insert({ q.front().first - 1, q.front().second + 1 });
		}
		else {
			auto a = m.find(q.front().first - 1);
			if (a->second > q.front().second + 1) {
				a->second = q.front().second + 1;
			}
		}
		if (m.find(q.front().first + 1) == m.end()) {
			q.push({ q.front().first + 1, q.front().second + 1 });
			m.insert({ q.front().first + 1, q.front().second + 1 });
		}
		else {
			auto a = m.find(q.front().first + 1);
			if (a->second > q.front().second + 1) {
				a->second = q.front().second + 1;
			}
		}
		}
		q.pop(); // 맨앞 제거
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	if (N == K ) {
		cout << 0;
	}
	else {
		q.push({ N, 0 });
		m.insert({ N, 0 });
		adj_bfs(N, K);
		auto a = m.find(K);
		cout << a->second;
	}
}