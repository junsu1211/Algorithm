#include <stdio.h>
int main() {
    int N;
    int t=1;
    while (t) {
        scanf("%d", &N);
        if (N <= 1000)
            t = 0;
    }
    int a = 0, b = 0, c = 0, d=0;
    int count=0;

    for (int i = 1; i <= N; i++) {

        if (i >= 100 && i <= 999) { //N이 세자리 수일 때
             c = i / 100; // 백의 자리 수
             b = (i - ((i / 100) * 100)) / 10; // 십의 자리 수
             a = i - (c * 100) - (b * 10); // 일의 자리 수
             if (a == b && b == c) {
                 count++;
             }
             else if (a < b && (b - a == c - b)) {
                 count++;
             }
             else if (a > b && (a - b == b - c)) {
                 count++;
             }
        }

        if (i >= 10 && i <= 99) { // N이 두자리 수 일 때
            count++;
        }

        if (i >= 1 && i <= 9) { // N이 한자리 수 일 때
            count++;
        }
    }
    printf("%d", count);
    return 0;
}