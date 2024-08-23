#include <iostream>

using namespace std;

typedef struct Treetype {
	int N;
	char name;
	Treetype* leftchild;
	Treetype* rightchild;
}Treetype;

void front(Treetype* T) {
	cout << T->name;
	
	if (T->leftchild != NULL) {
		//cout << T->leftchild->name << "호출\n";
		front(T->leftchild);
	}

	if (T->rightchild != NULL) {
		//cout << T->rightchild->name << "호출\n";
		front(T->rightchild);
	}

}

void middle(Treetype* T) {
	if (T->leftchild != NULL) {
		middle(T->leftchild);
	}
	cout << T->name;
	if (T->rightchild != NULL) {
		middle(T->rightchild);
	}
}

void back(Treetype* T) {
	if (T->leftchild != NULL) {
		back(T->leftchild);
	}
	if (T->rightchild != NULL) {
		back(T->rightchild);
	}
	cout << T->name;
}
int main() {
	int N; // 이진 트리의 노드의 개수
	cin >> N;

	Treetype** T = new Treetype * [N + 1]; // 각 구조체 생성
	for (int i = 1; i <= N; i++)
		T[i] = new Treetype;

	char root = 'A';
	T[1]->name = root;
	T[1]->N = 1; // 실제 순서

	for (int i = 2; i <= N; i++) {	
		T[i]->name = root + i - 1;
	}

	char x, y, z;
	int now = 0;

	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> z;

		for (int r = 1; r <= N; r++) { // 현재 방문 노드의 번호를 찾아야함
			if (T[r]->name == x) {
				now = r;
				break;
			}
		}

		if (y == '.') {
			T[now]->leftchild = NULL;
		}
		if (z == '.') {
			T[now]->rightchild = NULL;
		}

		for (int t = 1; t <= N; t++) {

			if (T[t]->name == y) {
				T[now]->leftchild = T[t];

				//if (T[now]->N != 0)
					//T[now]->leftchild->N = T[now]->N * 2;
			}

			if (T[t]->name == z) {
				T[now]->rightchild = T[t];

				//if (T[now]->N != 0)
					//T[now]->rightchild->N = T[now]->N * 2 + 1;
			}


		}

	}

	front(T[1]);
	cout << "\n";
	middle(T[1]);
	cout << "\n";
	back(T[1]);
}