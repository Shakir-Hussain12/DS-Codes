#include <iostream>

using namespace std;

class Node {
	public:
		int value;
		Node* next;
	
	Node(int val, Node *nxt = NULL) {
		value = val;
		next = nxt;
	}
};

class LinkedList {
	Node *head;
	
	public:
		LinkedList(){
			head = NULL;
		}
		
		void append(int val){
			Node *newNode = new Node(val);
			
			if(head == NULL) {
				head = newNode;
			} else {
				Node *temp = head;
				while(temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
		
		void Display() {
			Node *temp = head;
			while(temp != NULL){
				cout << temp->value << endl;
				temp = temp->next;
			}
		}
		
		void swapping(){
			Node *temp = head;
			Node *temp2 = NULL;
			while(temp->next->next != NULL) {
				cout<< "temp->next : "<<temp->next->value<<endl;
				cout<< "temp->next->next : "<<temp->next->next->value<<endl;
				if(temp->next->value > temp->next->next->value) {
					temp2 = temp->next;
					temp->next = temp2->next;
					temp2->next = temp->next->next;
					temp->next->next = temp2;
					
					delete temp2;
					temp2 = NULL;
				}
				temp = temp->next;
			}
			delete temp;
			temp = NULL;
		}
};
int main() {
	LinkedList LL;
	LL.append(1);
	LL.append(3);
	LL.append(2);
	LL.append(5);
	LL.append(4);
	LL.Display();
	LL.swapping();
	LL.Display();
}
