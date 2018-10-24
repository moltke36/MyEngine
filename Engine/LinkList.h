#pragma once



namespace EngineLib
{
	template<class Any>
	struct Node
	{
		Node<Any> * prior;
		Any * data;
		Node<Any> * next;
	};

	template<class Any>
	class LinkedList
	{
		Node<Any> * head;//ͷ���
		Node<Any> * tail;//β���
		int length;//������
		Node<Any> * getNode(int index)
		{
			//���indexλ�õĽ������
			if (index<0 || index>length) {
				return NULL;
			}
			else {
				Node<Any> *temp = head->next;
				for (int i = 0; i < index; i++, temp = temp->next);
				return temp;
			}
		};
	public:

		//��ʼ��������������
		LinkedList();
		~LinkedList();

		void add(Any*  data);//�������
		Any * get(int index);//��ȡindexλ���ϵ�����
		bool add(int index, Any*  data);//��indexλ�������һ������
		void addFirst(Any* data);//������ͷ�����һ������
		void addLast(Any* data);//������β�����һ������
		Any * remove(int index);//�Ƴ�indexλ���ϵ�����
		Any * removeFirst();//�Ƴ������һ��Ԫ��
		Any * removeLast();//�Ƴ��������һ��Ԫ��
		int size();//�������ĳ���
				   //stack
		Any * pop();//��ջһ������
		void push(Any * data);//��ջһ������
							  //queue
		void in(Any * data);//�������
		Any * out();//������
	};
};