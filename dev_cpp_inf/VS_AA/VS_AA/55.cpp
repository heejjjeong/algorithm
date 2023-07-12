#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

//#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int n, temp, cnt = 1;
	stack<int> step;
	string str;

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		step.push(temp);
		str += "P";
		while (true)
		{
			if (step.empty())
				break;
			if (cnt == step.top())
			{
				step.pop();
				cnt++;
				str += "O";
			}
			else 
				break;
		}
	}

	if (!step.empty())
		cout << "impossible";
	else
		cout << str;

	return 0;
}