#include <stdio.h> 

int main() {
	//freopen("input.txt", "rt", stdin);
	
	char a[50];
	int result, count;
		
	scanf("%s", &a);
	
	for(int i = 0; a[i] != '\0'; ++i)
	{
		if(48 <= a[i] && 57 >= a[i] )
		{
			result = result * 10 + (a[i] - 48);
		}	
	}
	
	for(int j = 1; j < result; ++j)
	{
		if(0 == result%j)
		{
			++count;
		}
	}
	

	printf("%d\n", result);
	printf("%d", count);
	return 0;
}
