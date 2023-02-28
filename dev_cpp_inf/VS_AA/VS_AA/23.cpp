#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	/*FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);*/

	int N = 0, temp = 0, result = 1, max = -2730000; //N개의 숫자가 나열된 수열
	
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	//값이 같을 때는 증가로 판단
	for (int i = 0; i < N - 1; ++i)
	{
		if (vec[i] > vec[i + 1])
		{
			result = 1;
		}
		else
		{
			++result;
		}

		if (max < result)
		{
			max = result;
		}
	}

	cout << max << endl;
	return 0;
}