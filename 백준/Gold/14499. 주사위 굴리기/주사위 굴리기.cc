#include <iostream>

using namespace std;
int swapn = 0;
int swapn2 = 0;
void east(int* dice, int x, int y, int** map) { // 주사위를 동쪽으로 이동

	swapn = dice[3];
	dice[3] = dice[1];
	dice[1] = dice[4];
	dice[4] = dice[6];
	dice[6] = swapn;
	

	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
}

void west(int* dice, int x, int y, int** map) { // 주사위를 서쪽으로 이동
	
	swapn = dice[6];
	dice[6] = dice[4];
	dice[4] = dice[1];
	dice[1] = dice[3];
	dice[3] = swapn;

	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
}

void north(int* dice, int x, int y, int** map) { // 주사위를 북쪽으로 이동

	swapn = dice[2];
	dice[2] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[6];
	dice[6] = swapn;
	

		if (map[x][y] == 0) {
			map[x][y] = dice[6];
		}
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
}

void south(int* dice, int x, int y, int** map) { // 주사위를 남쪽으로 이동

	swapn = dice[5];
	dice[5] = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[6];
	dice[6] = swapn;

	if (map[x][y] == 0) { // 지도의 칸이 0이면
		map[x][y] = dice[6]; //주사위 바닥면의 수를 지도로 복사
	}
	else {
		dice[6] = map[x][y]; // 그게 아니라면 지도의 수를 주사위 바닥면으로 복사
		map[x][y] = 0;
	}

}





int main() {
	int N, M, x, y, K; // 지도의 크기 N,M  // 주사위 출발 좌표 x, y // 명령의 개수 K

	cin >> N >> M >> x >> y >> K;
	x = x + 1; 
	y = y + 1;
	// 0,0이 아닌 1,1을 시작점으로 하기 위해서

	int** map = new int* [N + 1];
	for (int i = 1; i <= N; i++)
		map[i] = new int[M + 1];

	for (int i = 1; i <= N; i++) {
		for (int t = 1; t <= M; t++) {
			cin >> map[i][t];
		}
	}

	int* cmd = new int[K + 1];
	for (int i = 1; i <= K; i++) {
		cin >> cmd[i];
	}

	int dice[7]; // 주사위의 면에 써져있는 숫자
	// 1 = 윗면, 2 = 북쪽면, 3 = 동쪽면, 4 = 서쪽면, 5 = 남쪽면, 6 = 아랫면
	for (int i = 1; i <= 6; i++)
		dice[i] = 0;


	for (int i = 1; i <= K; i++) {



		if (cmd[i] == 1 && y+1 <= M) { // 동쪽으로 가는 명령
			y = y + 1;
			east(dice, x, y, map);
			cout << dice[1] << "\n";
		}
		else if (cmd[i] == 2 && y - 1 >= 1) { // 서쪽으로 가는 명령
			y = y - 1;
			west(dice, x, y, map);
			cout << dice[1] << "\n";
		}
		else if (cmd[i] == 4 && x+1 <= N) { // 남쪽으로 가는 명령
			x = x + 1;
			south(dice, x, y, map);
			cout << dice[1] << "\n";
		}
		else if (cmd[i] == 3 && x - 1 >= 1) { // 북쪽으로 가는 명령
			x = x - 1;
			north(dice, x, y, map);
			cout <<  dice[1] << "\n";
		}
		
		/*cout << "현재 " << i << "번쨰----------------------명령 수행완료----------------------\n";
			cout << dice[1] << "\n";
			cout << dice[2] << "\n";
			cout << dice[3] << "\n";
			cout << dice[4] << "\n";
			cout << dice[5] << "\n";
			cout << dice[6] << "\n";
		cout << "--------------------------------------------------\n\n";
		*/

	}
}