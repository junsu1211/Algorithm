#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

bool compare(string a, string b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	unordered_set<string> s;
	vector<string> v;
	unordered_map<string, string> m;

	string name;
	string status;
	

	for (int i = 0; i < n; i++) {
		cin >> name >> status;
		if (status == "enter") {
			s.insert(name);
			v.push_back(name); // 벡터에 데이터 저장
		}
		else if (status == "leave") {
			auto it = s.find(name);
			if (it != s.end()) { // 없는 사람을 퇴근시키면 에러
				s.erase(it);
			}
		}
	}
	vector<string> vs(s.begin(), s.end());
	sort(vs.begin(), vs.end(), greater<string>());  // 역순 정렬

	// 출력
	for (const auto& person : vs) {
		cout << person << "\n";
	}

}