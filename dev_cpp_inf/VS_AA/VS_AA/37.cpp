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
	//�������ķ� Ǫ�� ����
	int n, s, temp, pos;

	cin >> s; //5
	vector<int> cache(s);
	cin >> n; //9

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		bool check = false;
		pos = -1;
		for (int j = 0; j < s; ++j)
		{
			if (temp == cache[j]) // ĳ�� ������ 
			{
				check = true;
				pos = j;
				break;
			}
		}

		int j = check ? pos : s - 1; //check true : ĳ����Ʈ, check false : ĳ�ù̽�
		for (; j >= 1; --j)
		{
			cache[j] = cache[j - 1];
		}
		cache[0] = temp;
	}

	for (int i = 0; i < s; ++i) //����� 5���� ��
	{
		cout << cache[i] << " ";
	}

	/*
	int s, n, temp = 0;
	cin >> s; //5
	vector<int> vec;
	cin >> n; //9

	for (int i = 0; i < n; ++i) //���ö����� �ٷιٷ� �־��ֱ�
	{
		cin >> temp;
		bool check = false;
		//���� ���� ���ٸ� �Ǿտ� insert��
		for (int j = 0; j < vec.size(); ++j)
		{
			if (temp == vec[j]) //������ �ִٸ�
			{
				check = true;
				vec.erase(vec.begin() + j); //j��ġ���� �����ϰ�
				vec.insert(vec.begin(), temp); //�տ� temp�ֱ�
			}
		}

		if (!check) //������ ������
		{
			vec.insert(vec.begin(), temp); //�տ� temp�ֱ�
		}
	}

	for (int i = 0; i < s; ++i) //����� 5���� ��
	{
		cout << vec[i] << " ";
	}
	*/
	return 0;
}
