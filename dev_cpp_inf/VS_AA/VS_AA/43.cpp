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
	/*
	이분검색 결정알고리즘
	결정 알고리즘 : 답을 정해두고 답이 맞는지 아닌지 좁혀 나아가는 알고리즘
	좁혀 나아가는 과정에서 이분 검색을 사용한다. 

	<풀이과정>
	1~sum까지의 길이중에 정답이 있다
	sum+1 ( 답이 나올수 있는 전체 가짓 수 )
	sum+1을 2로 나눈 값(mid)에 몇개의 dvd가 만들어 지는지 이분 검색을 시작
	개수가 나왔을때 m보다 같거나 작으면 sum+1을 2로 나눈 값(mid)을 저장해둔다.
	그리고 해당 값의 -1로 right를 변경한다.
	m보다 큰 값이 나온다면 해당 값의 +1로 left를 변경한다.
	여기서 -1과 +1을 하는 이유는 해당 값은 이미 확인을 했기 때문에 다시 할 필요가 없기 때문
	계속 반복하다가 left와 right가 같아지는 경우에 최종 저장되어 있는 값을 출력한다.
	
	*/

	int n, m, temp, lt, rt, mid, sum = 0, sumTemp = 0, cnt = 0, res = 0;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec[i] = temp;
		sum += temp;
	}

	/*
	lt = 1;
	rt = sum;
	mid = (rt + lt) / 2;

	while (lt <= rt) 
	{
		mid = (rt + lt) / 2;
		cnt = 0;

		for (i = 0; i < n; ++i)
		{
			sumTemp += vec[i];

			if (sumTemp > mid) //누적해서 더한 수가 mid보다 크다면
			{
				++cnt;
				sumTemp = vec[i];
			}
			else if (sumTemp == mid) //누적해서 더한 수가 mid보다 크다면
			{
				++cnt;
				sumTemp = 0;
			}
		}

		if (sumTemp > 0 )
		{
			++cnt;
			sumTemp = 0;
		}

		if (cnt <= m)
		{
			res = mid;
			rt = mid - 1;
		}
		else
		{
			lt = mid + 1;
		}
	}


	cout << res;
	*/
	return 0;
}
