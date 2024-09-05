#include <iostream>

using namespace std;
int main() {
	int N; //정사각형의 크기

	cin >> N;

	char** squ = new char*[N + 2];
	for (int i = 1; i <= N+1; i++) {
		squ[i] = new char[N + 2];
	}

	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= N; t++) {
			cin >> squ[i][t];
		}
	}
	int heartx = 0;
	int hearty = 0;

	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= N; t++) {
			if (squ[i][t] == '*') { // 가장 먼저 나오는 곳이 머리
				heartx = i + 1;
				hearty = t;
				// 심장은 머리의 바로 아래에 있다.
				break;
			}
		}
		if (heartx == i+1) {
			break;
		}
	}

	int leftarmlen= 0; // 왼쪽 팔 길이
	int lefty = hearty;

	while (1) {
		if (squ[heartx][lefty-1] == '*') {
			leftarmlen++;
			lefty--;
		}
		else {
			break; // 아니면 탈출
		}
	}

	int rightarmlen = 0;
	int righty = hearty;

	while (1) { // 오른쪽 팔 구하기
		if (squ[heartx][righty + 1] == '*') {
			rightarmlen++;
			righty++;
		}
		else {
			break; // 아니면 탈출
		}
	}

	int waistlen = 0;
	int waistx = heartx;

	int leftlegx = 0;
	int leftlegy = hearty -1;
	int rightlegx = 0;
	int rightlegy = hearty + 1;
	int leftleglen = 0;
	int rightleglen = 0;

	while(1) {
		if (squ[waistx + 1][hearty] == '*') {
			waistlen++;
			waistx++;
		}
		else {
			leftlegx = waistx;
			rightlegx = waistx;
			break;
		}
	}

	while (1) { // 왼쪽 다리 길이
		if (squ[leftlegx + 1][leftlegy] == '*') {
			leftleglen++;
			leftlegx++;
		}
		else
			break;
	}

	while (1) { // 오른쪽 다리 길이
		if (squ[rightlegx + 1][rightlegy] == '*') {
			rightleglen++;
			rightlegx++;
		}
		else
			break;
	}
	cout << heartx <<" " << hearty << "\n";
	cout << leftarmlen << " " << rightarmlen << " " << waistlen << " " << leftleglen << " " << rightleglen;
}