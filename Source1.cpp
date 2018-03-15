#include<iostream>
using namespace std;
#include"singly-header.h";



	linkedList::linkedList(){//default constructor

		head = nullptr;
		size = 0;
	}


	linkedList::linkedList(int data)//make the list and create the first node for testing purposes
	{
		node *temp = new node;
		temp->data = data;
		temp->next = nullptr;
		head = temp;
		size = 1;
	}
	
	linkedList::linkedList(const linkedList &old)//copy constructor
	{
		if (old.head == nullptr)
		{
			head = nullptr;//if the original list has nothing, then this list will copy nothing
		}
		else
		head = new node;//if theres something in the old list, when copy, make a first node

	head->data = old.head->data;//then give it some value


		//for the rest of the list
		node *temp = head;                            //second condition ֻҪoldheadptr������nullptr��һֱǰ��
		for (node *oldHeadPtr = old.head->next; oldHeadPtr != nullptr; oldHeadPtr = oldHeadPtr->next)//(first condition: make a ptr and point that at the second node of the list b/c we already have the first node; then just traverse down the list
		{
			temp->next = new node;//for every node there exists in the old list, make a new one here, and connect this new node to the first node of the list
			temp = temp->next;
			temp->data = oldHeadPtr->data;
		}
		temp->next = nullptr;

	}
	

	linkedList linkedList::operator=(const linkedList &old)
	{
		if (old.head == nullptr)
		{
			deleteList();
		}
		else{
			deleteList();//need to delete the new copy because all the addresses were copied too

			node *oldhead = old.head;//make a ptr and point that to the head of the old list 
			node *temp = new node;//make a new node here
			temp->data = oldhead->data;//the new node's data is the same as the data of the first node from the old list
			head = temp;//now this temp node becomes the first node of the list
			temp->next = nullptr;
			oldhead = oldhead->next;
			size = 1;


			//temp node is the first node of the new list
			while (oldhead != nullptr)//while theres more nodes in the first list
			{
				node *second = new node;
				second->data = oldhead->data;
				second->next = nullptr;
				temp->next = second;
				temp = temp->next;
				oldhead = oldhead->next;
				size++;
			}
		}
		return *this;
	}





	void linkedList::insertFront(int data){//�����linkedlistͷ���ӵ�һ��node
		node *temp = new node;//����һ����node
		temp->data = data;
		temp->next = nullptr;
		if (head == nullptr)//���headָ��û��ָ���κζ����Ļ�(Ҳ����˵���list�ǲ����ڵĻ�)
		{
			cout <<"This is head : " << head;
			head = temp;//head = temp��˼����head pointerֱ��ָ��temp node(��һ��node)
		}
		else
		{
			temp->next = head;//temp->next = head����˼����temp nodeָ��headָ���node. ����temp nodeӦ�ú�lindedlist�ĵ�һ��node������
			head = temp;//Ȼ���ڰ�headָ��temp node, Ҳ����list�ĵ�һ��node
		}
		size++;
	}


	void linkedList::pushBack(int data)
	{
		if (head == nullptr)//���û��list�Ļ�,��ô��ֱ�ӽ�һ��node�ͺ���
		{
			node *temp = new node;
			temp->next = nullptr;
			temp->data = data;
			head = temp;
		}

		else{//���list�����Ѿ���node�Ļ� 1.�Ƚ�һ��tempָ��, ���ָ��ָ���head ptrһ���ĵ�һ��node 2.��һ��node
			node *temp = head;//��һ��ָ���һ��node��ָ��
			node *tempNode = new node;
			tempNode->data = data;
			tempNode->next = nullptr;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = tempNode;//connect to nodes
		}
		size++;
		//cout << "size is " << size << endl;
	}
	//---------------------------------------------//

	void linkedList::popFront(){
		
		if (head == nullptr)
		{
			return;
		}
		else
		{
			node *temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
		}
		size--;
	}
	//-------popfront����----------------------------//
	//1.�Ƚ�һ��tempָ��
	//2.��headָ���Ƶ��ڶ���node����
	//3.����tempָ�뻹�ڵ�һ��node����,���Կ���ֱ�Ӱ����node��next����д�� temp->next = nullptr;
	//4.ֱ�Ӱ�tempɾ��
	//----------------------------------------------



	//---------------��linkedlist����, �����һ��pointer��������һ��ָ���ʱ��, ������˼��ʵ�����⼸��ָ�붼ָ��ͬһ��node
	void linkedList::popBack(){//2 extra ptrs needed
		if (head == nullptr)
		{
			return;
		}
		
			node *last = head;//ָ���һ��node
			node *secondToLast = nullptr;

			while (last->next != nullptr)
			{
				secondToLast = last;//��ʱ��secondToLastָ��ָ���һ��node
				last = last->next;//last�Ƶ���һ��node
			}
				delete last;
				secondToLast->next = nullptr;
				size--;
	}





	void linkedList::deleteDuplicate()
	{
		if (head == nullptr)
		{
			return;
		}
		else
		{
			node *current = head;
			node *duplicate;
			node *moving;

			while (current != nullptr && current->next != nullptr)
			{
				moving = current;
				while (moving->next != nullptr)
				{

					if (current->data == moving->next->data)//���current���������moving��һ����������һ���Ļ�
					{
						duplicate = moving->next;//moving����һ��node����duplicate
						moving->next = moving->next->next;
						delete duplicate;
						size--;
					}
					else
					{
						moving = moving->next;
					}
				}
				current = current->next;
			}

		}

	}



	void linkedList::insert(int pos, int val)
	{
		node *temp = new node;
		temp->data = val;

		node *current = new node;
		node *previous = new node;
		
		current = head;

		int nodePos = 0;

		
		if (head == nullptr)
		{
			head = temp;
			temp->next = nullptr;
			cout << "List is empty, added the first node to the list." << endl;
		}

		else{
			while (current->next != nullptr && nodePos !=pos)//ֻҪ����һ������fail�Ļ�, �ͻ�����while loop
			{
				previous = current;//traverse through the list and the loop will stop at a specific location b/c nodePos != pos
				current = current->next;
				nodePos++;
			}
			if (pos == 0)//if 0 is entered, use insert front function
			{
				temp->data = val;
				temp->next = head;
				head = temp;
			}
			else if (current->next == nullptr && nodePos+1==pos) //if 
			{
				temp->data = val;
				current = head;
				while (current->next != nullptr)
				{
					current = current->next;
				}
				current->next = temp;
				
			}
			else if (pos > nodePos + 1)
			{
				cout << "Pos not valid, the list below remains the same." << endl;
			}
			else
			{
				previous->next = temp;
				temp->next = current;
			}
		}

	}

	int linkedList::listSize(){
		return size;
	}


	//--------For reverse list, we can assume the list 1---> 2 ---> 3 ---> 4 ---> NULL ---------------------------///

	void linkedList::reverseList()//3 extra ptrs needed
	{
		if (head == nullptr)
		{
			return;
		}

		node *current = head;//make a current pointer point to the same node head ptr is pointing to 
		node *previous = nullptr;//make a previious node make it point to nothing
		node *next = nullptr;//make a next node make it point to nothing

		while (current != nullptr)//traverse the current ptr||  current ptr should be pointing to 1 right now
		{
			next = current->next;//line executed, next ptr points to 2 since current pointing to 1
			current->next = previous;//disconnect 1 from the list, because previous node is nullptr
			previous = current;//now previous is pointing to the same node current is pointing to 
			current = next;//move the current ptr, now the current pointer is pointing to the node the next pointer is pointing to 
		}
		head = previous;//now previous points to the "first" node in the list but head ptr is still pointing to the "last", therefor i need to make the head ptr points to the same node the prev ptr points to

	}

	//----------------reverse linkedlist completed------------------------------//


	  ostream &operator<<(ostream &os, const linkedList &l)//��ʾ���б���ʱ����Ҫ������ָ����, ����ֱ����headָ������ʾ
	{

		linkedList list = l;//�ⲽ�ر���Ҫ. �����ֱ�Ӹ�list��һ��object, ����һ��copyһ��. û���ⲽ�Ļ���main�����list�Ͳ��ܶ�α���ʾ��

		while (list.head != nullptr)  //2.ֱ����while loop
		{
			os << list.head->data << "---->";//3.print�Ļ�ֱ��print head�� ��ʾ���Ǻ�����ʾhead-?data��
			list.head = list.head->next;//move head pointer to next node
		}
		
		return os;
	}


	 void linkedList::mtoLastElement(int a)
	 {
		 if (head == nullptr)
		 {
			 return;
		 }
		 else
		 {
			 reverseList();
			 node *current = head;
			 int pos = 0;

			 while (current != nullptr && current->next != nullptr)
			 {
				 if (a == pos)
				 {
					 cout << current->data << endl;
					 break;
				 }
				 else
				 {
					 current = current->next;
					 pos++;
					 if (a == pos)
					 {
						 cout << current->data << endl;
						 break;
					 }
				 }
			 }
		 }
	 }


	 void linkedList::deleteList(){

		 node *temp = head;
		 while (temp != nullptr)
		 {
			 head = temp->next;//1.��head�Ƶ���һ��node
			 delete temp;//2.�����Nodeɾ��
			 temp = nullptr;//3.��temp�Ƶ�headָ���node
		 }
		 head = nullptr;
		 size = 0;
	 }



	linkedList::~linkedList(){
		if (head == nullptr)
			return;
		deleteList();
	}


