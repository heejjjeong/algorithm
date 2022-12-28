#include <stdio.h> 
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	int n, result = 0;
	
	scanf("%d", n);

	int array[n] = {0,};
	int temp = 0;
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", temp);
		array[i] = temp;
	}

	
	
	printf("%d", result);
	return 0;
}


