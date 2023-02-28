#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//이중 for문 사용 금지
int main()
{
	/*FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);*/

	int N = 0, K = 0, i = 0, j = 0, temp = 0, sum = 0, max = -23700000;
	cin >> N >> K;

	vector<int> vec;

	for (i = 0; i < N; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	//맨처음연속날짜누적
	for (i = 0; i < K; ++i)
	{
		sum += vec[i];
	}
	
	max = sum;

	for (i = 0; i < N - K ; ++i)
	{
		sum = sum - vec[i] + vec[i + K];

		if (max < sum)
		{
			max = sum;
		}
	}

	cout << max;

	return 0;
}