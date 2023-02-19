#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//분노 유발자 김청
int main()
{
	//FILE* stream;
	//errno_t err;
	//
	//freopen_s(&stream, "input.txt", "r", stdin);

	int n = 0, sum = 0, max = -1;
	cin >> n;

	vector<int> Height;
	Height.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;

		Height.push_back(temp);
	}
	int i,j;
	for (i = n - 1; i > -1 ; --i)
	{
		for (j = i - 1; j > -1; --j)
		{
			if (Height[j] > Height[i])
			{
				sum++;
				i = j + 1;
				break;
			}
			if (j == 0)
			{
				i = j;
			}
		}
	}
	cout << sum << endl;

	return 0;
}