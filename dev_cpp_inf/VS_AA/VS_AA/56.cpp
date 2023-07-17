#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void recursive(int x)
{
	if (x == 0)
		return;
	else
	{
		recursive(x - 1);
		cout << x << " ";
	}
}
#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int n;
	cin >> n;

	recursive(n);
	
	return 0;
}