#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	map<string, int> m;

	int K, L;
	cin >> K >> L;
	string s;

	for (int i = 0; i < L; i++) {
		cin >> s;
		auto a = m.find(s);
		if (a == m.end()) { // 중복 검사 문제 없음
			m.insert({ s,i+1 });
			//cout << i + 1 << "에 " << s << "삽입" << "\n";
		}
		else if(a != m.end()) { // 중복 발견
			//cout << a->second << "에 " << a->first << "삭제" << "\n";
			m.erase(a); // 원래 it 제거
			m.insert({ s,i+1 }); // 맨 뒤로 push
			//cout << i + 1 << "에 " << s << "삽입" << "\n";
		}
	}

	vector<pair<string, int>> v(m.begin(), m.end()); // 벡터 변환
	sort(v.begin(), v.end(), compare);

	int count = 0;
	for (auto i = v.begin(); i !=v.end(); i++) {
		count++;
		cout << i->first << "\n";
		if (count == K) {
			break;
		}
	}
}