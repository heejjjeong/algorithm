#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void recursive(int n)
{
	if (n > 7) 
		return;

	cout << n << " ";
	recursive(n * 2);
	recursive((n * 2) + 1);
}
//#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif

	recursive(1);
	return 0;
}