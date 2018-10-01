#pragma once


struct Node
{
	int Data;
	Node* Next;
};

class list
{
	Node*Head;
public:
	list() { Head = nullptr; }
	void InsertList(int aData,int bData); //链表结点的插入
	void DeleteList(int aData); //链表结点的删除

	void Outputlist();//链表结点的输出

	Node*Gethead() { return Head; }
};