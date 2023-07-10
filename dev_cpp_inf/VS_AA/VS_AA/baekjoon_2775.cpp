#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int n, k, t, sum = 0;
	vector<vector<int>> res(15, vector<int>(15, 0));

	cin >> t >> n >> k;

	while (t > 0)
	{
		for (int i = 0; i < k + 1; ++i)
		{
			res[0][i] = i;
		}
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < k + 1; ++j)
			{
				res[i][j] = res[i][j - 1] + res[i - 1][j];
			}
		}

		cout << res[n][k - 1] + res[n - 1][k] << endl;
		
		--t;
		cin >> n >> k;
	}
	
	return 0;
}