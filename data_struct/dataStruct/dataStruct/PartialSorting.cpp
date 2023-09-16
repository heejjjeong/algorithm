#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::vector<int> S;

template <typename T>
auto partition(typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end)
{
	// 세 개의 반복자를 생성합니다.
	// 하나는 피벗을 가리키고, 나머지 둘은 벡터의 시작과 마지막 원소를 가리킵니다.
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;
	while (true)
	{
		// 벡터의 첫 번째 원소부터 시작하여 피벗보다 큰 원소를 찾습니다.
		while (*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
			left_iter++;

		// 벡터의 마지막 원소부터 시작하여 역순으로 피벗보다 작은 원소를 찾습니다.
		while (*right_iter > pivot_val && std::distance(left_iter, right_iter) > 0)
			right_iter--;

		// 만약 left_iter와 right_iter가 같다면 교환할 원소가 없음을 의미합니다.
		// 그렇지 않으면 left_iter와 right_iter가 가리키는 원소를 서로 교환합니다.
		if (left_iter == right_iter)
			break;
		else
			std::iter_swap(left_iter, right_iter);
	}

	if (pivot_val > *right_iter)
		std::iter_swap(begin, right_iter);

	return right_iter;
}


template <typename T>
void print_vector(std::vector<T> arr)
{
	for (auto i : arr)
		std::cout << i << " ";

	std::cout << std::endl;
}

template <typename T>
void quick_sort(typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator last, int index)
{
	// 만약 벡터에 하나 이상의 원소가 있다면
	if (std::distance(begin, last) >= 1)
	{
		// 분할 작업을 수행
		auto partition_iter = partition<T>(begin, last);
		
		std:: cout << index << std::endl;

		// 분할 작업에 의해 생성된 벡터를 재귀적으로 정렬
		quick_sort<T>(begin, partition_iter - 1, index);

		if (partition_iter < begin + index)
		{
			quick_sort<T>(partition_iter, last, index);
			index = std::distance(partition_iter, begin + 10);
		}
	}
}

void run_quick_sort_test(int size)
{
	
	std::random_device rd;
	std::mt19937 rand(/*rd()*/1);

	// [1, size] 범위에서 정수 난수 발생
	std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

	// S에 난수 추가
	for (auto i = 0; i < size; i++)
		S.push_back(uniform_dist(rand));

	std::cout << "정렬되지 않은 입력 벡터:" << std::endl;
	print_vector<int>(S);
	std::cout << std::endl;

	// arr.end()는 맨 마지막 원소 다음을 가리키므로 arr.end() - 1 형태로 호출합니다.
	quick_sort<int>(S.begin(), S.end() - 1, 10);
	
	std::cout << "부분 퀵 정렬 수행 후의 벡터:" << std::endl;
	print_vector<int>(S);
	std::cout << std::endl;
}

int main()
{
	run_quick_sort_test(1000);
	return 0;
}