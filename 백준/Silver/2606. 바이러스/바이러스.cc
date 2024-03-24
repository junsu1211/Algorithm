#include <iostream>
#include <stdlib.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

using namespace std;

typedef struct GraphType {
	int n; // 정점의 개수
	int adj_mat[MAX_VERTICES+1][MAX_VERTICES+1];
}GraphType;

int visited[MAX_VERTICES+1];

void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r <= MAX_VERTICES; r++)
		for (c = 0; c <= MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "정점의 개수 초과");
		return;
	}
	g->n++; // 정점의 개수 추가
}

void insert_edge(GraphType* g, int start, int end) {
	if (start > g->n || end > g->n) {
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

int dfs_mat(GraphType* g, int v, int count) {
	int w;
	visited[v] = TRUE; // 정점 방문 여부
	//cout << "정점 " << v << " -> ";
	for (w = 1; w <= g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) {
			count++;
			count = dfs_mat(g, w, count);
		}
	}
	return count;
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	int t = 0;
	int count = 0;
	init(g);

	int computenum; // 컴퓨터의 개수
	cin >> computenum;
	for (int i = 1; i <= computenum; i++)
		insert_vertex(g, i);

	int twinnum; // 쌍의 개수
	cin >> twinnum;
	int a, b; // 엣지를 생성할 쌍의 넘버

	for (int i = 1; i <= twinnum; i++) {
		cin >> a >> b;
		insert_edge(g, a, b);
	}
	count = dfs_mat(g, 1, count);
	cout << count;
}