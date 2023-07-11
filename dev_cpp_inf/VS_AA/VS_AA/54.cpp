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
	stack<char> input;
	string str;
	cin >> str;
	for (auto a : str)
	{
		if (a == '(')
			input.push(a);
		else
		{
			if (!input.empty())
				input.pop();
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}

	if (input.empty())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}