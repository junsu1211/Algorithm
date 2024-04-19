#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num=0; // N의 약수의 개수
	cin >> num;

	int* array = (int*)malloc(sizeof(int)* num);

	for (int i = 0; i < num; i++) {
		cin >> array[i]; //입력 받음
	}

	int max = array[0];

	for (int t = 0; t < num; t++) {
		if (array[t] > max)
			max = array[t]; // 최대값 구했음
	}

	sort(array, array + num); // 정렬
	int result;
	int flag = 0;

	for (int i = 0; i < num; i++) {
		result = max * array[i];
		for (int t = i; t < num; t++) {
			if (result % array[t] != 0) {
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << result;
			break;
		}
		flag = 0;
	}
}