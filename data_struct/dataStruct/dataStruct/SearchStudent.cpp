#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
class Student
{
	std::pair<int, int> name;
	bool vaccinated;

public:
	Student(pair<int, int> first, bool second) : name(first), vaccinated(second){}
	bool operator ==(Student& student)
	{
		return name == student.name;
	}
	bool operator < (Student& student)
	{
		return name < student.name;
	}
	bool operator > (Student& student)
	{
		return name > student.name;
	}

	bool IsVaccin()
	{
		return vaccinated;
	}
	pair<int,int>  GetName()
	{
		return name;
	}
};


bool binary_search(Student N, std::vector<Student>& S)
{
	auto first = S.begin();
	auto last = S.end();

	while (true)
	{
		// ���� �˻� ������ �߰� ���Ҹ� mid_element�� ����
		auto range_length = std::distance(first, last);
		auto mid_element_index = std::floor(range_length / 2);
		auto mid_element = *(first + mid_element_index);

		if (mid_element == N && mid_element.IsVaccin() == false)
			return true;
		if (mid_element == N && mid_element.IsVaccin() == true)
			return false;
		else if (mid_element > N)
			std::advance(last, -mid_element_index);
		else
			std::advance(first, mid_element_index);

		// ���� �˻� ������ �ϳ��� ���Ҹ� ���� �ִٸ� false�� ��ȯ
		if (range_length == 1)
			return true;
	}
}

int main()
{

	vector<Student> Students;

	Students.push_back(Student(pair<int, int>(1,2), true));
	Students.push_back(Student(pair<int, int>(2,2), true));
	Students.push_back(Student(pair<int, int>(3,2), false));
	Students.push_back(Student(pair<int, int>(4,2), false));
	Students.push_back(Student(pair<int, int>(5,2), false));

	sort(Students.begin(), Students.end());

	// �˻� �ð� ���� ����
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	bool check = binary_search(Students[1], Students);
	if (check)
		cout << Students[1].GetName().first << " " << Students[1].GetName().second << "�л��� �������� �ʿ�" << endl;
	else
		cout << Students[1].GetName().first << " " << Students[1].GetName().second << "�л��� �������� �� �ʿ�" << endl;
	// �˻� �ð� ���� ����
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "���� �˻� ���� �ð�: " << diff.count() << std::endl;

	// �˻� �ð� ���� ����
	begin = std::chrono::steady_clock::now();

	check = binary_search(Students[4], Students);
	if (check)
		cout << Students[4].GetName().first << " " << Students[4].GetName().second << "�л��� �������� �ʿ�" << endl;
	else				 
		cout << Students[4].GetName().first << " " << Students[4].GetName().second << "�л��� �������� �� �ʿ�" << endl;
	// �˻� �ð� ���� ����
	end = std::chrono::steady_clock::now();
	diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "���� �˻� ���� �ð�: " << diff.count() << std::endl;

	return 0;
}