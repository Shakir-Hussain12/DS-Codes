//
//None selected
//
//Skip to content
//Using NUCES-FAST Mail with screen readers
//
//Conversations
//Using 99,412.03 GB
//Program Policies
//Powered by Google
//Last account activity: in 8 hours
//Details
#include<iostream>
using namespace std;
class node
{
public:
	int val;
	node* next;
	node()
	{
		val = 0;
		next = NULL;
	}
	node(int v)
	{
		val = v;
		next = NULL;
	}
	~node()
	{
		if (next != NULL)
		{
			delete next;
			next = 0;
		}
	}
};
class linkedlist
{
public:
	node* head;
	linkedlist()
	{
		head = NULL;
	}
	~linkedlist()
	{
		delete head;
		head = 0;
	}
	void appendAtTail(int v)
	{
		node* newNode = new node(v);

		if (head == NULL)
		{
			head = newNode;
		}
		else if (head != NULL)
		{
			node* ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = newNode;
		}
	}
	void appendAtHead(int v)
	{
		node* newNode = new node(v);
		newNode->next = head;
		head = newNode;
	}
	void addAfterValue(int v, int value)
	{
		node* newNode = new node(v);
		node* ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			if (ptr->val == value)
			{
				break;
			}
		}
		node* p1 = ptr;
		p1 = p1->next;
		ptr->next = newNode;
		newNode->next = p1;
	}
	void deletionAtLast()
	{
		node* ptr = head;
		while (ptr->next->next != NULL)
		{
			ptr = ptr->next;
		}
		node* p1 = ptr;
		p1 = p1->next;
		delete p1;
		p1 = NULL;
		ptr->next = NULL;
	}
	void deletionAtValue(int value)
	{
		node* ptr=head;
		if(ptr->val==value)
		{
		  head=head->next;
		  delete ptr;
			ptr=0;
		} else {
			while(ptr->next->val!=value)
			{
				ptr=ptr->next;
			}
			node* temp=ptr->next;
			ptr->next=ptr->next->next;
			temp->next=NULL;
			delete temp;
			temp=0;
		}
	}
	
	void deletionAtIndex(int index)
	{
		int count = 1;
		node* ptr = head;
		while (ptr->next != NULL)
		{
			if (count == (index-1))
				break;
			ptr = ptr->next;
			count++;
		}
		node* p1 = ptr;     //for deletion of value
		p1 = p1->next;
		node* otherptr = head;   //for referencing the pointer after value
		int othercount = 1;
		while (otherptr->next != NULL)
		{
			if (othercount==(index+1))
			{
				break;
			}
			otherptr = otherptr->next;
			othercount++;
		}
		ptr->next = otherptr;
	}
	void printlist()
	{
		cout << "list is: " << endl;
		node* p = head;
		while (p != NULL)
		{
			cout << p->val << ", ";
			p = p->next;
		}
		cout << endl;
	}
};
int main()
{
	linkedlist l;
	l.appendAtTail(4);
	l.appendAtTail(5);
	l.appendAtTail(6);
	l.appendAtHead(2);
	l.appendAtHead(1);
	l.appendAtTail(7);
	l.appendAtTail(8);
	l.appendAtTail(9);
	l.printlist();
	l.addAfterValue(3, 2);
	l.printlist();
	/*l.deletionAtLast();
	l.printlist();*/
	l.deletionAtValue(5);
	l.printlist();
	l.addAfterValue(5, 4);
	l.printlist();
	l.deletionAtIndex(4);
	l.printlist();
}
//task3 deletion of link list 22k4159 lab 3.cpp
//Displaying task3 deletion of link list 22k4159 lab 3.cpp.
