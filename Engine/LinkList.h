#pragma once

namespace EngineLib
{
	template <typename T>
	struct Node
	{
		T Data;
		Node* Next;
	};

	template <typename T>
	class list
	{
		Node<T>*Head;
	public:
		list() { Head = nullptr; }

		void InsertList(T bData, T aData=NULL)//链表结点的插入
		{
			Node<T>* p, *q = nullptr, *s;
			s = (Node<T>*)new(Node<T>); //动态分配一个新结点
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
					p = p->Next;
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
			//delete[] s;
		}

		void DeleteList(T aData) //链表结点的删除
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

		void Outputlist()//链表结点的输出
		{
			Node*current = Head;
			while (current != NULL)
			{
				cout << current->Data << " ";
				current = current->Next;
			}
			cout << endl;
		}

		Node<T>*Gethead() { return Head; }
	};
}