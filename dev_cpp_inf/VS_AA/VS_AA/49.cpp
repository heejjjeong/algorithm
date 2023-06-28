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
	int n, temp, total = 0;
	cin >> n;
	vector<vector<int>> vec(2, vector<int>(n, 0)); //input 받는 용도
	vector<vector<int>> res(n, vector<int>(n, 0)); //결과 받는 용도

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> temp;
			vec[i][j] = temp;
		}
	}
	
	/*
	2 3 0 1
	2 3 0 1
	2 3 0 1
	2 3 0 1
	*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			res[i][j] = vec[0][j];
		}
	}
	
	/*
	 1 1 2 3
	 4행과 0인덱스부터 검사해서 현재 값보다 크면 현재 값으로 만들어줌
	 res[3][3] 과 vec[1][0] 를 비교해서 vec보다 res가 더 크면 res 값을 vec으로 만들어줌
	 res[3][2] vec[1][0]
	 res[3][1] vec[1][0]
	 res[3][0] vec[1][0]

	 res[2][3] vec[1][1]
	 */
	for (int i = 0; i < n; ++i) // 0~3
	{
		for (int j = n - 1; j >= 0; --j) //3~
		{
			if (res[n - 1 - i][j] > vec[1][i])
			{
				res[n - 1 - i][j] = vec[1][i];
			}

			total += res[n - 1 - i][j];
		}
	}

	cout << total << endl;
	return 0;
}