#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	
	vector<bool> vec;
	for(int i = 1; i < n; ++i)
	{
		vec.push_back(false);
	}
	vec[0] = true;
	for(int i = 2; i <= sqrt(n); ++i)
	{
		for(int j = i * 2; j <= n; j += i)
		{
			vec[j] = true;
		}
	}

	int temp = 0;
	for(int i = 2; i <= n; ++i)
	{
		if(false == vec[i])
		{
			++temp;
		}
	}
	cout << temp <<endl;
	return 0;
}



