#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define TEST

int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int n, temp = 0;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	//for (int i = 0; i < n ; ++i)
	//{
	//	if (0 > vec[i]) // minus
	//	{
	//		for (int j = 0; j < i ; ++j)
	//		{
	//			if (vec[i - j - 1] > 0 && vec[i - j] < 0)
	//			{
	//				temp = vec[i - j];
	//				vec[i - j] = vec[i - j - 1];
	//				vec[i - j - 1] = temp;
	//			}
	//		}
	//	}
	//}
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (0 < vec[j] && 0 > vec[j + 1])
			{
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";
	}

	return 0;
}
