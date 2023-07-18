#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void recursive(int x)
{
	if (0 == x)
		return;
	else
	{
		recursive(x / 2);
		cout << x % 2;
	}
}
//#define TEST
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