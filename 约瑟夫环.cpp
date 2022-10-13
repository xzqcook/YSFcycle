#include "CycleLinkList.h"
#include <iostream>
using namespace std;

int main()
{
	int NumPeople;
	cout << "请输入人数: " ;
	cin >> NumPeople;
	CycleLinkList L;
	CreatList(L, NumPeople);
	Print(L);
	cout << "请输入初始密码: " ;
	int m;
	cin >> m;
	YsfRing(L, NumPeople, m);
	system("pause");
	return 0;
}
