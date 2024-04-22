#include <iostream>
#include <string>
#define MAX_SIZE 50

using namespace std;
typedef struct {
	char c[MAX_SIZE][MAX_SIZE];
}starray;

int sum = 0;

void searchr(int N, starray* st, int i, int w) {
	sum++; //하나 획득

	if (st->c[i][w] == st->c[i][w + 1] && w+1 < N) { // 우측에 사탕 색이 같으면
		searchr(N, st, i, w + 1);
	}
}

void searchc(int N, starray* st, int i, int w) {
	sum++; //하나 획득
	if (st->c[i][w] == st->c[i+1][w] && i + 1 < N) { // 우측에 사탕 색이 같으면
		searchc(N, st, i+1, w);
	}
}

int main() {
	int N; // 보드의 크기
	cin >> N;
	
	string s;
	starray* st = (starray*)malloc(sizeof(starray));

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int t = 0; t < N; t++) {
			st->c[i][t] = s.at(t);
		}
	}
	
	/*for (int i = 0; i < N; i++) {
		for (int t = 0; t < N; t++) {
			cout << st->c[i][t];
		}
		cout << endl;
	}*/
	int q = 0;
	int flag = 0;

	for (int i = 0; i < N; i++) {
		for (int w = 0; w < N; w++) {

			//std::cout << i << "행" << w << "열 검사중..." << endl;

			if (st->c[i][w] != st->c[i][w + 1] && w+1 < N) { // 우측 검사 및 변환

				swap(st->c[i][w], st->c[i][w + 1]); // 위치 변경
				//cout << w << "와" << w + 1 << "이 다르므로 SWAP" << endl;

				for (int a = 0; a < N; a++) {
					for (int b = 0; b < N; b++) {
						searchr(N, st, a, b); // 행 검사
						if (sum > flag) {
							flag = sum;
						}

						sum = 0;

						searchc(N, st, a, b); // 열 검사
						if (sum > flag) {
							flag = sum;
						}
						sum = 0;
					}
				}

				swap(st->c[i][w], st->c[i][w + 1]); // 위치 변경
			}
			
			q = 0;

			if (st->c[i][w] != st->c[i + 1][w] && i + 1 < N) { // 하단 검사 및 반환
				swap(st->c[i][w], st->c[i+1][w]); // 위치 변경
				//cout << i << "와" << i + 1 << "이 다르므로 SWAP" << endl;

				for (int a = 0; a < N; a++) {
					for (int b = 0; b < N; b++) {
						searchr(N, st, a, b); // 행 검사
						if (sum > flag) {
							flag = sum;
						}

						sum = 0;

						searchc(N, st, a, b); // 열 검사
						if (sum > flag) {
							flag = sum;
						}
						sum = 0;
					}
				}

				swap(st->c[i][w], st->c[i+1][w]); // 위치 변경
			}




		}
	}

	cout << flag << endl;
}