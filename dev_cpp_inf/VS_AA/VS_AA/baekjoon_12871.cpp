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

	vector<string> str;
	for (int i = 0; i < 2; ++i)
	{
		string temp;
		cin >> temp;
		str.push_back(temp);
	}
	if(str[0].length() <= str[1].length())
	{
		if (str[1].find(str[0].c_str()) == string::npos)
			cout << 0 << endl;
		else
		{
			if(str[0].back() == str[1].back())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}

	}
	else if (str[0].length() > str[1].length())
	{
		if (str[0].find(str[1].c_str()) == string::npos)
			cout << 0 << endl;
		else
		{
			if (str[0].back() == str[1].back())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	
	return 0;
}
