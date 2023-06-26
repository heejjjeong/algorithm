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
	int n, temp, cnt = 0;
	cin >> n;

	vector<vector<int>> vec(n + 2, vector<int>(n + 2, 0));
	int a[4] = { -1,0,1,0 }, b[4] = { 0,-1,0,1 };

	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 1; j <= n ; ++j)
		{
			cin >> temp;
			vec[i][j] = temp;
		}
	}
	//-------------------
	bool check = false;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			check = false;
			for (int k = 0; k < 4; ++k)
			{
				if (vec[i + a[k]][j + b[k]] >= vec[i][j])
				{
					check = true;
					continue;
				}
			}

			if (!check)
				cnt++;
		}
	}

	/*for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (vec[i - 1][j] < vec[i][j] && vec[i][j - 1] < vec[i][j] &&
				vec[i + 1][j] < vec[i][j] && vec[i][j + 1] < vec[i][j])
			{
				++cnt;
			}
		}
	}*/
	cout << cnt;
	return 0;
}