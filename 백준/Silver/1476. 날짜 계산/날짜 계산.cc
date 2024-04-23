#include <iostream>

using namespace std;

int main() {
	int E, S, M; // 각각 지구 태양 달

	cin >> E >> S >> M;

	int result = 0;
	int a=0, b=0, c=0;

	while (1) {
		if (a == E && b == S && c == M)
			break;
		a++;
		b++;
		c++;
		result++;
		if (a > 15)
			a = 1; // 1로 변환
		if (b > 28)
			b = 1; // 1로 변환
		if (c > 19)
			c = 1; // 1로 변환
	}

	cout << result;


}