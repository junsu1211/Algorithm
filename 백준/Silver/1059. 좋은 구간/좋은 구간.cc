#include <iostream>

using namespace std;
int main() {
	int L;
	cin >> L; // 집합 S의 크기 L
	if (L < 1 || L > 50) {
		perror("범위 초과");
		exit(1);
	}

	int* S = (int*)malloc(L * sizeof(int));
	for (int i = 0; i < L; i++) {
		cin >> S[i];
		if (S[i] < 0 || S[i] > 1000) {
			perror("범위 초과");
			exit(1);
		}
	}
	int bignum=0; // 최대값
	int minnum = 1001; // 최소값
	
	for (int i = 0; i < L; i++) {
		if (bignum < S[i]) {
			bignum = S[i];
		}
	}

	for (int i = 0; i < L; i++) {
		if (minnum > S[i]) {
			minnum = S[i];
		}
	}

	int n;
	cin >> n;
	if (n < 1 || n > bignum) {
		perror("범위 초과");
		exit(1);
	}
	int A=0, B=0;
	int alpha = n - minnum; // n - 집합의 최소값
	int beta = bignum - n;
	// n-s[i]의 최소값은 -999이고, n-s[i]의 최대값은 999이다.

	for (int i = 0; i < L; i++) { // A구간 찾기
		if (n - S[i] <= alpha && n - S[i] >= 0) {
			alpha = n - S[i];
			A = S[i];
		}

		if (S[i] - n >= 0 && S[i] - n <= beta) { // B구간 찾기
			beta = S[i] - n;
			B = S[i];
		}

	}

	//cout << A << B << endl;
	A = A + 1;
	B = B - 1;
	int sum = 0;
	int count = 0;

	for (int i = A; i <= n; i++) { //A는 고정
		if (i == n) {
			for (int k = n + 1; k <= B; k++) {
				sum++;
			}
		}
		else {
			for (int k = n; k <= B; k++) {
				sum++;
			}
		}
	}
	cout << sum << endl;


}