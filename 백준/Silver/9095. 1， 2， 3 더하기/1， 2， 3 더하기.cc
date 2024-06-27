#include <iostream>

using namespace std;

int counting=0;

void one(int n, int sum);
void two(int n, int sum);
void three(int n, int sum);

void summation(int n,int* result, int i) {
	int sum = 0;
	one(n, sum);
	two(n, sum);
	three(n, sum);
	result[i] = counting;
}

void one(int n, int sum) {
	sum = sum + 1;

	if (sum > n)
		return;
	if(sum == n){
		counting++;
		return ;
	}
	else {
		one(n, sum);
		two(n, sum);
		three(n, sum);
	}
}

void two(int n, int sum) {
	sum = sum + 2;

	if (sum > n)
		return;
	else if (sum == n) {
		counting++;
		return;
	}
	else {
		one(n, sum);
		two(n, sum);
		three(n, sum);
	}
}

void three(int n, int sum) {
	sum = sum + 3;

	if (sum > n) // sum이 원래 값 n을 넘는다면 종료
		return;
	else if (sum == n) { // sum이 원래 값 n과 같아진다면 count를증가시키고 종료
		counting++;
		return;
	}
	else {
		one(n, sum); // sum 값이 부족하다면 다시 재귀호출
		two(n, sum);
		three(n, sum);
	}
}

int main() {
	int T;
	cin >> T;

	int* result = new int[T];
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		summation(n,result,i);
		counting = 0;
	}

	for (int t = 0; t < T; t++)
		cout << result[t] << "\n";
}