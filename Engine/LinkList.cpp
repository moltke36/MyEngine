#include "LinkList.h"
#include <iostream>
using namespace std;

void list::InsertList(int aData, int bData) //��aDate�ǽ��a�е����ݣ�bDate�ǽ��b�е�����   ���Ҫ�������еĽ��a֮ǰ������b
{
	Node* p, *q, *s;
	s = (Node*)new(Node); //��̬����һ���½��
	s->Data = bData;   //��bΪ�˽�� 
	p = Head;
	if (Head == nullptr) //���ǿձ�ʹb��Ϊ��һ�����
	{
		Head = s;
		s->Next = nullptr;
	}
	else if (aData == Head->Data)
	{
		s->Next = p; // s���¸��ڵ�ĳ�aData
		Head = s;
	}
	else
	{
		while (p->Data != aData && p->Next != nullptr) //���ҽ��a
		{
			q = p;
			p = p ->Next;
		}
		if (p->Data == aData) //���н��a
		{
			q->Next = s;
			s->Next = p;
		}
		else   //��û�н��a��
		{
			p->Next = s;
			s->Next = nullptr;
		}
	}


}

void list::DeleteList(int aData)  //��aDate��Ҫɾ���Ľ��a�е����ݳ�Ա
{
	Node*p, *q; //p����ָ����a,q����ָ���a��ǰһ�����
	p = Head;
	if (p == NULL) //���ǿձ�
		return;
	if (p->Data == aData) //��a�ǵ�һ�����
	{
		Head = p->Next;
		delete p;
	}
	else
	{
		while (p->Data != aData && p->Next != NULL) //���ҽ��a
		{
			q = p;
			p = p->Next;
		}
		if (p->Data == aData) //���н��a
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
