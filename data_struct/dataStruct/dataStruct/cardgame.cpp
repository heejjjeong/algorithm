#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <random>

using namespace std;
/*
�׸��� �÷��̾�
���� ������ ī�� 13�� ����

<���� ��>
1. �� �÷��̾��� ������ ī�� ���� ����
2. �� ī�� 4���� ����µ� 2���� ���ٸ� 2�� ����, 3���� ���ٸ� 2�� ����, 4���� ���ٸ� 4�� ��� ����
3. ������ ī��� ī�带 �� �÷��̾ �ٽ� ������
4. ��ġ�ϴ� ī�尡 ���ٸ� �÷��̾��� ī�� ��Ʈ ����
5. �� ������ �� ����� ī�尡 �� ����� �� ���� �ݺ�
6. ���� ���� �ڽ��� ī�带 ��� ���� ����� ������ ����
7. ���� ���ڸ� ȭ�鿡 ��� �� ���� ����  
*/

void CardResetAndRand(vector<int> playerCard, mt19937& g)
{
	sort(playerCard.begin(), playerCard.end()); //�ʱ�ȭ
	shuffle(playerCard.begin(), playerCard.end(), g); //ī�� ����
}

int PickRandomCard(const vector<int>& playerCard,mt19937& g)
{
	uniform_int_distribution<int> dist(0, playerCard.size() - 1); //�����ϰ� �ε����� �����ϱ� ���� ������ ����
	int randomIndex = dist(g); //�����ϰ� ���õ� �ε���

	return randomIndex;
}

void IsMatchingCard(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4, mt19937& g)
{
	//���� ��ġ�ϴ� ī�尡 �ִ��� �˻�

	//������ ī�� ����
	int p1CardIndex = PickRandomCard(p1, g);
	int p2CardIndex = PickRandomCard(p2, g);
	int p3CardIndex = PickRandomCard(p3, g);
	int p4CardIndex = PickRandomCard(p4, g);

	cout << "���õ� ī�� P1 : " << p1[p1CardIndex] << ",  "
		<< "���õ� ī�� P2 : " << p2[p2CardIndex] << ",  "
		<< "���õ� ī�� P3 : " << p3[p3CardIndex] << ",  "
		<< "���õ� ī�� P4 : " << p4[p4CardIndex] << ",  " << endl;

	if (p1[p1CardIndex] == p2[p2CardIndex])
	{
		//��¥�� 3���� ���Ƶ� 2���� ����ϱ� �ΰ� ������ �ΰ� ����� ������ 2�� ���������� ���� ��..
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
	//���� ������ �ʱ�ȭ�� ����� seed �� ����
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
		CardResetAndRand(player1, gen); //ī�� �ʱ�ȭ �� ����
		IsMatchingCard(player1, player2, player3, player4, gen);
		PickWinner(player1, player2, player3, player4);
	}
	return 0;
}