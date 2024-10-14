#include <iostream>
#include <cmath>

using namespace std;

int minuss = 0;
int zero = 0;
int one = 0;

int powerOfThree(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 3;
    }
    return result;
}

void find(int x, int y, int pows, int** array, int size){
    int flag = 0;
    int subsize = powerOfThree(pows);

    // 현재 탐색 범위 확인
    for (int i = x; i < x + subsize; i++) {
        for (int t = y; t < y + subsize; t++) {
            if (array[x][y] != array[i][t]) {
                flag = 1; // 다른 값이 발생
                break;
            }
        }
        if (flag == 1) break;
    }

    if (flag == 0) {
        // 더 이상 탐색 안해도됨
        if (array[x][y] == 0)
            zero++;
        else if (array[x][y] == -1)
            minuss++;
        else if (array[x][y] == 1)
            one++;
        return;
    }

    if (pows == 0) return; // 재귀 탈출 조건, 더 이상 나눌 수 없음

    // 9등분으로 나눠서 재귀 탐색
    for (int i = 0; i < 3; i++) {
        for (int t = 0; t < 3; t++) {
            find(x + i * (subsize / 3), y + t * (subsize / 3), pows - 1, array, size);
        }
    }
}

int main() {
    int N;
    cin >> N;

    int a = N;
    int pows = 0;

    // N을 3으로 나눌 수 있는지 확인하여 pows 계산
    while (a != 1) {
        pows++;
        a /= 3;
    }

    // 0부터 시작하도록 배열 할당
    int** array = new int*[N];
    for (int i = 0; i < N; i++) {
        array[i] = new int[N];
    }

    // 배열 입력받기
    int flag = 0;
    for (int i = 0; i < N; i++) {
        for (int t = 0; t < N; t++) {
            cin >> array[i][t];
            if (array[0][0] != array[i][t]) {
                flag = 1; // 다른 값이 발생
            }
        }
    }

    // 값이 동일하면 바로 결과 출력
    if (flag == 0) {
        if (array[0][0] == 0)
            zero++;
        else if (array[0][0] == -1)
            minuss++;
        else if (array[0][0] == 1)
            one++;
    } else { // 9등분해서 재귀 탐색
        find(0, 0, pows, array, N);
    }

    cout << minuss << "\n" << zero << "\n" << one << "\n";

    // 동적 배열 해제
    for (int i = 0; i < N; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
