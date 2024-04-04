#include <iostream>

#define MAX_SIZE 1001
#define MAX_QUEUE_SIZE 1001
#define TRUE 1
#define FALSE 0
using namespace std;

typedef int element;

typedef struct {
	int n; // 그래프의 크기
	int adj_mat[MAX_SIZE][MAX_SIZE];
}GraphType;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init(GraphType* g) {
	g->n = 0;
	int r, c;
	for (r = 0; r < MAX_SIZE; r++) {
		for (c = 0; c < MAX_SIZE; c++)
			g->adj_mat[r][c] = 0;
	}
}

void insert_vertex(GraphType* g) {
	if ((g->n) + 1 > MAX_SIZE) {
		perror("정점 개수 초과");
		exit(1);
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start > g->n || end > g->n) {
		perror("정점 번호 오류");
		exit(1);
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs(GraphType* g, int V, int* visited) {
	
	visited[V] = TRUE; // 정점 방문 완료
	cout << V << " ";
	int w;
	for (w = 1; w <= g->n; w++) {
		if (visited[w] != TRUE && g->adj_mat[V][w] == 1) {			
			dfs(g, w, visited);
		}
	}
}

void error(char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}

void queue_init(QueueType* q) { 
	q->front = 0;
	q->rear = 0;
} // 큐 초기화

int qis_empty(QueueType* q) {
	return q->front == q->rear;
} // 참 또는 거짓의 논리값 반환

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
} // 큐 포화 상태

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		perror("큐가 포화 상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
} // 재사용 못하는 큐다

element dequeue(QueueType* q) {
	if(qis_empty(q))
		perror("큐가 비어 있습니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void bfs(GraphType* g, int V, int* bfsvisit) {
	QueueType q;
	queue_init(&q); // 큐 초기화
	int w;
	cout << V << " ";
	bfsvisit[V] = TRUE; // 정점 방문 완료
	enqueue(&q, V); // 큐에 정점 V 삽입 
	while (!qis_empty(&q)) {
		V = dequeue(&q);
		for (w = 1; w <= g->n; w++) {
			if (g->adj_mat[V][w] == 1 && bfsvisit[w] != TRUE) {
				bfsvisit[w] = TRUE;
				cout << w << " ";
				enqueue(&q, w);
			}
		}
	}
}

int main() {
	GraphType* g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	int N, M, V; // 정점 개수, 간선 개수, 시작 정점

	cin >> N >> M >> V;
	int a, b;

	for (int i = 0; i < N; i++) {
		insert_vertex(g); // 정점 생성
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		insert_edge(g, a, b); // 정점 연결
	}
	int* visited = new int[g->n + 2]; // 정점 개수 만큼 방문 여부 배열 생성
	dfs(g, V, visited); // DFS 수행 결과
	cout << endl;
	int* bfsvisit = new int[g->n + 2];
	bfs(g, V, bfsvisit); // BFS 수행 결과

	free(g);
	return 0;
}