#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Job
{
public:
	Job(int ID, string name, int pages) : taskID(ID), user(name), printPages(pages) {};

	int taskID;
	string user;
	int printPages;
};

class Printer
{
public:
	void AddPrint(const Job& job)
	{
		Tasks.push(job);
	}

	void Printing()
	{		
		while (!Tasks.empty())
		{
			cout << "�۾� ��ȣ : " << Tasks.front().taskID << ", " << "�۾��� �̸� : " << Tasks.front().user << ", " << "�۾� ������ : " << Tasks.front().printPages << endl;
			Tasks.pop();
		}
	}

	queue<Job> Tasks;
};

int main()
{
	Printer Print;
	
	Job j1(1, "����", 6);
	Job j2(2, "����", 5);
	Job j3(3, "����", 3);
	Job j4(4, "����", 3);
	Job j5(5, "ȿ��", 7);

	Print.AddPrint(j1);
	Print.AddPrint(j2);
	Print.AddPrint(j3);
	Print.AddPrint(j4);
	Print.Printing();

	Print.AddPrint(j5);
	Print.Printing();
}
