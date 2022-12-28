#include <stdio.h> 
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	string strNum = "";
	int n, result = 0, maxNum = 0;
	cin >> strNum;

   const int strLen = strNum.length();

	int numCount[strLen] = {0};
	
	for(int i = 0; i < strLen; ++i)
	{
		int temp = strNum[i] - '0';
		numCount[temp] += 1;
	}
	
	for(int i = 1; i < strLen; ++i)
	{
		if(numCount[i] > maxNum) // numCount[i] : ���� ������ ����
		{
			//i��° ������ ���� �ִ밪���� Ŭ��
			maxNum = numCount[i]; //��° ���� ���� �ִ뿡 �ְ�
			result = i;	// �ش� ������ ������� �־���
		}
		if(numCount[i] == maxNum) //��° ������ ���� ���� ������
		{
			if(i > result) // �ش� ������ ������� ���ؼ� ū ���� ����
			{
				result = i;
			}
		}
	}
	
	printf("%d", result);
	return 0;
}

/*
//���� Ǭ Ǯ��

#include <stdio.h> 
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	string strNum = "";
	int n, result = 0, maxNum = 0;
	cin >> strNum;

   const int strLen = strNum.length();

	int numCount[strLen] = {0};
	
	for(int i = 0; i < strLen; ++i)
	{
		int temp = strNum[i] - '0';
		numCount[temp] += 1;
	}
	
	for(int i = 1; i < strLen; ++i)
	{
		if(numCount[i] > maxNum) // numCount[i] : ���� ������ ����
		{
			//i��° ������ ���� �ִ밪���� Ŭ��
			maxNum = numCount[i]; //��° ���� ���� �ִ뿡 �ְ�
			result = i;	// �ش� ������ ������� �־���
		}
		if(numCount[i] == maxNum) //��° ������ ���� ���� ������
		{
			if(i > result) // �ش� ������ ������� ���ؼ� ū ���� ����
			{
				result = i;
			}
		}
	}
	
	printf("%d", result);
	return 0;
}


*/
