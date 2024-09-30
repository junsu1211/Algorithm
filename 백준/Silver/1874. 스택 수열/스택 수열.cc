#include <iostream>
#include <vector>
#include <stack>
#include <string>

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

	stack<int> s;
	s.push(0);
	int Idx = 0;
	int cnt = 1;
	vector<string> rsv;
	int flag = 1;
	bool visited[100000] = {false};

	while (1) {

		if (v[Idx] == s.top()) {
			//cout << " 현재 " << s.top() << "방문 후 pop" << s.top() << "\n";
			visited[s.top()] = true;
			s.pop();
			rsv.push_back("-");
			Idx++;
		}
		else if (v[Idx] > s.top()) {
			//cout << " 현재 " << cnt << "push" << "\n";
			s.push(cnt);
			cnt++;
			rsv.push_back("+");
		}
		else if (v[Idx] < s.top() ) {
			//cout << " 현재 " << s.top() << "방문 중.. pop" << s.top() << "\n";
			if (visited[s.top()] == false) { // 아직 방문하지 않은 곳을 pop하면
				cout << "NO";
				break;
			}
			s.pop();
			rsv.push_back("-");
		}

		if (Idx == N) {
			for (int i = 0; i < rsv.size(); i++) {
				cout << rsv[i] << "\n";
			}
			break;
		}
	
	}


	
}
