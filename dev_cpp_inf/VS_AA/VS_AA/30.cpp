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
	1. 1�� �ڸ��� ������ 1���� ��
	2. 1�� �ڸ��� 3���� ũ�ų� ���� 2�� �ڸ����� �Ѿ��
	   2�� �ڸ��� �ִ� �� ��ŭ ������ �ִ� �� (24�� 2��)
	3. �ٵ� 2�� �ڸ����� 3�� ������ 2�� �ڸ����ϱ� 10 ���� 
	   1�� �ڸ��� 3���� ū�� ���� 2�� �ڸ��� �ִ� �� ��ŭ ���� �ִ� ��
	   3��. 
	4. �ٵ� ���� 34 ���� ���� ���� 3�̱� ������ 2�ڸ��� 3�� 5�� �̱⶧���� 
	   1�� �ڸ��� + 1 ���ٰ� 1�� �ڸ��� 4�� �ؼ� 9��
	*/
	int n, temp, pos, cnt = 0;

	cin >> n;
	/*
	temp = n;
	while (temp > 0) //temp = 24;
	{ 
		pos = temp % 10; //pos = 4;

		if (pos > 3)
		{

		}
	}
	*/
	string str = to_string(n);
	unsigned int strSize = str.size();
	for (int i = 0; i < strSize; ++i) //strSize�ڸ��� ��� ��
	{
		int num = str[strSize - 1 - i] - '0'; // 1�� �ڸ����� ����
		if (3 <= num)
		{
			
		}

		else //less 3
		{
			strSize + i

		}

	}
	//4721
	return 0;
}