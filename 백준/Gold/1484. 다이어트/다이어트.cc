#include <iostream>

using namespace std;

int main() {
	int G; 
	cin >> G;
	
	// 기억하는 몸무게 old , 현재 몸무게 new
	// G = new^2 - old^2
	
	
	int maximum = ( G / 2 ) + 1; // 최대 루프

	int* dp = new int[maximum + 1];
	

	int flag = 0;
	
	for (int i = 1; i <= maximum; i++) {
		dp[i - 1] = 0;
		for (int t = i; t<= maximum; t++) {		
			dp[t] = 2 * t + 1;
			dp[t] = dp[t - 1] + dp[t];
			
			if (dp[t] == G) {
				flag = 1;
				cout << t + 1 << "\n";
				break;
			}
			if (dp[t] > G) {
				break;
			}

		}
	}

	if (flag == 0) {
		cout << -1;
	}

	/*for (int i = 1; i <= maximum; i++) {
		for (int t = i; t <= maximum; t++) {
			cout << i << "행" << t << " 열 : " << dp[i][t] << "\n";
		}
	}*/
	
	

	//1 (+3) 4 (+5) 9 (+7) 16 (+9) 25 (+11) 36 (+13) 49 (+15) 64 (+17) 81 (
}