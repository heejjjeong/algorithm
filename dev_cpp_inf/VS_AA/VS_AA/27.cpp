#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool demical(int num)
{
	for (int i = 2; i < num; ++i)
	{
		if (0 == num % i)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	/*FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);*/

	int N, temp = 0, mul = 1, i, j;
	cin >> N;
	
	//���ڿ� �´� �Ҽ��� ���� ���ϱ�
	vector<int> vdemi; //N������ �Ҽ���
	vector<int> vcnt;  //N�� �´� �Ҽ� ����

	for (i = 2; i <= N; ++i)
	{
		if (demical(i))
		{
			vdemi.push_back(i);
			vcnt.push_back(0);
		}
	}

	//N������ �Ҽ��� �� ���������� N���� ��ȸ�ϸ鼭 ������ ���ڵ�� ������..?
	for (i = 2; i <= N; ++i)
	{
		auto num = find(vdemi.begin(), vdemi.end(), i);
		if (vdemi.end() != num) // �Ҽ��߿� �ش� ���� �ִٸ�
		{
			int index = num - vdemi.begin();
			++vcnt[index];
			continue;
		}

		j = 0;
		while (vdemi[j] <= i)
		{
			if (1 == i / vdemi[j] && 0 == i % vdemi[j]) //���� ���� ������ �� 1�̰�, �������� 0�̴� -> ���� ����
			{
				++vcnt[j];

				break;
			}
			else if ( 0 == i % vdemi[j]) //�Ҽ��� mod���� �� �� �� ��������. 
			{
				temp = i;
				while (1 < temp / vdemi[j]) //1�� ���ö����� �ٽ� ���� 
				{
					if (0 != temp % vdemi[j]) //��� �߿� �������� 0�� �ƴϰ� �Ǹ� ���� ���ڷ� ����
					{
						++j;
						continue;
					}

					temp = temp / vdemi[j];
					++vcnt[j];

					auto num = find(vdemi.begin(), vdemi.end(), temp); //��� ���� �Ҽ��� �ִ��� ã��
					if (vdemi.end() != num)
					{
						int index = num - vdemi.begin(); //�ִٸ� �ش� �ε����� ī��Ʈ +1
						++vcnt[index];
						break;
					}
				}
			}
			else if (0 != i % vdemi[j]) //���ʺ��� �������� 0�� �ƴϸ� �ٷ� ���� �Ҽ��� �Ѿ
			{
				++j;
				continue;
			}
			break;
		}
	}
	

	cout << N << "! =";
	for (i = 0; i < vcnt.size(); ++i)
	{
		cout << " " << vcnt[i];
	}
	return 0;
}