#include<iostream>
using namespace std;
 
class Node
{
	public:
		int data;
		Node* next;
		
		Node()
		{
			
		}
		Node(int d)
		{
			data=d;
			next=NULL;
			
		}
};

class LinkedList
{
	public:
		
		Node* head;
		
	 
		LinkedList()
		{
			head=NULL;
		}
			LinkedList(Node * h)
		{
			head=h;
		}
		
		void InsertAtFront(int d){
			
			Node * N1=new Node(d);
			if(head==NULL) {
				head=N1;
				
			} else {
				
				Node * ptr= head;
				
				while(ptr->next!=NULL) {
					ptr=ptr->next;
				}
						
				ptr->next=N1;
			}
						
		}

		void DeleteNodeByValue(int value)
		{	
			Node*temp=head;
			int found = 1;
			
			if (temp->data == value) {
				head = head->next;
				delete temp;
				temp = NULL;
				return;
			}
			
			while(temp->next->data != value)
			{
				temp = temp->next;
				if (temp->next == NULL) {
					found = 0;
					break;
				}
			}
			
			if (found == 1 ) {
				Node*store=temp->next;
				temp->next=temp->next->next;
			
				delete store;
				store=NULL;
				
			} else {
				cout << "Value doesn't exist" << endl;
			}
		}
		
		void Print( )
		{
			Node * temp=head;
			while( temp!=NULL)
			{
				cout<<" "<<temp->data;
				temp=temp->next;
			}
		}
};

int main()
{

	LinkedList L1;
	L1.InsertAtFront(12);
	L1.InsertAtFront(10);
	L1.InsertAtFront(15);
	L1.InsertAtFront(40);
	
	L1.DeleteNodeByValue(35);
	L1.Print();
	
}
