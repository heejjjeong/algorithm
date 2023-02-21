#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	//FILE* stream;
	//errno_t err;
	//
	//freopen_s(&stream, "input.txt", "r", stdin);

	int N = 0, K = 0, i = 0, j = 0,temp = 0, sum = 0;
	cin >> N >> K;
	
	vector<int> vec;
	vector<int> res;

	for (i = 0; i < N; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	for (i = 0; i < N - 1; ++i)
	{
		for (j = 0; j < K; ++j)
		{
			sum += vec[i + j];
		}
		res.push_back(sum);
		sum = 0;
	}

	int resMax = *max_element(res.begin(), res.end());
	cout << resMax << endl;
	return 0;
}