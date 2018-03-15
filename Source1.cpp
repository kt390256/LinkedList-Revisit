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
		node *temp = head;                            //second condition 只要oldheadptr不等于nullptr就一直前进
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





	void linkedList::insertFront(int data){//如何在linkedlist头增加第一个node
		node *temp = new node;//制造一个新node
		temp->data = data;
		temp->next = nullptr;
		if (head == nullptr)//如果head指针没有指向任何东西的话(也就是说如果list是不存在的话)
		{
			cout <<"This is head : " << head;
			head = temp;//head = temp意思是让head pointer直接指向temp node(第一个node)
		}
		else
		{
			temp->next = head;//temp->next = head的意思是让temp node指向head指向的node. 现在temp node应该和lindedlist的第一个node连接了
			head = temp;//然后在把head指向temp node, 也就是list的第一个node
		}
		size++;
	}


	void linkedList::pushBack(int data)
	{
		if (head == nullptr)//如果没有list的话,那么就直接建一个node就好了
		{
			node *temp = new node;
			temp->next = nullptr;
			temp->data = data;
			head = temp;
		}

		else{//如果list里面已经有node的话 1.先建一个temp指针, 这个指针指向和head ptr一样的第一个node 2.建一个node
			node *temp = head;//建一个指向第一个node的指针
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
	//-------popfront步骤----------------------------//
	//1.先建一个temp指针
	//2.把head指针移到第二个node上面
	//3.由于temp指针还在第一个node上面,所以可以直接把这个node的next部分写成 temp->next = nullptr;
	//4.直接把temp删掉
	//----------------------------------------------



	//---------------在linkedlist里面, 当你把一个pointer等于另外一个指针的时候, 它的意思其实就是这几个指针都指向同一个node
	void linkedList::popBack(){//2 extra ptrs needed
		if (head == nullptr)
		{
			return;
		}
		
			node *last = head;//指向第一个node
			node *secondToLast = nullptr;

			while (last->next != nullptr)
			{
				secondToLast = last;//这时的secondToLast指针指向第一个node
				last = last->next;//last移到下一个node
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

					if (current->data == moving->next->data)//如果current的数字书和moving下一个的数字是一样的话
					{
						duplicate = moving->next;//moving的下一个node就是duplicate
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
			while (current->next != nullptr && nodePos !=pos)//只要其中一个条件fail的话, 就会跳出while loop
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


	  ostream &operator<<(ostream &os, const linkedList &l)//显示出列表的时候不需要制造新指针了, 可以直接用head指针来显示
	{

		linkedList list = l;//这步特别重要. 这个是直接给list做一个object, 就想一个copy一样. 没有这步的话，main里面的list就不能多次被显示了

		while (list.head != nullptr)  //2.直接用while loop
		{
			os << list.head->data << "---->";//3.print的话直接print head， 显示的是后是显示head-?data的
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
			 head = temp->next;//1.把head移到下一个node
			 delete temp;//2.把这个Node删了
			 temp = nullptr;//3.把temp移到head指向的node
		 }
		 head = nullptr;
		 size = 0;
	 }



	linkedList::~linkedList(){
		if (head == nullptr)
			return;
		deleteList();
	}



