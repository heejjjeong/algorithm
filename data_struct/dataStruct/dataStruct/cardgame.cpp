#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <random>

using namespace std;
/*
네명의 플레이어
각각 임의의 카드 13장 보유

<게임 룰>
1. 각 플레이어의 임의의 카드 한장 선택
2. 비교 카드 4장이 생기는데 2장이 같다면 2장 제거, 3장이 같다면 2장 제거, 4장이 같다면 4장 모두 제거
3. 남겨진 카드는 카드를 낸 플레이어가 다시 가져감
4. 일치하는 카드가 없다면 플레이어의 카드 세트 섞음
5. 이 과정을 한 사람의 카드가 다 사라질 때 까지 반복
6. 제일 먼저 자신의 카드를 모두 없앤 사람이 게임의 승자
7. 최종 승자를 화면에 출력 후 게임 종료  
*/

void CardResetAndRand(vector<int> playerCard, mt19937& g)
{
	sort(playerCard.begin(), playerCard.end()); //초기화
	shuffle(playerCard.begin(), playerCard.end(), g); //카드 섞기
}

int PickRandomCard(const vector<int>& playerCard,mt19937& g)
{
	uniform_int_distribution<int> dist(0, playerCard.size() - 1); //랜덤하게 인덱스를 선택하기 위한 분포를 설정
	int randomIndex = dist(g); //랜덤하게 선택된 인덱스

	return randomIndex;
}

void IsMatchingCard(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4, mt19937& g)
{
	//서로 일치하는 카드가 있는지 검사

	//무작위 카드 선택
	int p1CardIndex = PickRandomCard(p1, g);
	int p2CardIndex = PickRandomCard(p2, g);
	int p3CardIndex = PickRandomCard(p3, g);
	int p4CardIndex = PickRandomCard(p4, g);

	cout << "선택된 카드 P1 : " << p1[p1CardIndex] << ",  "
		<< "선택된 카드 P2 : " << p2[p2CardIndex] << ",  "
		<< "선택된 카드 P3 : " << p3[p3CardIndex] << ",  "
		<< "선택된 카드 P4 : " << p4[p4CardIndex] << ",  " << endl;

	if (p1[p1CardIndex] == p2[p2CardIndex])
	{
		//어짜피 3개가 같아도 2개만 지우니까 두개 같으면 두개 지우고 나머지 2개 지울지말지 보면 됨..
		p1.erase(p1.begin() + p1CardIndex);
		p2.erase(p2.begin() + p2CardIndex);
		if (p3[p3CardIndex] == p4[p4CardIndex])
		{
			p3.erase(p3.begin() + p3CardIndex);
			p4.erase(p4.begin() + p4CardIndex);
		}
	}
	else if (p1[p1CardIndex] == p3[p3CardIndex])
	{
		p1.erase(p1.begin() + p1CardIndex);
		p3.erase(p3.begin() + p3CardIndex);
		if (p2[p2CardIndex] == p4[p4CardIndex])
		{
			p2.erase(p2.begin() + p2CardIndex);
			p4.erase(p4.begin() + p4CardIndex);
		}
	}
	else if (p1[p1CardIndex] == p4[p4CardIndex])
	{
		p1.erase(p1.begin() + p1CardIndex);
		p4.erase(p4.begin() + p4CardIndex);
		if (p2[p2CardIndex] == p3[p3CardIndex])
		{
			p2.erase(p2.begin() + p2CardIndex);
			p3.erase(p3.begin() + p3CardIndex);
		}
	}
	else if (p2[p2CardIndex] == p3[p3CardIndex])
	{
		p2.erase(p2.begin() + p2CardIndex);
		p3.erase(p3.begin() + p3CardIndex);
	}
	else if (p2[p2CardIndex] == p4[p4CardIndex])
	{
		p2.erase(p2.begin() + p2CardIndex);
		p4.erase(p4.begin() + p4CardIndex);
	}
	else if (p3[p3CardIndex] == p4[p4CardIndex])
	{
		p3.erase(p3.begin() + p3CardIndex);
		p4.erase(p4.begin() + p4CardIndex);
	}
}

void PickWinner(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4)
{
	if (p1.empty())
		cout << "winner is  player1" << endl;
	else if (p2.empty())
		cout << "winner is  player2" << endl;
	else if (p3.empty())
		cout << "winner is  player3" << endl;
	else if (p4.empty())
		cout << "winner is  player4" << endl;
}

void printPlayerCard(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4)
{
	cout << "Player1 Cards : ";
	for (auto cards : p1)
	{
		cout << cards << ", ";
	}
	cout << endl;
	cout << "Player2 Cards : ";
	for (auto cards : p2)
	{
		cout << cards << ", ";
	}
	cout << endl;
	cout << "Player3 Cards : ";
	for (auto cards : p3)
	{
		cout << cards << ", ";
	}
	cout << endl;
	cout << "Player4 Cards : ";
	for (auto cards : p4)
	{
		cout << cards << ", ";
	}
	cout << endl;
}
int main()
{
	//난수 생성기 초기화에 사용할 seed 값 설정
	random_device rd;
	mt19937 gen(rd());
	//gen.seed(rd());

	vector<int> player1 , player2, player3, player4;
	for (int i = 0; i < 13; ++i)
	{
		player1.push_back(i + 1);
		player2.push_back(i + 1);
		player3.push_back(i + 1);
		player4.push_back(i + 1);
	}
	
	while (!player1.empty() && !player2.empty() && !player3.empty() && !player4.empty())
	{
		printPlayerCard(player1, player2, player3, player4);
		CardResetAndRand(player1, gen); //카드 초기화 후 섞기
		IsMatchingCard(player1, player2, player3, player4, gen);
		PickWinner(player1, player2, player3, player4);
	}
	return 0;
}