#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
//사실은 쓰리포인터로 풀었어야했던것이었다..

//#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int n, p2 = 1, p3 = 1, p5 = 1, temp = 1;
	vector<int> vec(1501,0);
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		vec[i] = temp;

		int numP2 = vec[p2] * 2;
		int numP3 = vec[p3] * 3;
		int numP5 = vec[p5] * 5;

		if (numP2 < numP3 && numP2 < numP5)
		{
			temp = vec[p2++] * 2;
			continue;
		}
		else if (numP3 < numP2 && numP3 < numP5)
		{
			temp = vec[p3++] * 3;
			continue;
		}
		else if (numP5 < numP2 && numP5 < numP3)
		{
			temp = vec[p5++] * 5;
			continue;
		}

		if (numP2 == numP3 && numP2 == numP5)
		{
			temp = vec[p2++] * 2;
			p3++;
			p5++;
			continue;
		}
		else if (numP2 == numP3)
		{
			temp = vec[p2++] * 2;
			p3++;
			continue;
		}
		else if (numP2 == numP5)
		{
			temp = vec[p2++] * 2;
			p5++;
			continue;
		}
		else if (numP3 == numP5)
		{
			temp = vec[p3++] * 3;
			p5++;
			continue;
		}
	}
	cout << vec[n];
	return 0;
}