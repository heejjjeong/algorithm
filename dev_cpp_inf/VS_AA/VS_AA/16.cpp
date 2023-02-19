#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	string str1, str2;
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
	}
	return 0;
}



