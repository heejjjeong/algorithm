#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define TEST

int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif

	int n, i, temp, Cnt = 0, digit;

	cin >> n;

	for (i = 1; i <= n; ++i)
	{
		temp = i;
		while (temp > 0)
		{
			digit = temp % 10;
			if (3 == digit)
			{
				++Cnt;
			}
			temp = temp / 10;
		}
	}

	cout << Cnt << endl;
	
	return 0;
}