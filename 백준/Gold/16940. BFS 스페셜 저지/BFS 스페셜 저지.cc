#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Queue {
    int N;
    int* Queue;
    int front;
    int rear;
}QueueType;

typedef struct GraphType {
    int N;
    vector<int>* adj_list; // 인접 리스트
}GraphType;

bool isempty(QueueType* Q) {
    if (Q->front == Q->rear)
        return true; // 비어있다
    else
        return false;
}

bool isfull(QueueType* Q) {
    if (Q->rear == Q->N) { // 큐가 꽉참
        return true;
    }
}

void init(QueueType* Q, GraphType* G, int N) {
    Q->front = 0;
    Q->rear = 0;
    Q->N = N;
    G->N = N;

    G->adj_list = new vector<int>[N+1];
} // 큐가 비어 있는 상태

void push(int A, QueueType* Q) {

    Q->rear++;
    Q->Queue[Q->rear] = A;
}

int size(QueueType* Q) {
    return Q->rear - Q->front;
}
int pop(QueueType* Q) {
    if (isempty(Q) == true) { // 큐가 비어있다면
        return -1;
    }
    else {
        Q->front++;
        return Q->Queue[Q->front];
    }
}

int front(QueueType* Q) {
    if (isempty(Q) == true) { // 큐가 비어있다면
        return -1;
    }
    else
        return Q->Queue[Q->front + 1];
}

int back(QueueType* Q) {
    if (isempty(Q) == true)
        return -1;
    else
        return Q->Queue[Q->rear];
}

void add_edge(GraphType* g, int A, int B) {
    g->adj_list[A].push_back(B);
    g->adj_list[B].push_back(A); // 무방향 그래프일 경우
}

bool bfs_check(GraphType* g, vector<int>& sequence, QueueType* Q) {
    if (sequence[1] != 1) return false; // 첫 번째 정점이 1이 아닌 경우
    vector<int> visited(g->N + 1, 0);

    visited[1] = 1;

    int idx = 2; // sequence 배열의 인덱스

    while (!isempty(Q)) {
        int curr = pop(Q);
        

        // 현재 노드에 연결된 노드들 중, 방문하지 않은 노드들을 찾음
        vector<int> children;
        for (int next : g->adj_list[curr]) {
            if (!visited[next]) {
                visited[next] = 1;
                children.push_back(next);
            }
        }

        // sequence 배열에서 현재 순서에 맞게 큐에 넣은 순서를 확인
        for (int i = 0; i < children.size(); i++) {
            if (idx > g->N || find(children.begin(), children.end(), sequence[idx]) == children.end()) {
                return false; // 올바르지 않은 순서
            }
            push(sequence[idx], Q);
            idx++;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL); //입출력 묶음 해제
    ios_base::sync_with_stdio(false);

    int N; // 정점의 수
    cin >> N;

    QueueType* Q = new QueueType;
    GraphType* g = new GraphType;
    Q->Queue = new int[N + 2];

    init(Q, g, N);

    int A, B; // 정점 A와 B의 간선정보

    for (int i = 1; i <= N - 1; i++) {
       cin >> A >> B;
       add_edge(g, A, B);
    }

    vector<int> sequence(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> sequence[i];

    int flag = 0;
    if (sequence[1] != 1) {
        flag = 1;
    }
    //1 2 3
    //2 4 5
    //3 6 7

    vector<int> depth(g->N + 1, -1); // 깊이를 저장할 배열
    depth[1] = 1;
    push(1, Q);
    

    if (bfs_check(g, sequence, Q))
        cout << 1;
    else
        cout << 0;

    delete[] g->adj_list;
    delete g;

}