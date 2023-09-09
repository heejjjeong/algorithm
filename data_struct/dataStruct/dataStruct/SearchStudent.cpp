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
		// 현재 검색 범위의 중간 원소를 mid_element에 저장
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

		// 현재 검색 범위에 하나의 원소만 남아 있다면 false를 반환
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

	// 검색 시간 측정 시작
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	bool check = binary_search(Students[1], Students);
	if (check)
		cout << Students[1].GetName().first << " " << Students[1].GetName().second << "학생은 예방접종 필요" << endl;
	else
		cout << Students[1].GetName().first << " " << Students[1].GetName().second << "학생은 예방접종 불 필요" << endl;
	// 검색 시간 측정 종료
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "이진 검색 수행 시간: " << diff.count() << std::endl;

	// 검색 시간 측정 시작
	begin = std::chrono::steady_clock::now();

	check = binary_search(Students[4], Students);
	if (check)
		cout << Students[4].GetName().first << " " << Students[4].GetName().second << "학생은 예방접종 필요" << endl;
	else				 
		cout << Students[4].GetName().first << " " << Students[4].GetName().second << "학생은 예방접종 불 필요" << endl;
	// 검색 시간 측정 종료
	end = std::chrono::steady_clock::now();
	diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	std::cout << "이진 검색 수행 시간: " << diff.count() << std::endl;

	return 0;
}