#include <iostream>

using namespace std;
int maxs(int A, int B) {
	if (A > B)
		return A;
	else 
		return B;
}

int main() {
	int n;
	cin >> n;

	int** summation = new int*[n + 2];
	for (int i = 1; i <= n+1; i++)
		summation[i] = new int[n + 2];

	int** intg = new int*[n + 2];
	for (int i = 1; i <= n+1; i++)
		intg[i] = new int[n + 2];

	for (int t = 1; t <= n; t++) {
		for (int c = 1; c <= t; c++) {
			cin >> intg[t][c];
		}
	}

	summation[1][1] = intg[1][1];
	summation[2][1] = intg[1][1] + intg[2][1];
	summation[2][2] = intg[1][1] + intg[2][2];


	for (int t = 3; t <= n; t++) {
		for (int c = 1; c <= t; c++) {
			if (c == 1) {
				summation[t][c] = summation[t - 1][c] + intg[t][1];
				continue;
				//cout << "summation[" << t << "][" << c << "] 는 " << summation[t][c] << endl;
			}
			else if (c == t) {
				summation[t][c] = summation[t - 1][ t - 1] + intg[t][c];
				continue;
				//cout << "summation[" << t << "][" << c << "] 는 " << summation[t][c] << endl;
			}
			else {
				summation[t][c] = maxs(summation[t - 1][c - 1] + intg[t][c], summation[t - 1][c] + intg[t][c]);
				//cout << "summation[" << t << "][" << c << "] 는 " << summation[t][c] << endl;
				continue;
			}
		}
	}
	int maxsum = 0;
	for (int q = 1; q <= n; q++) {
		if (summation[n][q] >= maxsum) {
			maxsum = summation[n][q];
		}
	}
	cout << maxsum;

}