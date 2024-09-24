#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
	return (a.first == b.first) ? a.second < b.second : a.first < b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> startv;
	vector<pair<int, int>> endv;

	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		startv.push_back(pair<int, int>(start, end));
		endv.push_back(pair<int, int>(start, end));
	}

	sort(startv.begin(), startv.end(), compare);
	sort(endv.begin(), endv.end(), compare2);
	
	bool* visited = new bool[N + 1];
	int starttime, endtime;

	visited[0] = true;
	starttime = startv[0].first; // 시작 시간
	endtime = startv[0].second; // 끝나는 시간
	int count = 0;
	int endpoint = 1;

	/*
	int nextstime = 0;
	int nextetime = 0;
	int Idx = 1;
	int flag = 0;
	int q = 0;
	int flag2 = 0;
	
		for (int i = Idx; i < N; i++) {

			if (visited[i] != true && endtime <= startv[i].first) {
				//cout << "현재 방문.." << startv[i].first << " " << startv[i].second << "\n";
				visited[i] = true;
				endpoint= endpoint+1;
				//cout << endpoint << "\n";
				starttime = startv[i].first; // 시작 시간 // 새로운 설정
				endtime = startv[i].second; // 끝나는 시간 -> 새로운 설정
				startv.erase();
				if (flag2 == 0) {
					count++;
				}
				flag2 = 1;
			}
			else if ((visited[i] != true && endtime > startv[i].first) && flag==0) {
				//cout << "현재 방문.." << startv[i].first << " " << startv[i].second << "\n";
				flag = 1; // for문에서 처음 단 한번만 실행되는 구문
				Idx = i;
			}
			if (i == N - 1) {
				i = Idx-1;
				flag2 = 0;
				flag = 0;
				starttime = 0;
				endtime = 0;
			}
			if (endpoint == N)
				break;
		}
	std::cout << count;
	*/
	//vector<int>::iterator it;
	vector<int> v;
	v.push_back(startv[0].second);
	//it = v.begin();
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(startv[0].second);

	for (int i = 1; i < N; i++) {
		if (q.top() <= startv[i].first) { // 현재 끝나는 시간 보다 다음 시작하는 시간이 크거나 같아서 시작할 수 있는 경우
			//cout << "POP : " << startv[0].second << "\n";
			q.pop();
			//cout << "PUSH : " << startv[i].second << "\n";
			q.push(startv[i].second);
			//v.push_back(startv[i].second);
		}
		else if(q.top() > startv[i].first) { // 현재 끝나는 시간 보다 다음 시작하는 시간이 작아서 새로운 시작 혹은 다른 강의실에서 진행하는 경우
			//v.push_back(startv[i].second);
			//cout << "push : " << startv[i].second << "\n";
			q.push(startv[i].second);
		}

	}
	
	cout << q.size();
}