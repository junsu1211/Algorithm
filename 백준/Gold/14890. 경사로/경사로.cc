#include <iostream>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    int** array = new int* [N + 1];

    for (int i = 1; i <= N; i++) {
        array[i] = new int[N + 1];
        for (int t = 1; t <= N; t++) {
            cin >> array[i][t];
        }
    }
    int max = 0;

    int center = 0;
    bool** visited = new bool* [N + 1];

    for (int i = 1; i <= N; i++) {
        visited[i] = new bool[N + 1];
    }
    int exitcode = 0;
    int flag = 0;

    for (int i = 1; i <= N; i++) { // 가로 행 찾기 

        for (int t = 2; t <= N; t++) {
            exitcode = 0;
            flag = 0;
         
            // 행 검사
            if (array[i][t - 1] == array[i][t]) { // 그 다음 칸이 같은 높이인 경우
            
                center = array[i][t]; // 기준점 옮겨주고
            }

            else if (array[i][t - 1] + 1 == array[i][t] && t - L >= 1) { // 상승하는 경우
                for (int q = 1; q <= L; q++) {
                    if (visited[i][t - q] == true || array[i][t - q] != array[i][t - 1]) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                   // cout << t - 1 << " , " << t << " 로 상승 상태...\n";
                    center = array[i][t]; // 기준점 옮겨주고
                    for (int q = 1; q <= L; q++) {
                        visited[i][t - q] = true;
                    }
                }
                else if (flag == 1) {
                   // cout << "상승불가..\n";
                    break;
                }
            }

            else if (array[i][t - 1] - 1 == array[i][t] && t + L - 1 <= N) { //하강하는 경우
                for (int q = 0; q < L; q++) {
                    if (visited[i][t + q] == true || array[i][t + q] != array[i][t]) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                  //  cout << t - 1 << " , " << t << " 로 하강 상태...\n";
                    center = array[i][t];
                    for (int q = 0; q < L; q++) {
                        visited[i][t + q] = true;
                    }
                }
                else if (flag == 1) {
                  //  cout << "하강 불가...\n";
                    break;
                }
            }
            else {
                
               // cout << "아무 경우도 아니므로 브레이크..\n";
                exitcode = 1;
            }

            if (t == N && center == array[i][N]) { // 문제없이 끝에 도착한 경우
             //   cout << i << " 번 쨰에서 카운터\n";
                max++;
            }
            if (exitcode) {
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int t = 1; t <= N; t++) {
            visited[i][t] = false;
        }
    }

    for (int i = 1; i <= N; i++) { // 세로열 찾기 

        center = array[1][i]; // 기준점 잡기
       // cout << "현재 " << i << "열 검사중...\n";
        for (int t = 2; t <= N; t++) {
            exitcode = 0;
            flag = 0;
           // cout << "현재 기준점 : " << t << "\n";
            // 행 검사
            if (array[t-1][i] == array[t][i]) { // 그 다음 칸이 같은 높이인 경우
               // cout << t - 1 << " , " << t << " 가 같으므로 기준점 옮기기...\n";
                center = array[t][i]; // 기준점 옮겨주고
            }

            else if (array[t-1][i] + 1 == array[t][i] && t - L >= 1) { // 상승하는 경우
                for (int q = 1; q <= L; q++) {
                    if (visited[t-q][i] == true || array[t-q][i] != array[t-1][i]) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                 //   cout << t - 1 << " , " << t << " 로 상승 상태...\n";
                    center = array[t][i]; // 기준점 옮겨주고
                    for (int q = 1; q <= L; q++) {
                        visited[t-q][i] = true;
                    }
                }
                else if (flag == 1) {
                  //  cout << "상승불가..\n";
                    break;
                }
            }

            else if (array[t-1][i] - 1 == array[t][i] && t + L - 1 <= N) { //하강하는 경우
                for (int q = 0; q < L; q++) {
                    if (visited[t+q][i] == true || array[t+q][i] != array[t][i]) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                   // cout << t - 1 << " , " << t << " 로 하강 상태...\n";
                    center = array[t][i];
                    for (int q = 0; q < L; q++) {
                        visited[t+q][i] = true;
                    }
                }
                else if (flag == 1) {
                 //   cout << "하강 불가...\n";
                    break;
                }
            }
            else {
         
               // cout << "아무 경우도 아니므로 브레이크..\n";
                exitcode = 1;
            }

            if (t == N && center == array[N][i]) { // 문제없이 끝에 도착한 경우
              //  cout << i << " 번 쨰에서 카운터\n";
                max++;
            }
            if (exitcode) {
                break;
            }
        }
    }



    cout << max;
}