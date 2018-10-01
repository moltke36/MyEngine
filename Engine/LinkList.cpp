#include "LinkList.h"
#include <iostream>
using namespace std;

void list::InsertList(int aData, int bData) //设aDate是结点a中的数据，bDate是结点b中的数据   如果要在链表中的结点a之前插入结点b
{
	Node* p, *q, *s;
	s = (Node*)new(Node); //动态分配一个新结点
	s->Data = bData;   //设b为此结点 
	p = Head;
	if (Head == nullptr) //若是空表，使b作为第一个结点
	{
		Head = s;
		s->Next = nullptr;
	}
	else if (aData == Head->Data)
	{
		s->Next = p; // s的下个节点改成aData
		Head = s;
	}
	else
	{
		while (p->Data != aData && p->Next != nullptr) //查找结点a
		{
			q = p;
			p = p ->Next;
		}
		if (p->Data == aData) //若有结点a
		{
			q->Next = s;
			s->Next = p;
		}
		else   //若没有结点a；
		{
			p->Next = s;
			s->Next = nullptr;
		}
	}


}

void list::DeleteList(int aData)  //设aDate是要删除的结点a中的数据成员
{
	Node*p, *q; //p用于指向结点a,q用于指向结a的前一个结点
	p = Head;
	if (p == NULL) //若是空表
		return;
	if (p->Data == aData) //若a是第一个结点
	{
		Head = p->Next;
		delete p;
	}
	else
	{
		while (p->Data != aData && p->Next != NULL) //查找结点a
		{
			q = p;
			p = p->Next;
		}
		if (p->Data == aData) //若有结点a
		{
			q->Next = p->Next;
			delete p;
		}
	}
}

void list::Outputlist()
{ 
	Node*current = Head;
	while (current != NULL) 
	{ 
		cout << current->Data << " ";
		current = current->Next; 
	}
	cout << endl; 
}
