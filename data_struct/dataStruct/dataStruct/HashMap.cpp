#include <iostream>
#include <vector>

//�������� �����ϴ� ������ ����
using uint = unsigned int;

class hash_map
{
	std::vector<int> data;

public:
	hash_map(size_t dataSize)
	{
		//��� ���� -1�� �ʱ�ȭ ( ���������� ���X, �ش���ġ�� ����� ���� ������ ��
		data = std::vector<int>(dataSize, -1);
	}

	//�����Լ�
	void insert(uint value)
	{
		//�� �Լ��� ���� �ؽ� �� ��ġ�� �̹� �ٸ� ���� �����ϴ��� Ȯ������ �ʴ´�.
		//�� Ư�� ��ġ�� �̹� �ٸ� ���� ���� �ϴ��� �ܼ� ������ �ȴ�.
		//�ؽ� �� �ߺ��� �� ��� ���� ���� ���� ����ȴ�.
		int n = data.size();
		data[value % n] = value; 
		std::cout << value << "��(��) ���� �߽��ϴ�." << std::endl;
	}

	//Ư�� ���Ұ� �ʿ� �ִ��� Ȯ���ϴ� ��� �Լ�
	bool find(uint value)
	{
		//�ش� ��ġ�� ����� ���� value�� ������ Ȯ��
		int n = data.size();
		return (data[value % n] == value);
	}

	void erase(uint value)
	{
		int n = data.size();
		if (data[value % n] == value)
		{
			data[value % n] = -1;
			std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
		}
	}
};

int main()
{
	//��� ����� ����ϴ� ���� �Լ�
	hash_map MyHashMap(7);

	auto print = [&](int value)
	{
		if (MyHashMap.find(value))
			std::cout << " �ؽ� �ʿ���" << value << "��(��) ã�ҽ��ϴ�.";

		else
			std::cout << "�ؽ� �ʿ��� " << value << "��(��) ã�� ���߽��ϴ�.";
		std::cout << std::endl;
	};

	MyHashMap.insert(2);
	MyHashMap.insert(25);
	MyHashMap.insert(10);
	print(25);

	MyHashMap.insert(100);
	print(100);
	print(2);

	MyHashMap.erase(25);

	return 0;
}