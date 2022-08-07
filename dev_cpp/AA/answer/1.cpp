#include <iostream>

int main() {
	
	int n,m,i,sum = 0;
	
	std::cin>>n>>m;
	for(i = 1; i <= n; ++i)
	{
		if( 0 == i%m)
		{
			sum += i;
		}
	}
	std::cout << sum;
	return 0;
}
