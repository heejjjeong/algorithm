#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
int mystack[1000] = {};
int top = 0;

void push(int n)
{
	mystack[++top] = n;
}
int pop()
{
	return mystack[top--];
}
*/

#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int n, k, div = 0;
	char str[16] = { '0','1','2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'A' ,'B' ,'C' ,'D' ,'E' ,'F' };
	cin >> n >> k;
	div = n;

	/*top = -1;
	while (div > 0)
	{
		push(div % k);
		div = div / k;
	}
	while (top >= 0)
	{
		cout << str[pop()];
	}*/

	stack<int> stk;

	div = n;
	while (div > 0)
	{
		stk.push(div % k);
		div /= k;
	}

	int size = stk.size();
	for (int i = 0; i < size; ++i)
	{
		cout << str[stk.top()];
		stk.pop();
	}

	return 0;
}