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
	void InsertList(int aData,int bData); //������Ĳ���
	void DeleteList(int aData); //�������ɾ��

	void Outputlist();//����������

	Node*Gethead() { return Head; }
};