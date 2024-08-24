#include <iostream>

using namespace std;

int maxs(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= a && b >= c) {
		return b;
	}
	else if (c >= a && c >= b) {
		return c;
	}

}

int main() {
	
	int a = 1;
	int b = 1;
	int c = 1;

	int maxi = 0;

	while(1){
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) { // 탈출
			break;
		}
		
		maxi = maxs(a, b, c);
		if (maxi >= a + b + c - maxi) { // 삼각형의 조건 만족 x
			cout << "Invalid\n";
		}
		else {
			if (a == b && b == c) {// 세변이 모두 같은 경우
				cout << "Equilateral\n";
			}
			else if (a != b && b != c && a != c) { // 세변이 모두 다른경우
				cout << "Scalene\n";
			}
			else if ((a == b && b != c) || (a == c && a != b) || (b == c && a != b)) {
				cout << "Isosceles\n";
			}
		}
	}
}