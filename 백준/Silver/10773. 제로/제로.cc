#include <iostream>
#include <stack>

using namespace std;

int main() {
	int K;
	cin >> K;

	stack<int> s;
	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0) {
			//cout << s.top() << " 이 빠짐";
			s.pop();
		}
		else {
			s.push(num);
		}
	}
	
	int sum = 0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		//cout << "현재 " << i << "에서는 " << s.top() << "\n";
		sum = sum + s.top();
		s.pop();
		if (s.size() == 0)
			break;
	}

	cout << sum;
}