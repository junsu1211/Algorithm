#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int AN;
	cin >> AN; // 배열 A의 크기 N

	int* A = new int[AN];
	int* B = new int[AN];
	int* P = new int[AN];
	for (int i = 0; i <= AN - 1; i++) {
		cin >> A[i];
		B[i] = A[i];
	}

	

	//A[0] = 2, A[1] = 3, A[2] = 1 ===> B [p[0]] = A[0], B[ p[1] ] = 3, B[ p[2] ] = 1
	//A를 내림차순으로 만드는 P[0]를 구하는 것

	sort(B, B + AN); // 오름차순 정렬
	//B[0] = 1, B[1] = 1, B[2] = 2, B[3] = 3
	//A[0] = 2, A[1] = 1, A[2] = 3, A[3] = 1

	for (int i = 0; i <= AN - 1; i++) {
		for (int t = 0; t <= AN - 1; t++) {
			if (A[i] == B[t]) {
				P[i] = t;
				B[t] = -1;
				break;
			}

		}
	}

	for (int i = 0; i <= AN - 1; i++)
		cout << P[i] << " ";
}