#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

//1351
using namespace std;

unordered_map<long long, long long> m;
set<long long> s;

void search(long long N, long long P, long long Q) {
	if (s.find(N) == s.end()) {
		s.insert(N);
	}
	else {
		return;
	}
	if (N <= 1) {
		return;
	}
	search(N / P, P, Q);
	search(N / Q, P, Q);
}

int main() {
	long long N;
	long long P, Q;
	cin >> N >> P >> Q;


	if (N > 0) {
		s.insert(N);
		search(N / P, P, Q);
		search(N / Q, P, Q);

		m.insert({ 0,1 });
		m.insert({ 1,2 });
		long long ans = 0;
		long long a, b;

		for (auto it = s.begin(); it != s.end(); it++) {
			if (m.find(*it) == m.end()) { // map에 데이터가 없으면
				auto at = m.find(*it / P);
				a = at->second;

				auto bt = m.find(*it / Q);
				b = bt->second;

				//cout << "현재 : N: " << *it << " = " << at->first << " " << bt->first << "\n";
				ans = a + b;
				m.insert({ *it, ans });
			}
		}

		auto at = m.find(N / P);
		a = at->second;

		auto bt = m.find(N / Q);
		b = bt->second;

		ans = a + b;
		cout << ans;
	}
	else {
		cout << "1";
	}

}