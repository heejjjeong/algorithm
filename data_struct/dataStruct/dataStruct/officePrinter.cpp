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
			cout << "작업 번호 : " << Tasks.front().taskID << ", " << "작업자 이름 : " << Tasks.front().user << ", " << "작업 페이지 : " << Tasks.front().printPages << endl;
			Tasks.pop();
		}
	}

	queue<Job> Tasks;
};

int main()
{
	Printer Print;
	
	Job j1(1, "희정", 6);
	Job j2(2, "생선", 5);
	Job j3(3, "꾸이", 3);
	Job j4(4, "형순", 3);
	Job j5(5, "효원", 7);

	Print.AddPrint(j1);
	Print.AddPrint(j2);
	Print.AddPrint(j3);
	Print.AddPrint(j4);
	Print.Printing();

	Print.AddPrint(j5);
	Print.Printing();
}
