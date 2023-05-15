#include <stdio.h> 
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

//A~Z 65~90 -> count 26
//a~z 97~122 -> count 26
//total count 52

#define TEST

int a[60]; int b[60];

int main() {

#ifdef TEST
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	char ch[100];
	cin >> ch;

	for (int i = 0; ch[i] != '\0'; ++i)
	{
		if (65 <= ch[i] && 90 >= ch[i]) //대문자
		{
			++a[ch[i] - 65];
		}
		else
		{
			++a[ch[i] - 71];
		}
	}

	cin >> ch;

	for (int i = 0; ch[i] != '\0'; ++i)
	{
		if (65 <= ch[i] && 90 >= ch[i]) //대문자
		{
			++b[ch[i] - 65];
		}
		else
		{
			++b[ch[i] - 71];
		}
	}

	for (int i = 1; i <= 52; ++i)
	{
		if (a[i] != b[i])
		{
			cout << "NO" << endl;
			exit(0);
		}
	}
	cout << "YES" << endl;
	/*string str1, str2;
	cin >> str1;
	cin >> str2;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	if(str1 == str2)
	{
		cout << "YES" <<endl;
	}
	else
	{
		cout << "NO" <<endl;
	}*/
	return 0;
}



