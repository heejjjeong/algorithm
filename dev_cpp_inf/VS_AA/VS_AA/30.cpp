#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//#define TEST

int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	
	int n, left = -1, right = 0, k = 1, cur, cnt = 0;
	cin >> n;
	while (0 != left)
	{
		left = n / (k * 10);
		cur = (n / k) % 10;
		right = n % k;

		if (3 < cur)
		{
			cnt += (left + 1) * k;
		}
		else if (3 > cur)
		{
			cnt += left * k;
		}
		else //3 == cur
		{
			cnt += (left * k) + (right + 1);
		}

		k *= 10;
	}

	cout << cnt << endl;
	return 0;
}