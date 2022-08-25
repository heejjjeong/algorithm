#include <stdio.h> 

int main() {
	//freopen("input.txt", "rt", stdin);
	
	char text[30];
	int num = 0;
	
	scanf("%s", &text);
	
	for(int i = 0; text[i] != '\0'; ++i)
	{
		if(text[i] == '(')
		{
			++num;
		}
		if(text[i] == ')')
		{
			--num;
		}
		
		if( 0 > num)
		{
			printf("NO");
			return 0;	
		}
	}
	
	if( 0 == num)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

	return 0;
}
