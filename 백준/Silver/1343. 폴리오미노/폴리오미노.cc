#include <iostream>
#include <cstring>

using namespace std;
int main() {

	string s;
	cin >> s;

	int size = s.length();
	//cout << n;

	string c = s;

	int flag = 0;

	for (int i = 0; i < size; i++) {
		if (s[i] == 'X') {
			flag++; // X값이 있음을 하나 추가
		}
		else if (s[i] == '.'){
			flag = 0; //플래그 초기화
		}

		if (flag == 2 && s[i + 1] == 'X') // X가 2개 이상인 경우
			continue;
		else if (flag == 2 && s[i + 1] != 'X') { // X가 2개인 경우
			s[i] = 'B';
			s[i - 1] = 'B';
			flag = 0; // 플래그 초기화
		}

		if (flag == 4) {
			s[i] = 'A';
			s[i - 1] = 'A';
			s[i - 2] = 'A';
			s[i - 3] = 'A';
			flag = 0;
		}

		if (flag % 2 != 0 && s[i + 1] != 'X') { // 폴리오미노를 채울 수 없는 경우
			cout << -1 << endl;
			return 0;
		}

	}
	cout << s << endl;
}