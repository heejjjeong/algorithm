#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::vector<int> S;

template <typename T>
auto partition(typename std::vector<T>::iterator begin,
	typename std::vector<T>::iterator end)
{
	// �� ���� �ݺ��ڸ� �����մϴ�.
	// �ϳ��� �ǹ��� ����Ű��, ������ ���� ������ ���۰� ������ ���Ҹ� ����ŵ�ϴ�.
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;
	while (true)
	{
		// ������ ù ��° ���Һ��� �����Ͽ� �ǹ����� ū ���Ҹ� ã���ϴ�.
		while (*left_iter <= pivot_val && std::distance(left_iter, right_iter) > 0)
			left_iter++;

		// ������ ������ ���Һ��� �����Ͽ� �������� �ǹ����� ���� ���Ҹ� ã���ϴ�.
		while (*right_iter > pivot_val && std::distance(left_iter, right_iter) > 0)
			right_iter--;

		// ���� left_iter�� right_iter�� ���ٸ� ��ȯ�� ���Ұ� ������ �ǹ��մϴ�.
		// �׷��� ������ left_iter�� right_iter�� ����Ű�� ���Ҹ� ���� ��ȯ�մϴ�.
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
	// ���� ���Ϳ� �ϳ� �̻��� ���Ұ� �ִٸ�
	if (std::distance(begin, last) >= 1)
	{
		// ���� �۾��� ����
		auto partition_iter = partition<T>(begin, last);
		
		std:: cout << index << std::endl;

		// ���� �۾��� ���� ������ ���͸� ��������� ����
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

	// [1, size] �������� ���� ���� �߻�
	std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

	// S�� ���� �߰�
	for (auto i = 0; i < size; i++)
		S.push_back(uniform_dist(rand));

	std::cout << "���ĵ��� ���� �Է� ����:" << std::endl;
	print_vector<int>(S);
	std::cout << std::endl;

	// arr.end()�� �� ������ ���� ������ ����Ű�Ƿ� arr.end() - 1 ���·� ȣ���մϴ�.
	quick_sort<int>(S.begin(), S.end() - 1, 10);
	
	std::cout << "�κ� �� ���� ���� ���� ����:" << std::endl;
	print_vector<int>(S);
	std::cout << std::endl;
}

int main()
{
	run_quick_sort_test(1000);
	return 0;
}