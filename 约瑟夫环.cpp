#include "CycleLinkList.h"
#include <iostream>
using namespace std;

int main()
{
	int NumPeople;
	cout << "����������: " ;
	cin >> NumPeople;
	CycleLinkList L;
	CreatList(L, NumPeople);
	Print(L);
	cout << "�������ʼ����: " ;
	int m;
	cin >> m;
	YsfRing(L, NumPeople, m);
	system("pause");
	return 0;
}
