#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> v;
	int ipt = 0;

	for (int i = 0; i < N; i++) {
		cin >> ipt;
		v.push_back(ipt);
	}

	int left = 0, right = 0;
	int limit = 1;
	int len = 1;
	int result = 0;
	int big = 0;
	unordered_map<int, int> m;

	//5 5 
	while (1) {
		if (limit <= K && right == N) {
			break;
		}

		if (limit <= K) {
			auto it = m.find(v[right]);

			if (it == m.end()) { // 존재하지 않는 
				m.insert( pair<int,int>(v[right], 1));
			}
			else {

				it->second++;
				limit = max(limit, it->second);
				if (it->second == limit) {
					big = it->first;
				}
			}
			if (limit <= K) {
				result = max(result, right - left + 1);
			}
			right++;
		}
		else if (limit > K) {
			auto it = m.find(v[left]);
			it->second--;
			if (it->first == big) { // 현재 limit값을 넘는 녀석이 삭제되면
				limit--;
			}
			
			left++;
		}
	}
	cout << result;
}