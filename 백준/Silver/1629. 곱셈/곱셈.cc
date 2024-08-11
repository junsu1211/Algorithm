#include <iostream>
#include <string>

using namespace std;
int A, B, C;

long long int f(long long int X) {
	if (X == 1) return A % C;

	long long int k = f(X / 2) % C;
	if (X % 2 == 0) return k * k % C;
	else return k * k % C * A % C;
}
int main() {
	
	cin >> A >> B >> C;

	cout << f(B);
}