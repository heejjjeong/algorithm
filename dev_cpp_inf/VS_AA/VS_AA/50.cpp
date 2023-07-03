#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int h, w, myh, myw;

int Count(int _h, int _w, const vector<vector<int>>& _vec)
{
	int total = 0;
	for (int i = 0; i < myh; ++i)
	{
		for (int j = 0; j < myw; ++j)
		{
			total += _vec[_h + i][_w + j];
		}
	}

	return total;
}
// #define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int temp, max = 0, cnt = 0;
	cin >> h >> w;
	vector<vector<int>> vec(h, vector<int>(w, 0));

	for (int i = 0; i < h; ++i) 
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> temp;
			vec[i][j] = temp;
		}
	}
	   
	cin >> myh >> myw;
	////////////////////

	for (int i = 0; i <= h - myh; ++i)
	{
		for (int j = 0; j <= w - myw; ++j)
		{
			int total = Count(i, j, vec);
			if (max < total)
			{
				max = total;
			}
		}
	}

	cout << max  ;
	return 0;
}