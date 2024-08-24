#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int prev = 2;
	int count = 0;

	for (int i = 1; i <= N; i++) {

		if (i == prev + (6*count)  ) {
			prev = i;
			count++;
		}

	}

	if (N == 1) {
		cout << 1;
	}
	else {
		cout << count+1;
	}
	// 1 , 2 , 8 , 20, 38
	
}