#include <iostream>

using namespace std;

int main() {
	string S;

	cin >> S;

	// 단어의 길이는 1,000,000을 넘지 않음
	char st[27]; // 알파벳 개수
	char bst[27];

	int cnt[27];

	st[1] = 'a';
	bst[1] = 'A';
	cnt[1] = 0;

	for (int i = 2; i <= 26; i++) {
		st[i] = st[i - 1] + 1; // 아스키 값을 이용
		bst[i] = bst[i - 1] + 1;
		cnt[i] = 0; // 초기화
	}

	for (int i = 0; i < S.length(); i++) {
		for (int t = 1; t <= 26; t++) {

			if (S[i] == st[t]) { // 같은 알파벳을 찾으면
				cnt[t]++; //카운트
				break;
			}
			else if (S[i] == bst[t]) { // 같은 대문자 알파벳을 찾으면
				cnt[t]++;
				break;
			}

		}
	}

	cnt[0] = 0;
	int max = 0;
	int midx = 0;

	for (int i = 1; i <= 27; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			midx = i;
		}
	}

	int flag = 1;
	for (int i = 1; i <= 27; i++) {
		if (i != midx && max == cnt[i]) { // 최대값이 일치하는 다른 경우가 존재하는 경우
			cout << "?";
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		cout << bst[midx];
	}

}