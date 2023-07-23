#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class DynamicArray
{
	T* data;
	size_t n;

public:
	DynamicArray(int n)
	{
		this->n = n;
		data = new T[n];
	}
	DynamicArray(const DynamicArray<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; ++i)
		{
			data[i] = other[i];
		}
	}
	~DynamicArray()
	{
		//�޸� �� ����
		delete[] data;
	}

	//��� �����Ϳ� ���� ���� �ϱ� ���� [] ������
	T& operator[](int index)
	{
		return data[index];
	}
	const T& operator[](int index)const 
	{
		return data[index];
	}

	//at() �Լ�
	T& at(int index)
	{
		if (index < n)
			return data[index];

		throw "index out of range";
	}

	//�迭 ũ�� ��ȯ
	size_t size() const
	{
		return n;
	}
	
	//�迭 ���Ҹ� ��ȸ�� �� ����� �ݺ��� ���� �Լ�
	T* begin() { return data; }
	const T* begin() const { return data; }

	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//�� �迭�� �ϳ��� ��ġ�� �Լ�
	/* ? ? ? : friend�� �ٴ� ������ �Ϲ������� 
			   Ŭ���� �ܺο����� private ����� ������ �� ������, 
			   friend Ű���带 ����Ͽ� �ش� �Լ����Ը� ���� ������ �ο�
			   �̷��� �ϸ� operator+ �Լ��� arr1�� arr2�� ���Ҹ� �б� ����
	*/
	friend DynamicArray<T> operator+(const DynamicArray<T>& arr1, DynamicArray<T>& arr2)
	{
		DynamicArray<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}

	//�迭�� ����� ��� �����͸� ���ڿ��� ��ȯ�ϴ� �Լ�
	std::string to_string(const std::string& sep = ", ")
	{
		if (n == 0)
			return "";

		std::ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++)
		{
			os << sep << data[i];
		}

		return os.str();
	}
};


//�л� ������ ������ ����ü 
struct student
{
	std::string name;
	int standard; //�б� ���� 
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
	int nStudent;
	std::cout << "1�� �л� ���� �Է��ϼ��� : ";
	std::cin >> nStudent;

	DynamicArray<student> class1(nStudent);
	for (int i = 0; i < nStudent; ++i)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ��� : ";
		std::cin >> name >> standard;
		class1[i] = student{ name,standard };
	}

	//�迭 ũ�⺸�� ū �ε����� �л��� ���� 
	try 
	{
		//class1[nStudent] = student{ "john", 8 }; //������ �� ���� ����

		class1.at(nStudent) = student{ "john", 8 }; //���� �߻�
	}
	catch (...)
	{
		std::cout << "���� �߻�" << std::endl;
	}

	//���� ����
	auto class2 = class1;
	std::cout << "1���� �����Ͽ� 2�� ���� : " << class2.to_string() << std::endl;

	//�� �б��� ���ļ� ���ο� ū �б��� ����
	auto class3 = class1 + class2;
	std::cout << "1�ݰ� 2���� ���ļ� 3�� ����" << class3.to_string() << std::endl;

	return 0;
}