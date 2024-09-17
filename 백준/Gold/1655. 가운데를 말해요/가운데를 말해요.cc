#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int> bpq; // 작은값의 절반이 최대 힙
	priority_queue<int, vector<int>, greater<int> > mpq; // 큰 값의 절반이 최소 힙 -> 홀수인 경우 최소힙이 1개 더
	int count = 0;
	int maxHn=0, minHn=0;
	
	int input=0;
	int* array = new int[N + 1];

	cin >> input;
	mpq.push(input); // 첫번째 원소 최소힙 투입
	minHn++;
	array[0] = input;

	for (int i = 1; i < N; i++)
	{
		cin >> input;

		if (maxHn == minHn) /* 현재 짝수개인 경우 */
		{
			if (input < bpq.top())
			{
				mpq.push(bpq.top());
				bpq.pop();
				minHn++;

				bpq.push(input);
				array[i] = mpq.top();
			}
			else
			{
				mpq.push(input);
				minHn++;
				array[i] = mpq.top();
			}
		}
		else /* 현재 홀수개인 경우 */
		{
			if (mpq.top() < input)
			{
				bpq.push(mpq.top()); // 최소힙에서 최대힙으로 옮기고
				mpq.pop();
				maxHn++;

				mpq.push(input);
				array[i] = bpq.top();
			}
			else
			{
				bpq.push(input);
				maxHn++;
				array[i] = bpq.top();
			}
		}
	}

	for (int t = 0; t < N; t++)
		cout << array[t] << "\n";
	
}