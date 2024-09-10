#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	char* line = new char[N + 1];

	for (int i = 1; i <= N; i++) {
		cin >> line[i];
	}
	bool* ate = new bool[N + 1];
	for (int i = 1; i <= N; i++)
		ate[i] = true;


	int maxnum = 0;

	for (int i = 1; i <= N; i++) {
		if (line[i] == 'P') { // 사람을 찾으면
			for (int t = i - K; t <= i + K; t++) {
				if (line[t] == 'H' && ate[t] == true) { // 범위 내 가장 좌측에 있는 아직 먹히지 않은 햄버거를 먹는다.
					maxnum++;
					ate[t] = false;
					//cout << "현재 " << i << " 번째 사람이" << t << " 에 있는 햄버거 먹었음\n";
					break;
				}
			}
		}
	}

	cout << maxnum;
}