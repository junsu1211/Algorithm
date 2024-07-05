#include <iostream>

using namespace std;

void search(int N, long long* array) {

	for (int i = 4; i <= N; i++) {
		array[i] = array[i - 1] + array[i - 2];
	}
	
}


int main() {
	int N;
	cin >> N;

	long long* array = new long long[91];

	array[1] = 1; // 이친수는 1로 시작한다
	array[2] = 1; // 이친수는 1 1을 부분 문자열로 가질 수 없다 ex) 10
	array[3] = 2; // 100, 101  
	
	if (N >= 4)
		search(N, array);

	cout << array[N];
}