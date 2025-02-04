#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int P;
    cin >> P;
    int num = 0;

    int** arr = new int* [P + 1];
    for (int i = 0; i <= P; i++) {
        arr[i] = new int[21];
    }

    int chn = 0;
    int count = 0;
    vector<pair<int, int>> v;

    for (int i = 0; i < P; i++) {
        cin >> num;
        arr[i][0] = num;
        count = 0;

        for (int t = 1; t <= 20; t++) {
            cin >> arr[i][t];

            for (int j = 1; j <= t; j++) { // 가장 앞에 있는 나보다 큰애
                if (arr[i][j] > arr[i][t]) {
                    // 찾았어
                    chn = arr[i][t];
                    for (int q = t; q >= j+1; q--) { // 맨 앞부터 t까지 모두 뒷걸음질
                        arr[i][q] = arr[i][q - 1];
                        count++;
                    }
                    arr[i][j] = chn;
                    //cout << count << "\n";
                    //sort(&arr[i][1], &arr[i][t]);
                    break;
                }
            }
            /*for (int w = 1; w <= t; w++) {
                cout << arr[i][w];
            }
            cout << "\n";*/
        }

        v.push_back({ num, count });
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}