#include <iostream>

int main() {
	
	int n, i, sum = 1;
	
	std::cin>>n;
	std::cout << 1 ;
	
	for(i = 2; i < n ; ++i)
	{
		if(0 == n % i)
		{
			sum += i;
			std::cout << " + " << i;
		}
	}
	std::cout << " = " << sum;
	
	return 0;
}
