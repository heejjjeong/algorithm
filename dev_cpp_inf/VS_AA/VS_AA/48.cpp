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
	int n = 9, temp, total = 0, min = 2147000000, res = 0;
	vector<vector<int>> vec(n, vector<int>(n, 0));
	vector<int> vecAverage;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> temp;
			vec[i][j] = temp;
			total += temp;
		}

		//반올림해서 평균 저장 하는 부분
		float Average = total / (float)n; 
		/*float gap = Average - (int)Average;
		if (gap >= 0.5f)
			total = (total / n) + 1;
		else
			total = total / n;*/
		total = Average + 0.5f;
		vecAverage.push_back(total);
		
		sort(vec[i].begin(), vec[i].end());

		for (int j = 0; j < 9; ++j)
		{
			if (min > abs(vec[i][j] - vecAverage[i]))
			{
				min = abs(vec[i][j] - vecAverage[i]);
				res = vec[i][j];
			}
			else if (min == abs(vec[i][j] - vecAverage[i]))
			{
				if (res < vec[i][j])
				{
					res = vec[i][j];
				}
			}
		}

		cout << vecAverage[i] << " " << res << endl;

		total = 0;
		min = 2147000000;
	}

	///////////////////////////////////////////
	
	

	return 0;
}