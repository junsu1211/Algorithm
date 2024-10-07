#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N,M;

	cin >> N >> M;
	string s;
	map<int, string> m;
	map<string, int > ms;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		m.insert({ i,s });
		ms.insert({ s,i });
	}

	string rs;
	vector<string> v;

	for (int i = 0; i < M; i++) {
		cin >> rs;
		if ((rs[0] <= 90 && rs[0] >= 65) || (rs[0] >= 97 && rs[0] <= 122)) {
			//문자이면
			auto a = ms.find(rs);
			v.push_back(to_string(a->second));
		}
		else if (rs[0] >= 48 && rs[0] <= 57) {
			//숫자이면
			int num = stoi(rs);
			v.push_back( m[num] );
		}
	}
	for (int i = 0; i < M; i++) {
		cout << v[i] << "\n";
	}
}