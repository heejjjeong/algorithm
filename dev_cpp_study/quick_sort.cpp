#include <stdio.h>
#include <string.h>

int arr[10] = { 23,123,324234,12312,2123,24,456,56,123,564 };
void swap(int* a, int* b)
{
	int temp = &a;
	*a = *b;
	*b = temp;
}

void quickSort(int* data, int start, int end)
{
	if(start >= end)
		return;
		
	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp = 0;
	
	while( i <= j )
	{
		while(arr[i] < arr[pivot] && i <= end)
	}
}


int main()
{
	
}
