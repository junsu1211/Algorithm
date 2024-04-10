#include <iostream>
#include <stack>
#define MAX_SIZE 100000
#define TRUE 1
#define FALSE 0
using namespace std;

typedef struct GraphNode{
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode* adj_list[MAX_SIZE];
}GraphType;

void init(GraphType* g, int num) { // 그래프 초기화
	int v;
	g->n = num;
	for (v = 0; v< MAX_SIZE; v++)
		g->adj_list[v] = NULL; // 그래프의 인접 리스트 초기화
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_SIZE) {
		fprintf(stderr, "정점 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u > g->n || v > g->n) {
		fprintf(stderr, "정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v; // ex) 1,3 -> vertex = 3

	node->link = g->adj_list[u]; // 3에 link된 1을 저장 -> 3과 1은 연결된 상태
	g->adj_list[u] = node; // 노드들을 저장한 배열 1에 3에대한 그래프 노드 정보를 저장

	GraphNode* n;
	n = (GraphNode*)malloc(sizeof(GraphNode));
	n->vertex = u; // ex) 1,3 -> vertex = 3

	n->link = g->adj_list[v]; // 3에 link된 1을 저장 -> 3과 1은 연결된 상태
	g->adj_list[v] = n; // 노드들을 저장한 배열 1에 3에대한 그래프 노드 정보를 저장


}

int visited[MAX_SIZE];

int parent[100001] = { 0 };

void dfs_list(GraphType* g, int v) {
	
	GraphNode* w;
	visited[v] = TRUE;
	
	for (w = g->adj_list[v]; w; w = w->link) {
		if (!visited[w->vertex]) {
			parent[w->vertex] = v;
			dfs_list(g, w->vertex);
		}
	}
}


int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num; // 노드의 개수
	
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	init(g,num);

	int u, v;
	for (int i = 1; i < num; i++) {
		cin >> u >> v;
		insert_edge(g, u, v);
		//insert_edge(g, v, u);
	}

	dfs_list(g, 1);

	for (int i = 2; i <= num; i++) {
		cout << parent[i] << "\n";
	}
	free(g);
}
