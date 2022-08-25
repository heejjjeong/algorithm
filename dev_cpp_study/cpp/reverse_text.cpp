#include <stdio.h>
#include <string.h>

int main()
{
	char a[30];
	char b[30];
	
	gets(a);
	
	memcpy(b,a,sizeof(a));
	
	size_t size = strlen(a);
	
	for(int i = 0; i < size >>1; ++i)
	{
		char temp = b[i];
		b[i] = b[size - i -1];
		b[size-i-1] = temp;
	}
	
	printf("%s", b);
	
	//printf("%s", b);
}
