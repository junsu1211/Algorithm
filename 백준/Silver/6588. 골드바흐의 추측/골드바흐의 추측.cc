#include <iostream>
#define MAX_ARRAY 100001

using namespace std;

void Select(bool* PrimeArray, int n) {
	int newA = -1, newB = -1;
	// 뒤에서부터 찾아가면서 
	for (int i = n; i >= 3; i--) {
		if (PrimeArray[i] == true && PrimeArray[n - i] == true && n - i > 2) {
			newB = i; 
			newA = n - i;
			break;
		}
	}

	if (newA == -1 && newB == -1)
		cout << "Goldbach's conjecture is wrong.";
	else
		cout << n << " = " << newA << " + " << newB << "\n";
}


void Eratos(bool* PrimeArray, int n) {
	if (n <= 1) return;

	//bool* PrimeArray = new bool[n + 1];

	for (int i = 2; i <= n; i++) 
		PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++) {
		if (PrimeArray[i]) {
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
		}
	}

}

int main() {
	//4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.

	int* array = new int[MAX_ARRAY];
	
	int i = 0;

	while (1) {
		cin >> array[i]; // 배열에 수를 저장
		if (array[i] == 0)
			break;
		else
			i++;
	}

	bool* PrimeArray = new bool[1000000];
	Eratos(PrimeArray, 1000000); // O(n) 10^6승, 미리 소수로만 이루어진 배열로 변경
	

	for(int t = 0; t < i; t++) { //O(n) 의 시간복잡도 필요 그 이상은 안됨 ( 5천만 = 0.5초)
		Select(PrimeArray, array[t]);
	}

	return 0;
}