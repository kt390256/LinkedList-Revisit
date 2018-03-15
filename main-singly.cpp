#include<iostream>
using namespace std;
#include"singly-header.h"

int main(){

	int a;
	
	int upperLimit;
	int pick;
	int pick2;

	cout << "Welcome to my linked list testing interface " << endl << endl;
	cout << "<Make a list> --- 1.Push_back    2.Insert_Front" << endl;
	cout << "If you want to test the delete duplicates function make sure your list has"; cout<< "duplicated nodes" << endl;
	cin >> pick;
	if (pick == 1)
	{
		linkedList list;
		
		cout << "How many nodes do you want to add to the list?" << endl;
		cin >> upperLimit;
		
		for (int i = 0; i < upperLimit; i++)
		{
			cout << "Enter node ";
			cin >> a;
			list.pushBack(a);
		}
		cout << "This is your list with push_back function." << endl;
		cout << list << "NULL" << " size : " << list.listSize() << endl << endl;

		bool test = true;
		while (test == true){
			cout << "What would you list to do with this list?" << endl << endl;
			cout << "1.Pop_back  2.Pop_Front  3.Insert node  4.reverse list  5.delete duplicates  6.find M to last Element" << endl;
			cin >> pick2;
			if (pick2 == 1){
				linkedList copy(list);
				copy.popBack();
				cout << "<Copy constructor used>New List : ";
				cout << copy << "NULL" << endl;
				cout << "<Original list>                   " << list << "NULL" << endl;
			}
			else if (pick2 == 2){
				linkedList copy1(list);
				copy1.popFront();
				cout << "<Copy constructor used>New List : ";
				cout << copy1 << "NULL" << endl;
				cout << "<Original list>                   " << list << "NULL" << endl;
			}
			else if (pick2 == 3){
				linkedList copy2(list);
				cout << "Please assign a value to the new node and a position in the list" << endl;
				int pos, numb;
				cout << "enter pos "; cin >> pos;
				cout << "enter num "; cin >> numb;
				if (pos > list.listSize() - 1)
				{
					cout << "Pos size is bigger than the list size, program will now exit. " << endl;
				}
				else{
					copy2.insert(pos, numb);
					cout << "<Copy constructor used>New List : ";
					cout << copy2 << "NULL" << endl;
					cout << "<Original list>                   " << list << "NULL" << endl;
				}
			}
			else if (pick2 == 4){
				linkedList copy3(list);
				copy3.reverseList();
				cout << "<Copy constructor used>New List : ";
				cout << copy3 << "NULL" << endl;
				cout << "<Original list>                   " << list << "NULL" << endl;
			}
			else if (pick2 == 5){
				linkedList copy4(list);
				copy4.deleteDuplicate();
				cout << "<Copy constructor used>New List : ";
				cout << copy4 << "NULL" << endl;
				cout << "<Original list>                   " << list << "NULL" << endl;
			}
			else if (pick2 == 6){
				linkedList copy5(list);
				cout << "Enter your M number(Ex. If 0 is entered, the last element returns. " << endl;
				int m;
				cin >> m;
				if (m > list.listSize() - 1)
				{
					cout << "M is invalid. " << endl;
				}
				else{
					cout << "Node at pos " << m << " M(backward) is ";
					copy5.mtoLastElement(m);
					cout << "<Original list>                   " << list << "NULL" << endl;
				}
			}
			cout << "would you like to do more with this list?  y/n" << endl <<endl;
			char check;
			cin >> check;
			cout << endl;
			if (check == 'y')
			{
				test = true;
			}
			else if (check == 'n')
			{
				break;
			}

		}

	}
	else if (pick == 2)
	{
		linkedList list1;
		cout << "How many nodes do you want to add to the list?" << endl;
		cin >> upperLimit;
		for (int i = 0; i < upperLimit; i++)
		{
			cout << "Enter node ";
			cin >> a;
			list1.insertFront(a);
		}
		cout << "This is your list with insert_Front function." << endl;
		cout << list1 << "NULL" << endl;

		bool test = true;
		while (test == true){
			cout << "What would you list to do with this list?" << endl << endl;
			cout << "1.Pop_back  2.Pop_Front  3.Insert node  4.reverse list  5.delete duplicates  6.find M to last Element" << endl;
			cin >> pick2;
			if (pick2 == 1){
				linkedList copy(list1);
				copy.popBack();
				cout << "<Copy constructor used>New List : ";
				cout << copy << "NULL" << endl;
				cout << "<Original list>                   " << list1 << "NULL" << endl;
			}
			else if (pick2 == 2){
				linkedList copy1(list1);
				copy1.popFront();
				cout << "<Copy constructor used>New List : ";
				cout << copy1 << "NULL" << endl;
				cout << "<Original list>                   " << list1 << "NULL" << endl;
			}
			else if (pick2 == 3){
				linkedList copy2(list1);
				cout << "Please assign a value to the new node and a position in the list" << endl;
				int pos, numb;
				cout << "enter pos "; cin >> pos;
				cout << "enter num "; cin >> numb;
				if (pos > list1.listSize() - 1)
				{
					cout << "Pos size is bigger than the list size, program will now exit. " << endl;
				}
				else{
					copy2.insert(pos, numb);
					cout << "<Copy constructor used>New List : ";
					cout << copy2 << "NULL" << endl;
					cout << "<Original list>                   " << list1 << "NULL" << endl;
				}
			}
			else if (pick2 == 4){
				linkedList copy3(list1);
				copy3.reverseList();
				cout << "<Copy constructor used>New List : ";
				cout << copy3 << "NULL" << endl;
				cout << "<Original list>                   " << list1 << "NULL" << endl;
			}
			else if (pick2 == 5){
				linkedList copy4(list1);
				copy4.deleteDuplicate();
				cout << "<Copy constructor used>New List : ";
				cout << copy4 << "NULL" << endl;
				cout << "<Original list>                   " << list1 << "NULL" << endl;
			}
			else if (pick2 == 6){
				linkedList copy5(list1);
				cout << "Enter your M number(Ex. If 0 is entered, the last element returns. " << endl;
				int m;
				cin >> m;
				if (m > list1.listSize() - 1)
				{
					cout << "M is invalid. " << endl;
				}
				else{
					cout << "Node at pos " << m << " M(backward) is ";
					copy5.mtoLastElement(m);
					cout << "<Original list>                   " << list1 << "NULL" << endl;
				}
			}
			cout << "would you like to do more with this list?  y/n" << endl << endl;
			char check;
			cin >> check;
			cout << endl;
			if (check == 'y')
			{
				test = true;
			}
			else if (check == 'n')
			{
				break;
			}

		}
	}




	////------------------insert front and pop front---------------//
	//linkedList list;
	//cout << "how many nodes?";
	//cin >> upperLimit;
	//for (int i = 0; i < upperLimit; i++){

	//	cout << "<InsertFront>Enter your node ";
	//	cin >> a;
	//	list.insertFront(a);
	//}
	//cout << endl;
	//cout << list;
	//cout << "NULL" << endl;
	//cout << endl;
	//list.popFront();
	//cout << "<PopFront>After removing." << endl;
	//cout << list << "NULL";
	//cout << endl;
	//cout << endl;





	////------------------reverse list---------------//
	//linkedList list1;
	//cout << "<Reverse list - using insert front function to add nodes>Enter your node " << endl;
	//cout << "how many nodes?";
	//cin >> upperLimit;
	//for (int i = 0; i < upperLimit; i++){

	//	cout << "Enter your node ";
	//	cin >> a;
	//	list1.insertFront(a);
	//}
	//cout << "Original list <Created with insertFront funct>." << endl;
	//cout << list1 << "NULL "<<endl;
	//list1.reverseList();
	//cout << "Reverse list." << endl;
	//cout << list1 << "NULL" << endl;

	////cout << endl;
	//


	//
	//////-----------push back and pop back-------------------//
	//linkedList list2;
	//cout << "<PushBack>how many nodes? ";
	//cin >> upperLimit;

	//for (int i = 0; i < upperLimit; i++){

	//	cout << "Enter your node ";
	//	cin >> a;
	//	list2.pushBack(a);
	//}
	//cout << list2;
	//cout << "NULL" << endl;
	//list2.popBack();
	//cout << "<PopBack>After popping back. " << endl;
	//cout << list2 << "NULL";
	//cout << endl;


	//--------------------------insert at specific location
	/*linkedList list3;
	cout << "<Insert at specific pos>how many nodes? ";
	cin >> upperLimit;

	for (int i = 0; i < upperLimit; i++){

		cout << "Enter your node ";
		cin >> a;
		list3.pushBack(a);
	}
	cout << "list created with push back funct " << endl;
	cout << "original list." << endl;
	cout << list3 << "NULL" << endl;
	list3.insert(2, 6);
	cout << "New list." << endl;
	list3.deleteDuplicate();
	cout << list3 << "NULL";
*/


	system("pause");
	return 0;


}