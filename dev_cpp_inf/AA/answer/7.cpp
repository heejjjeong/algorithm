#include <stdio.h> 

int main() {
	//freopen("input.txt", "rt", stdin);
	
	char a[101];
	char b[101];
	
	int i, temp = 0;
	
	gets(a);
	
	for(i = 0; a[i] != '\0'; ++i)
	{
		if(' ' != a[i])
		{
			if(65 <= a[i] && 90 >= a[i])
			{
				b[temp++] = a[i] + 32;
			}
			else
			{
				b[temp++] = a[i];
			}
		}
	}
	
	b[temp] = '\0';
	printf("%s", b);
	return 0;
}
