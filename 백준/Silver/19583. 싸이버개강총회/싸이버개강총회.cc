#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	string S, E, Q; // S: 시작 시간 E : 끝낸 시간 Q : 스트리밍을 끝낸 시간
	cin >> S >> E >> Q;

	//00:00 ~ S : 입장 확인
	// E ~ Q : 퇴장 확인 
	// Q를 넘기고 퇴장하면 정상 퇴장이 아님

	int startt, endt, sendt;
	startt = S[0] * 1000 + S[1] * 100 + S[3] * 10 + S[4];
	endt = E[0] * 1000 + E[1] * 100 + E[3] * 10 + E[4];
	sendt = Q[0] * 1000 + Q[1] * 100 + Q[3] * 10 + Q[4];
	// 4자리의 숫자로 시간을관리
	
	string time, nickname;
	int rtime;
	unordered_set<string> set;
	int count = 0;
	int endline = 0;

	while (endline<100000) {
		endline++;
		cin >> time >> nickname;
		rtime = time[0] * 1000 + time[1] * 100 + time[3] * 10 + time[4];
		
		if (rtime <= startt) { // 제시간 입장
			set.insert(nickname); // 등록
		}
		else if (endt <= rtime && rtime <= sendt) { // 퇴장
			auto a = set.find(nickname); //찾음
			if (a != set.end()) { // 출석부에 명단이 있으면
				set.erase(a);
				count++;
			}
		}
	}
	cout << count;
}