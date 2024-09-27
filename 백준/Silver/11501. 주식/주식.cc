#include <iostream>
#include <algorithm>

int arrays[1000001];
int dp[1000001];

using namespace std;

int main() {
	int T; // 테스트 케이스 수
	cin >> T;

	for (int i = 1; i <= T; i++) {

		int N; // 날의 수
		cin >> N;

		int max = 0;
		for (int i = 0; i < N; i++) {
			cin >> arrays[i];
		}

		for (int i = N - 1; i >= 0; i--) {
			if (arrays[i] > max) {
				max = arrays[i]; // 맥스값 갱신
			}
			dp[i] = max;
		}
		// 주가가 가장 비싼날 팔아야함, 만약 첫날이 가장 비싼날이면 pass
		long long buy = 0;
		long long margin = 0; // 수익
		int numb = 0;

		for (int i = 0; i < N; i++) {
			if (arrays[i] < dp[i]) { // 뒤에 더 비싼 날이 있으면 구매
				numb++; // 산 주식 개수
				buy = buy + arrays[i];
			}
			if (buy != 0 && arrays[i] == dp[i]) { // 구매한 주식이 0이 아니고 최고가인 날이면
				margin = margin + ( (numb * arrays[i]) - buy );
				buy = 0; // 산 주식 처분 
				numb = 0;
			}
		}

		cout << margin << "\n";

	}

}