#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool demical(int num)
{
	for (int i = 2; i < num; ++i)
	{
		if (0 == num % i)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	/*FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);*/

	int N, temp = 0, mul = 1, i, j;
	cin >> N;
	
	//숫자에 맞는 소수를 먼저 구하기
	vector<int> vdemi; //N까지의 소수들
	vector<int> vcnt;  //N에 맞는 소수 개수

	for (i = 2; i <= N; ++i)
	{
		if (demical(i))
		{
			vdemi.push_back(i);
			vcnt.push_back(0);
		}
	}

	//N까지의 소수가 다 구해졌으면 N까지 순회하면서 벡터의 숫자들로 나눠서..?
	for (i = 2; i <= N; ++i)
	{
		auto num = find(vdemi.begin(), vdemi.end(), i);
		if (vdemi.end() != num) // 소수중에 해당 수가 있다면
		{
			int index = num - vdemi.begin();
			++vcnt[index];
			continue;
		}

		j = 0;
		while (vdemi[j] <= i)
		{
			if (1 == i / vdemi[j] && 0 == i % vdemi[j]) //같은 수로 나눴을 때 1이고, 나머지가 0이다 -> 같은 수다
			{
				++vcnt[j];

				break;
			}
			else if ( 0 == i % vdemi[j]) //소수로 mod연산 할 때 딱 떨어진다. 
			{
				temp = i;
				while (1 < temp / vdemi[j]) //1이 나올때까지 다시 돌림 
				{
					if (0 != temp % vdemi[j]) //계산 중에 나머지가 0이 아니게 되면 다음 숫자로 변경
					{
						++j;
						continue;
					}

					temp = temp / vdemi[j];
					++vcnt[j];

					auto num = find(vdemi.begin(), vdemi.end(), temp); //결과 몫이 소수에 있는지 찾고
					if (vdemi.end() != num)
					{
						int index = num - vdemi.begin(); //있다면 해당 인덱스의 카운트 +1
						++vcnt[index];
						break;
					}
				}
			}
			else if (0 != i % vdemi[j]) //애초부터 나머지가 0이 아니면 바로 다음 소수로 넘어감
			{
				++j;
				continue;
			}
			break;
		}
	}
	

	cout << N << "! =";
	for (i = 0; i < vcnt.size(); ++i)
	{
		cout << " " << vcnt[i];
	}
	return 0;
}