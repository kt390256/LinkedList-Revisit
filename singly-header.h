#include<iostream>
using namespace std;

class linkedList{

private:
	struct node{
		double data;
		node *next;
	};

	node *head;
	int size;


public:
	int a;
	linkedList();//default constructor
	linkedList(int data);//custom constructor for testing
	linkedList(const linkedList &old);//copy consturctor
	linkedList operator=(const linkedList &old);//overload = operator
	void insertFront(int data);
	void pushBack(int data);
	void popFront();
	void popBack();
	
	void insert(int pos, int val);
	void deleteDuplicate();
	void mtoLastElement(int a);
	int listSize();
	
	friend ostream &operator<<(ostream &os, const linkedList &l);

	void reverseList();

	void deleteList();
	~linkedList();
};