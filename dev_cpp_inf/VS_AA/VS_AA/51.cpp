#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

//#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int temp, h, w, myh, myw, mywtemp, max = 0, cnt = 0;
	cin >> h >> w;
	vector<vector<int>> dy(h + 1, vector<int>(w + 1, 0));
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> temp;

			dy[i][j] = dy[i - 1][j] + dy[i][j - 1] - dy[i - 1][j - 1] + temp;

		}
	}

	cin >> myh >> myw;
	////////////////////

	for (int i = myh; i <= h; ++i)
	{
		for (int j = myw; j <= w; ++j)
		{	
			temp = dy[i][j] - dy[i - myh][j] - dy[i][j - myw] + dy[i - myh][j - myw];
			if (max < temp)
			{
				max = temp;
			}
		}
	}

	cout << max;
	return 0;
}