#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x = 0;
    cin >> x;

    int rgb[1001][10];
    int r[1001];
    int g[1001];
    int b[1001];
    for (int i = 1; i <= x; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }

    rgb[1][0] = r[1];
    rgb[1][1] = g[1];
    rgb[1][2] = b[1];

    for (int i = 2; i <= x; i++) {
        rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + r[i];
        rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + g[i];
        rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + b[i];
    }
    cout << min(rgb[x][0], min(rgb[x][1], rgb[x][2]));
}