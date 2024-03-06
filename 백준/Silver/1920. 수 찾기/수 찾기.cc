#include <iostream>
#include <malloc.h>

using namespace std;


void heapify(int* Aarray, int n, int i) {
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left < n && Aarray[left] > Aarray[largest])
		largest = left;

	if (right < n && Aarray[right] > Aarray[largest])
		largest = right;

	if (largest != i) {
		swap(Aarray[i], Aarray[largest]);
		heapify(Aarray, n, largest); // 재귀 호출
	}
}

void heapSort(int* Aarray, int n) {
	for (int i = n / 2; i >= 0; i--)
		heapify(Aarray, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(Aarray[0], Aarray[i]);
		heapify(Aarray, i, 0);
	}
}

void printArray(int* Aarray, int n) {
	for (int i = 0; i < n; i++)
		cout << Aarray[i] << " ";
	cout << endl;
}

int search(int Marray, int* Aarray, int mid, int N) {
	int left = 0;
	int right = N;

	while (left <= right) {
		if (Marray == Aarray[mid]) { // 중앙값과 일치하면
			return 1;
		}
		else if (Marray < Aarray[mid]) { // 중앙값보다 작으면
			right = mid - 1;
			mid = right / 2;
			//search(Marray, Aarray, mid, right);
		}
		else if (Marray > Aarray[mid]) { // 중앙값 보다 크면 
			left = mid + 1;
			mid = (right + left) / 2;
			//search(Marray, Aarray, mid, right);
		}
	}

	return 0;
}

int main() {
	int N;
	cin >> N;

	int* Aarray = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		cin >> Aarray[i];
	}

	int M;
	cin >> M;

	int* Marray = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		cin >> Marray[i];
	}

	// Aarray를 정렬해서 이진탐색
	heapSort(Aarray, N);
	int mid = N/2; // 중앙값 찾기

	for (int i = 0; i < M; i++) {
		cout << search(Marray[i], Aarray, mid, N-1) << "\n";
	}

	//printArray(Aarray, N);
}