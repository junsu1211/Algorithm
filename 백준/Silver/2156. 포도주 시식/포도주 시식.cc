#include <iostream>

using namespace std;
int maxs(int A, int B, int C) {
	if (A >= B && A >= C)
		return A;
	else if (B >= A && B >= C) {
		return B;
	}
	else if (C >= A && C >= B) {
		return C;
	}
}

int main() {
	int N;
	cin >> N;

	int* Wine = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> Wine[i];
	}
	int* Drink = new int[N + 1];
	Drink[1] = Wine[1];
	Drink[2] = Drink[1] + Wine[2];
	Drink[3] = maxs(Drink[2], Wine[1] + Wine[3], Wine[2] + Wine[3]);

	for (int i = 4; i <= N; i++) {
		Drink[i] = maxs(Drink[i - 1], Drink[i - 3] + Wine[i - 1] + Wine[i], Drink[i - 2] + Wine[i]);
	}

	cout << Drink[N];

}
	
	
	