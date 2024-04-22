#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int length[9]; // 9난쟁이의 키
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> length[i];
		sum = sum + length[i]; // 
	}

	// 36가지의 경우의 수 9C7 이므로 
	sort(length, length + 9); // 정렬

	int side = sum - 100; // 넘는 숫자
	//cout << sum << "\n" << side << endl;
	// 합이 side가 되는 2개를 찾으면 될 것 같다

	int a=0, b=0;

	for (int i = 0; i < 9; i++) {
		for (int t = 0; t < 9; t++) {
			if (length[i] + length[t] == side && i != t) {
				a = i;
				b = t;
				i = 10;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) { // 경우 제외
		}
		else {
			cout << length[i] << endl;
		}
	}
}