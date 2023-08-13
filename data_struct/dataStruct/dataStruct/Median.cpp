#include <iostream>
#include <queue>
#include <vector>

struct median
{
	std::priority_queue<int> maxHeap;
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

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

	double get()
	{
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;

		if (maxHeap.size() < minHeap.size())
			return minHeap.top();

		return maxHeap.top();
	}
};

int main()
{
	median med;

	med.insert(2);
	std::cout << "2 »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	med.insert(4);
	std::cout << "4 »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	med.insert(6);
	std::cout << "6 »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	med.insert(8);
	std::cout << "8 »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	med.insert(10);
	std::cout << "10 »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;
}
