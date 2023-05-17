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
 	string str;
	cin >> str;

	int c = 0, h = 0, res = 0, pos, i = 0;

	if ('H' == str[1])
	{
		c = 1;
		pos = 1; //h의 position
	}
	else
	{
		for (i = 1; str[i] != 'H'; ++i)
		{
			c = c * 10 + (str[i] - 48);
		}
		pos = i;
	}
	if ('\0' == str[pos + 1])
	{
		h = 1;
	}
	else
	{
		for (int i = pos + 1; i < str.size(); ++i)
		{
			h = h * 10 + (str[i] - 48);
		}
	}

	cout << c * 12 + h << endl;

	return 0;
}

/*
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	string str;
	cin >> str;

	int num = 0, res = 0;
	string temp;
	bool isText = true;
	//C2H4 , CH4, C10H2
	for (int i = 0; i < str.size(); ++i)
	{
		if (65 <= str[i] && 90 >= str[i]) // 문자
		{
			if (!isText) //숫자돌다가 문자 만난것
			{
				int tmpNum = stoi(temp);
				res += num * tmpNum;
				temp.clear();
			}
			else //바로 문자면
			{
				res += num;
			}
			if ('C' == str[i])
				num = 12;
			else if ('H' == str[i])
				num = 1;

			if (i == str.size() - 1)
			{
				//마지막이 문자면
				res += num;
			}
			isText = true;
		}
		else //숫자
		{
			temp.push_back(str[i]);
			isText = false;

			if (i == str.size() - 1) //마지막 순번숫자면
			{
				int tmpNum = stoi(temp);
				res += num * tmpNum;
				temp.clear();

			}
		}
	}

	cout << res << endl;
	return 0;
}
*/