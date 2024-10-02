#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long answer = 0;
int input;
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		while (!s.empty())
		{
			if (s.top() > input)
				break;

			s.pop();
		}

		answer += (long long)s.size();
		s.push(input);
	}


	cout << answer << endl;
	return 0;
}