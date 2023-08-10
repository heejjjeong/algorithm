#include <stdio.h>
#include <iostream>
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
	int n, m, dist = 0, p1 , p2;
	cin >> n >> m;
	vector<vector<int>> vec(n + 1, vector<int>(n + 1));
	for (int i = 1; i < m + 1; ++i)
	{
		cin >> p1 >> p2 >> dist;
		vec[p1][p2] = dist;
	}

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}