#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//FILE* stream;
	//errno_t err;
	//err = freopen_s(&stream, "input.txt", "r", stdin);
	
	int n = 0;
	cin >> n;
	
	int studentNum = 0, studentResult = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		cin >> studentNum;
		cin >> studentResult;

		for (int j = 1; j <= studentNum; ++j)
		{
			sum += j;
		}

		if (sum == studentResult)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}