#include <iostream>

using namespace std;

int maxsum = 0;
int summation=0;
int Date = 0;


void Summation(int* Time, int* Cost, int Idx, int N) { 

	if (Idx + Time[Idx] <= N + 1) { // 의뢰를 받을 조건
		summation += Cost[Idx]; // 합 비용 , Idx가 현재 날짜
		//cout << "현재 날짜 " << Idx << "\n";
		//cout << "현재 비용 " << summation << "\n" << "\n";
	}
	else { // 의뢰를 못받으면 리턴
		summation += Cost[Idx];
		return;
	}

	if (summation >= maxsum)
		maxsum = summation;

	for (int i = Time[Idx]; i <= N; i++) {

		if (Idx + i < N ) {
			Summation(Time, Cost, Idx + i, N);
			summation -= Cost[Idx+i];
		}
		else if (Idx + i == N && Time[Idx + i] == 1) {
			Summation(Time, Cost, Idx + i, N);
			summation -= Cost[Idx+i];
		}
	}

}

int main() {
	int N;
	cin >> N;

	int* Time = new int[N + 1];
	int* Cost = new int[N + 1];

	for (int i = 1; i <= N; i++) {
		cin >> Time[i] >> Cost[i];
	}

	int result = 0;
	int cnt = 0;

	for (int Idx = 1; Idx <= N; Idx++) {

		if (Idx + Time[Idx] <= N + 1) {
			Summation(Time, Cost, Idx, N);
			summation = 0;
		}

	}
	cout << maxsum;

}