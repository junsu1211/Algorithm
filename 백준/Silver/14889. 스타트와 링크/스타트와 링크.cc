#include <iostream>

using namespace std;

int A = 0;
int B = 0;
int mini = 1000000000;
int sum = 0;

typedef struct Syn{
	int N;
	int value[21][21];
	int printed[21];
	bool visited[21];
}Syn;

void devide(int q, Syn* synergy, int cnt) {
	synergy->visited[q] = true; // q선수 팀으로 뽑음
	synergy->printed[cnt] = q;

	if (cnt == synergy->N / 2) {
		for (int t = 1; t <= synergy->N; t++) {
			for (int y = 1; y <= synergy->N; y++) {
				if (t != y && synergy->visited[t] == true && synergy->visited[y] == true) {
					A += synergy->value[t][y];
				}
				else if (t != y && synergy->visited[t] != true && synergy->visited[y] != true) {
					B += synergy->value[t][y];
				}
			}

		}

		/*for (int b = 1; b <= cnt; b++) {
			cout << "A팀 : " << synergy->printed[b] << "\n";
		}
		for (int w = 1; w <= synergy->N; w++) {
			if (synergy->visited[w] != true) {
				cout << "B팀 : " << w << "\n";
			}
		}
		cout << "\n";*/

		synergy->visited[q] = false;
		if (mini > abs(B - A)) {
			mini = abs(B - A);
		}
		A = 0;
		B = 0;

		return;
	}


	for (int i = q; i <= synergy->N; i++) {
		if (synergy->visited[i] != true) {
			devide(i, synergy, cnt + 1);
			synergy->visited[i] = false;
		}
	}
}



int main() {
	int N;

	cin >> N;
	Syn* synergy = new Syn;
	synergy->N = N;

	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= N; t++) {
			cin >> synergy->value[i][t];
		}
	}



	
	devide(1, synergy, 1);
	

	cout << mini;
}