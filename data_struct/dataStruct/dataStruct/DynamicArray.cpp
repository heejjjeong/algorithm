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
		//메모리 릭 방지
		delete[] data;
	}

	//멤버 데이터에 직접 접근 하기 위한 [] 연산자
	T& operator[](int index)
	{
		return data[index];
	}
	const T& operator[](int index)const 
	{
		return data[index];
	}

	//at() 함수
	T& at(int index)
	{
		if (index < n)
			return data[index];

		throw "index out of range";
	}

	//배열 크기 반환
	size_t size() const
	{
		return n;
	}
	
	//배열 원소를 순회할 때 사용할 반복자 관련 함수
	T* begin() { return data; }
	const T* begin() const { return data; }

	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//두 배열을 하나로 합치는 함수
	/* ? ? ? : friend가 붙는 이유는 일반적으로 
			   클래스 외부에서는 private 멤버에 접근할 수 없지만, 
			   friend 키워드를 사용하여 해당 함수에게만 접근 권한을 부여
			   이렇게 하면 operator+ 함수가 arr1과 arr2의 원소를 읽기 가능
	*/
	friend DynamicArray<T> operator+(const DynamicArray<T>& arr1, DynamicArray<T>& arr2)
	{
		DynamicArray<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}

	//배열에 저장된 모든 데이터를 문자열로 반환하는 함수
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


//학생 정보를 저장할 구조체 
struct student
{
	std::string name;
	int standard; //학급 정보 
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
	int nStudent;
	std::cout << "1반 학생 수를 입력하세요 : ";
	std::cin >> nStudent;

	DynamicArray<student> class1(nStudent);
	for (int i = 0; i < nStudent; ++i)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요 : ";
		std::cin >> name >> standard;
		class1[i] = student{ name,standard };
	}

	//배열 크기보다 큰 인덱스의 학생에 접근 
	try 
	{
		//class1[nStudent] = student{ "john", 8 }; //예상할 수 없는 동작

		class1.at(nStudent) = student{ "john", 8 }; //예외 발생
	}
	catch (...)
	{
		std::cout << "예외 발생" << std::endl;
	}

	//깊은 복사
	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성 : " << class2.to_string() << std::endl;

	//두 학급을 합쳐서 새로운 큰 학급을 생성
	auto class3 = class1 + class2;
	std::cout << "1반과 2반을 합쳐서 3반 생성" << class3.to_string() << std::endl;

	return 0;
}