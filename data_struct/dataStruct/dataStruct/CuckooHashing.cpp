#include <iostream>
#include <vector>

//���ٱ��ؽ�
class hash_map
{
	//2���� �ؽ����̺� ���, ���̺� ũ�� ����
	std::vector<int> data1;
	std::vector<int> data2;
	int size;

public:
	//2���� �ؽ��Լ� ( ������ �ؽ����̺��� �ٸ� �ؽ��Լ��� ��������)
	int hashFunc1(int key) const
	{
		return key % size;
	}
	int hashFunc2(int key) const
	{
		return (key / size) % size;
	}

	//�ؽ����̺� �ʱ�ȭ
	hash_map(int n) : size(n)
	{
		data1 = std::vector<int>(size, -1);
		data2 = std::vector<int>(size, -1);
	}

	//����� �����ϴ� �Լ�
	std::vector<int>::iterator lookup(int key)
	{
		//���� �ؽ����̺��� Ű�� �˻��ϰ� �ش� ��ġ�� ��Ÿ���� �ݺ��ڸ� ��ȯ.
		auto hash_value1 = hashFunc1(key);
		if (data1[hash_value1] == key)
		{
			std::cout << "1�� ���̺��� " << key << "��(��) ã�ҽ��ϴ�" << std::endl;
			return data1.begin() + hash_value1;
		}

		auto hash_value2 = hashFunc2(key);
		if (data2[hash_value2] == key)
		{
			std::cout << "2�� ���̺��� " << key << "��(��) ã�ҽ��ϴ�" << std::endl;
			return data2.begin() + hash_value2;
		}

		//���� ���Ҹ� ã�� ���ϸ� data2 ���̺��� ������ �ݺ��� ��ȯ
		return data2.end();
	}

	void erase(int key)
	{
		auto position = lookup(key);
		if (position != data2.end()) //ã������
		{
			*position = -1; //�ʱ�ȭ
			std::cout << key << "�� �ش��ϴ� ���Ҹ� �����߽��ϴ�." << std::endl;
		}
		else
		{
			std::cout << key << "Ű�� ã�� ���� �������� ���ߴϴ�." << std::endl;
		}
	}

	void insert(int key)
	{
		insert_impl(key, 0, 1);
	}

	//������ ��������� ����
	//�����Լ������� ��ȯ ���θ� �˻��ؾ���
	//�׷��� �湮�� ��ġ�� ��� ���� ����ϴ� ���� �δ��� ũ��.
	//�׷��Ƿ� �ܼ��� ��� ȣ�� Ƚ���� ��ȸ�̻��� �Ǹ� ��ȯ���� ����
	//�̶� �ִ� ��� ȣ�� Ƚ���� ���̺� ũ��� ���� �����Ѵ�.
	void insert_impl(int key, int cnt, int table)
	{
		if (cnt >= size)
		{
			std::cout << key << " ���� �� ����Ŭ �߻�! ���ؽ��� �ʿ��մϴ�!" << std::endl;
			return;
		}

		if (table == 1)
		{
			int hash = hashFunc1(key);
			if (data1[hash] == -1)
			{
				std::cout << table << "�� ���̺� " << key << " ����" << std::endl;
				data1[hash] = key;
			}
			else
			{
				int old = data1[hash];
				data1[hash] = key;
				std::cout << table << "�� ���̺� " << key << " ����: ������ " << old << " �̵� -> ";
				insert_impl(old, cnt + 1, 2);
			}
		}
		else
		{
			int hash = hashFunc2(key);
			if (data2[hash] == -1)
			{
				std::cout << table << "�� ���̺� " << key << " ����" << std::endl;
				data2[hash] = key;
			}
			else
			{
				int old = data2[hash];
				data2[hash] = key;
				std::cout << table << "�� ���̺� " << key << " ����: ������ " << old << " �̵� -> ";
				insert_impl(old, cnt + 1, 1);
			}
		}
	}

	void print()
	{
		std::cout << "Index: ";
		for (int i = 0; i < size; i++)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data1: ";
		for (auto i : data1)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data2: ";
		for (auto i : data2)
			std::cout << i << '\t';
		std::cout << std::endl;
	}
};


int main()
{
	hash_map map(7);
	map.print();
	std::cout << std::endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	std::cout << std::endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	std::cout << std::endl;

	map.print();
	std::cout << std::endl;

	map.insert(14); // ����Ŭ �߻�!
	return 0;
}