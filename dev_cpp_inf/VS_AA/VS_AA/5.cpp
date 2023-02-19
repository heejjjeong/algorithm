#include <stdio.h> 

int main() {
	//freopen("input.txt","rt",stdin);
	char a[20];
	int year, age;
	scanf("%s", &a);
	
	if('1' == a[7] ||'2' == a[7] )
	{
		year = 1900 + ((a[0] - 48) * 10) + ((a[1] - 48));
	}
	else
	{
		year = 2000 + ((a[0] - 48) * 10) + ((a[1] - 48));
	}
	age = 2019 - year + 1;
	printf("%d ",age); 
	
	if('1' == a[7] || '3' == a[7])
	{
		printf("M\n");
	}
	else
	{
		printf("W\n");
	}

	
	return 0;
}
