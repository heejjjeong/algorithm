#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct median
{
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, vector<int>, greater<int>> minHeap;

	void insert(int data)
	{
		if (maxHeap.size() == 0)
		{
			maxHeap.push(data);
			return;
		}

		if (maxHeap.size() == minHeap.size())
		{
			if (data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);

			return;
		}

		if (maxHeap.size() < minHeap.size())
		{
			if (data > get())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else
				maxHeap.push(data);

			return;
		}

		if (data < get())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else
			minHeap.push(data);
	}

	int get()
	{
		if (maxHeap.size() == minHeap.size()) //두개의 개수가 때
		{
			if (maxHeap.top() < minHeap.top())
				return maxHeap.top();
			else
				return minHeap.top();
		}

		if (maxHeap.size() < minHeap.size())
			return minHeap.top();

		return maxHeap.top();
	}
};

#define TEST

int main()
{
#ifdef TEST
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
#endif

	int n = 0, temp = 0;
	scanf_s("%d", &n);

	median med;

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &temp);
		med.insert(temp);
		printf_s("%d\n", med.get());
	}
}
