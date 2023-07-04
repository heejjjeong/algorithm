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
	vector<vector<int>> dy(h, vector<int>(w, 0));
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> temp;

			if (i == 0 && j == 0)
			{
				dy[i][j] = temp;
			}
			else if (i == 0 && j != 0)
			{
				dy[i][j] = dy[i][j - 1] + temp;
			}
			else if (i != 0 && j == 0)
			{
				dy[i][j] = dy[i - 1][j] + temp;
			}
			else if (i != 0 && j != 0)
			{
				dy[i][j] = dy[i - 1][j] + dy[i][j - 1] - dy[i - 1][j - 1] + temp;
			}
		}
	}

	cin >> myh >> myw;
	////////////////////

	for (int i = myh - 1; i < h; ++i)
	{
		for (int j = myw - 1; j < w; ++j)
		{
			if (i == myh - 1 && j == myw - 1)
			{
				max = dy[i][j];
			}
			else if (i == myh - 1 && j != myw - 1)
			{
				if (max < dy[i][j] - dy[i][j - myw])
				{
					max = dy[i][j] - dy[i][j - myw];
				}
			}
			else if (i != myh - 1 && j == myw - 1)
			{
				if (max < dy[i][j] - dy[i - myh][j])
				{
					max = dy[i][j] - dy[i - myh][j];
				}
			}
			else if (i != myh - 1 && j != myw - 1)
			{
				if (max < dy[i][j] - dy[i - myh][j] - dy[i][j - myw] + dy[i - myh][j - myw])
				{
					max = dy[i][j] - dy[i - myh][j] - dy[i][j - myw] + dy[i - myh][j - myw];
				}
			}
		}
	}

	cout << max;
	return 0;
}