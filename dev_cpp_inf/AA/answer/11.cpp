#include <stdio.h> 

int main() {
	//freopen("input.txt", "rt", stdin);
	
	int n,  num = 0,count = 0;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i)
	{
		num = i;
		while( num > 0)
		{
			++count;
			num /= 10;
		}
	}

	printf("%d", count);
	return 0; 
}
 
