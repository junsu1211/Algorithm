#include <iostream>
using namespace std;

int main() { //정수 범위를 넘어가는 수를 써야할 때는 부동소수점 표기 즉 지수를 활용하자!
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while (cin >> n) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp = tmp * 10 + 1;
            tmp %= n;
            if (tmp == 0) {
                cout << i << "\n";
                break;
            }
        }
    }
}