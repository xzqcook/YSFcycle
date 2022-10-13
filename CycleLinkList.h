#include <iostream>
#define ERROR 0
#define OK 1
typedef int Status;
using namespace std;
typedef struct LNode
{
	int data;
	int position;
	struct LNode* next;
	struct LNode* prior;
}LNode,*LinkList;
struct CycleLinkList
{
	LNode* head;
	int len;
};
void CreatList(CycleLinkList& L, int N)
{
	L.head= NULL;
	L.len = 0;
	LNode *p,*tail = new LNode;
	tail->next = tail->prior = tail;
	for (int i = 1; i <= N; i++)
	{
		cout << "请输入第" << i << "人密码： " ;
		if (i == 1) {
			cin >> tail->data;
			tail->position = 1;
			L.head = tail;
			L.len = 1;
			
			continue;
		}
		p = (LNode*)malloc(sizeof(LNode));
		cin >> p->data;
		p->position = i;
		p->prior = tail;
		p->next = tail->next;
		tail->next = p;
		tail = tail->next;
		L.len++;
	}

}
void Print(CycleLinkList L)
{
	LNode* p;
	p = L.head;
	int i = 0;
	while (i<L.len)
	{
		cout << "位置： " << p->position<<" 密码: "<< p->data << endl;
		p = p->next;
		i++;
	}
	
}
Status IsEmpty(CycleLinkList L)
{
	if (L.head== NULL)
		return OK;
	return ERROR;
}
Status DeleteList(CycleLinkList& L,int N)
{
	if (IsEmpty(L))
		return ERROR;
	LinkList p,s,t;
	p = L.head;
	s = L.head->prior;
	int n = 1;
	if (N == 1) {
		s->next = p->next;
		L.head->next->prior = s;
		L.head = L.head->next;
		L.len--;
		delete(p);
		return OK;
	}
	while (n != N-1)
	{
		p = p->next;
		n++;
	}
	t = p->next;
	p->next = t->next;
	t->next->prior = p;
	L.head = t->next;
	L.len--;
	delete(t);
	return OK;

}
void YsfRing(CycleLinkList& L, int n, int m)
{
	LinkList T=L.head;
	int K = n,local;
	while (n > 0)
	{
		m = m % n;
		if (m == 0)
			m = n;
		local = m;
		if (m == 1) {
			T = L.head;
			cout << "第" << K - n + 1 << "个出列的是： " << T->position<< endl;
			m = T->data;
			DeleteList(L,1);
			n--;
			continue;
		}
		T = L.head;
		for (int j = 2; j < m; j++)
		{
			T = T->next;
		}
		cout << "第" << K - n + 1 << "个出列的是： " << T->next->position<< endl;
		m = T->next->data;
		DeleteList(L, local);
		n--;
	}
}

