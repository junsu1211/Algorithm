#include <iostream>

using namespace std;

int** One(int** array, int N, int M, int big) { // 1번 연산
	int** Narray = new int* [big + 1];
	for (int i = 1; i <= big; i++)
		Narray[i] = new int[big + 1];

	for (int i = N; i >= 1; i--) {
		for (int t = 1; t <= M; t++) {
			Narray[N - i + 1 ][t] = array[i][t];
		}
	}
	return Narray;
}


int** Two(int** array, int N, int M, int big) {
	int** Narray = new int* [big + 1];
	for (int i = 1; i <= big; i++)
		Narray[i] = new int[big + 1];

	for (int i = 1; i <= N; i++) {
		for (int t = M; t >= 1; t--) {
			//cout << "현재 : Narray[" << i << "][" << M - t + 1 << "]는 " << array[i][t] << "\n";
			Narray[i][M - t + 1] = array[i][t];
		}
	}
	return Narray;
}

int** Three(int** array, int N, int M, int big) {
	int** Narray = new int* [big + 1];
	for (int i = 1; i <= big; i++)
		Narray[i] = new int[big + 1];

	for (int i = 1; i <= M; i++) {
		for (int t = N; t >= 1; t--) {
			Narray[i][N - t + 1] = array[t][i];
		}
	}
	return Narray;
}

int** Four(int** array, int N, int M, int big) {
	int** Narray = new int* [big + 1];
	for (int i = 1; i <= big; i++)
		Narray[i] = new int[big + 1];

	for (int i = M; i >= 1; i--) {
		for (int t = 1; t <= N; t++) {
			Narray[M - i + 1][t] = array[t][i];
		}
	}
	return Narray;
}

int** Five(int** array, int N, int M, int big) {
	int** Narray = new int* [big + 1];
	for (int i = 1; i <= big; i++)
		Narray[i] = new int[big + 1];

	for (int i = 1; i <= N / 2; i++) { // 4번을 1번으로 옮기는 연산
		for (int t = 1; t <= M / 2; t++) {
			Narray[i][t] = array[i + N / 2][t];
		}
	}

	for (int i = 1; i <= N/2; i++) { // 1번을 2번으로
		for (int t = M/2 + 1; t <= M; t++) {
			Narray[i][t] = array[i][t - M / 2];
		}
	}

	for (int i = N / 2 + 1; i <= N; i++) { // 2번을 3번으로
		for (int t = M / 2 + 1; t <= M; t++) {
			Narray[i][t] = array[i - N / 2][t];
		}
	}

	for (int i = N/2 + 1; i <= N; i++) { // 3번을 4번으로
		for (int t = 1; t <= M / 2; t++) {
			Narray[i][t] = array[i][t + M / 2];
		}
	}
	return Narray;
}

int** Six(int** array, int N, int M, int big) {
	int** Narray = new int* [big + 1];
	for (int i = 1; i <= big; i++)
		Narray[i] = new int[big + 1];

	for (int i = N / 2 + 1; i <= N; i++) { // 1번을 4번으로 
		for (int t = 1; t <= M / 2; t++) {
			Narray[i][t] = array[i - N / 2][t];
		}
	}
	for (int i = N / 2 + 1; i <= N; i++) { // 4번을 3번으로
		for (int t = M / 2 + 1; t <= M; t++) {
			Narray[i][t] = array[i][t - M / 2];
		}
	}
	for (int i = 1; i <= N / 2; i++) { // 3번을 2번으로
		for (int t = M / 2 + 1; t <= M; t++) {
			Narray[i][t] = array[i + N / 2][t];
		}
	}
	for (int i = 1; i <= N / 2; i++) { // 2번을 1번으로
		for (int t = 1; t <= M / 2; t++) {
			Narray[i][t] = array[i][t + M / 2];
		}
	}
	return Narray;
}


int main() {
	int N, M, R;
	cin >> N >> M >> R; // 배열의 크기 N,M // 연산의 횟수 R

	int big = 0;

	if (N >= M)
		big = N;
	else
		big = M;

	int** array = new int* [big + 1];
	for (int i = 1; i <= big; i++)
		array[i] = new int[big + 1];


	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++)
			cin >> array[r][c];
	}


	int* flag = new int[R+1];

	for (int q = 1; q <= R; q++) {
		cin >> flag[q];
	}

	int flagi = 0;
	int N1 = N;
	int M1 = M;

	for (int q = 1; q <= R; q++) {
		if (flag[q] == 1) {
			array = One(array, N, M, big);
		}
		else if (flag[q] == 2) {
			array = Two(array, N, M, big);
		}
		else if (flag[q] == 3) { // 행렬이 바뀌는 연산
			array = Three(array, N, M, big);
			flagi++;
			if (flagi % 2 == 1) {
				N = M1;
				M = N1;
			}
			else if (flagi%2 == 0) {
				N = N1;
				M = M1;
			}
		}
		else if (flag[q] == 4) { // 행렬이 바뀌는 연산
			array = Four(array, N, M, big);
			flagi++;
			if (flagi % 2 == 1) {
				N = M1;
				M = N1;
			}
			else if (flagi % 2 == 0) {
				N = N1;
				M = M1;
			}
		}
		else if (flag[q] == 5) {
			array = Five(array, N, M, big);
		}
		else if (flag[q] == 6) {
			array = Six(array, N, M, big);
		}
	}
	
	
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= M; c++) {
				cout << array[r][c] << " ";
			}
			cout << "\n";
		}
	
}