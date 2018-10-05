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

		void InsertList(T bData, T aData=NULL)//������Ĳ���
		{
			Node<T>* p, *q = nullptr, *s;
			s = (Node<T>*)new(Node<T>); //��̬����һ���½��
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
					p = p->Next;
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
			//delete[] s;
		}

		void DeleteList(T aData) //�������ɾ��
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

		void Outputlist()//����������
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