#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int M=0, N=0; // 변수

	cin >> M >> N;
	int flag = 0;
	
	int* array = (int*)malloc(sizeof(int) * (N-1));
	for (int i = 2; i <=N ; i++) {
		array[i-2] = i;
	}

	int t = 0;

	for (int i = 0; i<= N-2; i++) {
		if (array[i] != 0) {
			for (t = i+1; t <= N - 2; t++) {
				
				if (array[t] % array[i] == 0) {
					array[t] = 0;
				}
			}
		}
		if (array[i] * array[i] >= N)
			break;
	}
	if (M == 1) { M++; }
	for (int i = M-2; i <= N-2; i++) {
		
			if (array[i] != 0) {
				cout << array[i] << "\n";
			}
	}
}