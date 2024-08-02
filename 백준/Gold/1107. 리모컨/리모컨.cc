#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

int plus(int X) { // + 버튼
	X++;
	return X;
}

int minu(int X) { // - 버튼
	X--;
	return X;
}

bool test(int A, int B) { // 두 숫자가 같은지 판별하는 함수
	if (A == B) {
		return true;
	}
	else {
		return false;
	}
}

int comparison(int A, int B) { // 더 작은 수를 반환
	if(A < B)
		return A;
	else
		return B;
}

int main() {
	string N; // 이동하려는 채널
	cin >> N;

	int Ch[7];
	for (int i = 1; i <= N.size(); i++) {
		Ch[i] = N[i - 1] - '0';
	}
	int resbtn = 0;
	int a = 1;

	for (int i = N.size(); i >= 1; i--) {
		resbtn = resbtn + (Ch[a] * pow(10, i - 1));
		a++;
	}

	

	int M; // 고장난 버튼 개수
	cin >> M; 
	bool btn[11];

	for (int i = 0; i <= 9; i++) {
		btn[i] = true;
	}

	int* nch = new int[M + 1];
	for (int i = 1; i <= M; i++) {
		cin >> nch[i];
		btn[nch[i]] = false; // 고장난 버튼들 false로 교체
	}

	int startbtn = 100; // 시작 채널
	
	int count = 0;
	int result = 15;
	int wrub = 0;
	int wrdb = 0;
	int notwb = 0;

	if (M == 10) { // 고장난 버튼이 10개이면 수작업으로 하는 코드 작성해야됨
		if (resbtn >= 100) {
			cout << resbtn - 100;
		}
		else if (resbtn < 100) {
			cout << 100 - resbtn;
		}
		
	}
	else if (M == 0) {
		if (resbtn <= 100)
			cout << comparison(N.size(), 100 - resbtn);
		else
			cout << comparison(N.size(), resbtn - 100);
	}
	else {
		// 100주변의 버튼을 3번 이상 누르는 것보다 + - 버튼으로 누르는 경우에 대한 코드 작성해야됨
		if (resbtn <= 103 && resbtn >= 100) { // +, - 버튼이 더 빠름
			cout << resbtn - 100;
		}
		else if (resbtn >= 97 && resbtn < 100) {
			cout << 100 - resbtn;
		}
		else { // 버튼을 눌러서 일정 수로 이동한 후 +, - 버튼으로 도착하는 경우 

			/*
			// 직접 버튼을 누르는 경우임
			for (int i = 1; i <= N.size(); i++) {
				// 가장 앞자리부터 맞추는 것이 맞음
				//cout << "현재 버튼 : " << Ch[i] << "입니다..\n";

				if (btn[Ch[i]] == true) { // 고장나지 않아서 누를 수 있는 버튼이면
					//cout << Ch[i] << " 고장나지 않은 버튼이라 그냥 누름..\n";
					count = count + 1;;
				}
				else if (btn[Ch[i]] == false) { // 고장난 버튼이면
					//cout << Ch[i] << " 는 고장난 버튼임..\n";
					result = 15;
					wrdb = Ch[i];

					for (int t = 0; t <= 9; t++) {
						if (t < Ch[i] && btn[t] == true) { // 갈 수 있는 버튼이고, 현재 버튼보다 작은 경우
							result = comparison(result, Ch[i] - t);
							if (result == Ch[i] - t)
								wrdb = t;
						}
						else if (t > Ch[i] && btn[t] == true) {
							result = comparison(result, t - Ch[i]);
							if (result == t - Ch[i])
								wrdb = t;
						}
					}
					Ch[i] = wrdb;
					count = count + 1;

				}
				cout << Ch[i] << " 이 바뀐 번호임..\n";
			}

			int newbtn=0;
			a = 1;

			for (int i = N.size(); i >= 1; i--) {
				newbtn = newbtn + ( Ch[a] * pow(10, i-1) );
				a++;
			}
			//cout << newbtn;

			while (newbtn != resbtn) { // + , - 버튼을 이용해 목적지에 도착한 경우
				if (newbtn > resbtn) {
					newbtn = newbtn - 1;
					count++;
				}
				else {
					newbtn = newbtn + 1;
					count++;
				}
			}
			*/
			int flag = 1;
			string s;
			int upb = resbtn - 1;
			int dwb = resbtn + 1;
			string j;
			int s_size = to_string(upb).size();
			int j_size = to_string(dwb).size();

			while (flag) {
				// 여기부턴 감소하는 수

				flag = 0;
				dwb = dwb - 1; // 1 감소

				j = to_string(dwb);
				count = j.size();

				for (int i = 0; i < j.size(); i++) {

					if (btn[j[i] - '0'] == false) { // 하나라도 고장난 버튼이 있으면
						flag = 1;
						break;
					}
				}

				a = 0;
				dwb = 0;
				for (int i = j.size(); i >= 1; i--) { // 다시 숫자로
					dwb = dwb + ((j[a] - '0') * pow(10, i - 1));
					a++;
				}
				//cout << "다시 숫자로 변환 " << resbtn << "\n";
				//cout << dwb;
				if (flag == 0) {
					//cout << "가장 가까운 수는 : " << dwb << "입니다..\n";
					result = resbtn - dwb;
					if (dwb >= 0) {
						break;
					}
				}
				// 고장난 버튼이 하나도 없으면 종료됨

				flag = 0;	
				
				upb = upb + 1; // 1 증가
				
				s = to_string(upb);
				count = s.size();

				for (int i = 0; i < s.size(); i++) {

					if (btn[s[i] - '0'] == false) { // 하나라도 고장난 버튼이 있으면
						flag = 1;
						break;
					}
				}
				a = 0;
				upb = 0;
				for (int i = s.size(); i >= 1; i--) { // 다시 숫자로
					upb = upb + ((s[a] - '0') * pow(10, i - 1));
					a++;
				}
				//cout << "다시 숫자로 변환 " << resbtn << "\n";
				if (flag == 0) {
					//cout << "가장 가까운 수는 : " << upb << "입니다..\n";
					result = upb - resbtn;
					break;
				}
				



			}

			count = count + result;
			
			if (resbtn >= 104) {
				cout << comparison(count, resbtn - 100);
			}
			else if (resbtn <= 96 )
				cout << comparison(count, 100 - resbtn);

			
		}
	}
	// 최종적으로 한번 더 비교



	//	cout << count;

}