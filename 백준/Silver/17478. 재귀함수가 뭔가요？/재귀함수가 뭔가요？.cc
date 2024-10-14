#include <iostream>

using namespace std;
void dot(int depth) {
	for (int i = 1; i <= depth * 4; i++) {
		cout << "_";
	}
}
void end(int depth) {
	dot(depth);
	cout << "\"재귀함수가 뭔가요?\"\n";
	dot(depth);
	cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
}

void show(int N, int depth) {
	dot(depth);
	cout << "\"재귀함수가 뭔가요?\"\n";
	dot(depth);
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	dot(depth);
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	dot(depth);
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	
	if (depth == N-1) {
		end(depth+1);
		dot(depth + 1);
		cout << "라고 답변하였지.\n";
	}
	else {
		show(N, depth + 1);
	}
	dot(depth);
	cout << "라고 답변하였지.\n";
}

int main() {
	int depth;
	cin >> depth; // 재귀 횟수
	
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	show(depth, 0);
}