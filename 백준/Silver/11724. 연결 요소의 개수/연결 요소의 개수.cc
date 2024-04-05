#include <iostream>
#define MAX_SIZE 1001
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct {
	int n;
	int adj_mat[MAX_SIZE][MAX_SIZE];
}GraphType;

void init(GraphType* g) {
	g->n = 0;
	int r, c;
	for (r = 0; r < MAX_SIZE; r++) {
		for (c = 0; c < MAX_SIZE; c++) {
			g->adj_mat[r][c] = FALSE;
		}
	}
}

void insert_edge(GraphType* g, int start, int end) {
	if (end > g->n || start > g->n) {
		perror("간선 오류");
		exit(1);
	}
	g->adj_mat[start][end] = TRUE;
	g->adj_mat[end][start] = TRUE;
}

void insert_node(GraphType* g) {
	if ((g->n) + 1 > MAX_SIZE) {
		perror("정점 개수 초과");
		exit(1);
	}
	g->n++; // 정점 개수 추가
}

void dfs(GraphType* g, int searchstart, int* visited) {
	visited[searchstart] = TRUE; // 정점 방문했음
	int c;
	for (c = 1; c <= g->n; c++) {
		if (g->adj_mat[searchstart][c] == TRUE && visited[c] != TRUE) {
			dfs(g, c, visited);
		}
	}
}
int main() {
	int N, M; // N은 정점의 개수, M은 간선의 개수
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType)); // 그래프 메모리 할당
	init(g); // 그래프 초기화

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		insert_node(g); //노드 추가

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end; // 간선의 양 끝 점 
		insert_edge(g, start, end); // 간선 삽입
	}

	int* visited = new int[MAX_SIZE]; // 방문 여부 배열
	int searchstart=0; // 탐색 시작점

	for (int r = 1; r <= M; r++) {
		for (int c = 1; c <= M; c++) {
			if (g->adj_mat[r][c] == TRUE)
				searchstart = r;
		}
	}// 탐색 시작점 찾기
	int count = 0;
	for (int c = 1; c <= g->n; c++) {
		if ( visited[c] != TRUE) { // 방문한 적이 없으면
			dfs(g, c, visited);
			count++;
		}
	}
	cout << count;

	/*for (int r = 1; r <= M; r++) {
		for (int c = 1; c <= M; c++) {
			cout << g->adj_mat[r][c];
		}
		cout << endl;
	}*/

}