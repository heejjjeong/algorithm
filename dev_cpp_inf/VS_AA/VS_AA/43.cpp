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
	�̺а˻� �����˰���
	���� �˰��� : ���� ���صΰ� ���� �´��� �ƴ��� ���� ���ư��� �˰���
	���� ���ư��� �������� �̺� �˻��� ����Ѵ�. 

	<Ǯ�̰���>
	1~sum������ �����߿� ������ �ִ�
	sum+1 ( ���� ���ü� �ִ� ��ü ���� �� )
	sum+1�� 2�� ���� ��(mid)�� ��� dvd�� ����� ������ �̺� �˻��� ����
	������ �������� m���� ���ų� ������ sum+1�� 2�� ���� ��(mid)�� �����صд�.
	�׸��� �ش� ���� -1�� right�� �����Ѵ�.
	m���� ū ���� ���´ٸ� �ش� ���� +1�� left�� �����Ѵ�.
	���⼭ -1�� +1�� �ϴ� ������ �ش� ���� �̹� Ȯ���� �߱� ������ �ٽ� �� �ʿ䰡 ���� ����
	��� �ݺ��ϴٰ� left�� right�� �������� ��쿡 ���� ����Ǿ� �ִ� ���� ����Ѵ�.
	
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

			if (sumTemp > mid) //�����ؼ� ���� ���� mid���� ũ�ٸ�
			{
				++cnt;
				sumTemp = vec[i];
			}
			else if (sumTemp == mid) //�����ؼ� ���� ���� mid���� ũ�ٸ�
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
