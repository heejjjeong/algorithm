#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	
	int n = 0, temp = 0;
	vector<int> vecCard;
	cin>>n;
	
	for(int i = 0; i < n * 2; ++i)
	{
		cin >> temp;
		if(1 == temp % i)
		{
			vecCard.push_back(temp);
			
		}
	}
	
	cout << vecCard.size() <<endl;
	return 0;
}
