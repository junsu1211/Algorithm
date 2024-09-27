#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main() {
	vector<int> v;
	string s;

	cin >> s;

	char startpoint = s[0];
	int num0 = 0;
	int num1 = 0;

	if (s[0] == '0')
		num0++;
	else if (s[0] == '1')
		num1++;

	for (int i = 1; i < s.size(); i++) {

		if (startpoint != s[i] && s[i] == '1') { // 연속되지 않고 1로 바뀌면
			num1++;
			startpoint = s[i];
		}
		else if (startpoint != s[i] && s[i] == '0') { // 연속되지 않고 0으로 바뀌면 
			num0++;
			startpoint = s[i];
		}
	}

	cout << min(num0, num1);
	
}