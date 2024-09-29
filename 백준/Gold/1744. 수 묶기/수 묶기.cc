#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int A, int B) {
	return A > B;
}

int main() {
	int N;
	cin >> N;

	int num;
	vector<int> plusv;
	vector<int> mnv;
	int mct = 0;
	int zerocount = 0;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num < 0) // 음수의 개수
			mnv.push_back(num);
		else // 양수만 넣음
			plusv.push_back(num);

		if (num == 0) {
			zerocount++;
		}
	}
	 // 최대가 되려면 -> 음수는 음수 끼리 묶는것 -> 음수의 개수가 홀수이면 음수 하나는 묶지 않음
	// 큰수들은 최대한 큰 수 끼리
	vector<int> resultv;
	int sum = 0;

	sort(mnv.begin(), mnv.end());
	sort(plusv.begin(), plusv.end(), compare);

	if (mnv.size() % 2 == 0) { // 음수가 짝수개 있으면

		if (mnv.size() >= 2) {
			for (int i = 0; i <= mnv.size() - 2; i = i + 2) {
				sum = sum + (mnv[i] * mnv[i + 1]);
			}
		}

		if (plusv.size() % 2 == 0 && plusv.size() >= 2) { // 양수가 짝수 개 있으면서 2개이상
			for (int i = 0; i <= plusv.size() - 2; i=i+2) {
				if (plusv[i] * plusv[i + 1] > plusv[i] + plusv[i + 1]) { // 묶는 것이 더하는 것 보다 더 커야
					sum = sum + ( plusv[i] * plusv[i + 1]);
				}
				else { // 그렇지 않다면 
					sum = sum + plusv[i] + plusv[i + 1]; // 덧셈이 크기 때문
				}
			}
		}
		if (plusv.size() == 1) // 양수가 한개
			sum = sum + plusv[0];
		else if (plusv.size() % 2 == 1 && plusv.size() > 2) { // 양수가 홀수 개 면서 3개 이상
			for (int i = 0; i <= plusv.size() - 3; i=i+2) {
				if (plusv[i] * plusv[i + 1] > plusv[i] + plusv[i + 1]) { // 묶는 것이 더하는 것 보다 더 커야
					sum = sum + (plusv[i] * plusv[i + 1]);
				}
				else { // 그렇지 않다면 
					sum = sum + plusv[i] + plusv[i + 1]; // 덧셈이 크기 때문
				}
			}
			sum = sum + plusv[plusv.size() - 1]; // 마지막 수 더해주기
		}

		cout << sum;
	}
	else if (mnv.size() % 2 == 1) { // 음수가 홀수 개 있으면

		if (mnv.size() > 2) { //음수가 3개 이상
			for (int i = 0; i <= mnv.size() - 3; i = i + 2) {
				sum = sum + (mnv[i] * mnv[i + 1]);
			}
		}		

		if (zerocount >= 1) { // 0이 한개 이상이라면
			mnv[mnv.size() - 1] = 0; // 마지막 음수 0과 묶음 
		}
		else
			sum = sum + mnv[mnv.size() - 1];

		if (plusv.size() % 2 == 0 && plusv.size() >= 2) { // 양수가 짝수 개 있으면서 2개이상
			for (int i = 0; i <= plusv.size() - 2; i = i + 2) {
				if (plusv[i] * plusv[i + 1] > plusv[i] + plusv[i + 1]) { // 묶는 것이 더하는 것 보다 더 커야
					sum = sum + (plusv[i] * plusv[i + 1]);
				}
				else { // 그렇지 않다면 
					sum = sum + plusv[i] + plusv[i + 1]; // 덧셈이 크기 때문
				}
			}
		}
		if (plusv.size() == 1) // 양수가 한개
			sum = sum + plusv[0];
		else if (plusv.size() % 2 == 1 && plusv.size() > 2) { // 양수가 홀수 개 면서 3개 이상
			for (int i = 0; i <= plusv.size() - 3; i = i + 2) {
				if (plusv[i] * plusv[i + 1] > plusv[i] + plusv[i + 1]) { // 묶는 것이 더하는 것 보다 더 커야
					sum = sum + (plusv[i] * plusv[i + 1]);
				}
				else { // 그렇지 않다면 
					sum = sum + plusv[i] + plusv[i + 1]; // 덧셈이 크기 때문
				}
			}
			sum = sum + plusv[plusv.size() - 1]; // 마지막 수 더해주기
		}

		cout << sum;

	}

}