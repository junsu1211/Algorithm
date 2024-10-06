#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct graphtype {
    int** adj_mat;
} graphtype;

void init(graphtype* g, int N, int M, int**& result, bool**& visited) {
    g->adj_mat = new int*[N];
    result = new int*[N];
    visited = new bool*[N];

    for (int i = 0; i < N; i++) {
        g->adj_mat[i] = new int[M];
        result[i] = new int[M];
        visited[i] = new bool[M];
        for (int j = 0; j < M; j++) {
            result[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void cleanup(graphtype* g, int N, int M, int** result, bool** visited) {
    for (int i = 0; i < N; i++) {
        delete[] g->adj_mat[i];
        delete[] result[i];
        delete[] visited[i];
    }
    delete[] g->adj_mat;
    delete[] result;
    delete[] visited;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상

void bfs(int x, int y, graphtype* g, int N, int M, int** result, bool** visited) {
    queue<pair<int, int>> q;
    result[x][y] = 1;
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if (nx == N - 1 && ny == M - 1) {
            cout << result[nx][ny] << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = nx + dx[i];
            int next_y = ny + dy[i];

            if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
                if (g->adj_mat[next_x][next_y] == 1 && !visited[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    result[next_x][next_y] = result[nx][ny] + 1;
                    q.push({next_x, next_y});
                }
            }
        }
    }

    // 도착할 수 없으면 -1 출력
    cout << -1 << endl;
}

int main() {
    int N, M;
    cin >> N >> M;

    graphtype* g = new graphtype;
    int** result;
    bool** visited;

    init(g, N, M, result, visited);

    char input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            g->adj_mat[i][j] = input - '0';
        }
    }

    bfs(0, 0, g, N, M, result, visited);

    // 메모리 해제
    cleanup(g, N, M, result, visited);
    
    delete g;
    return 0;
}
