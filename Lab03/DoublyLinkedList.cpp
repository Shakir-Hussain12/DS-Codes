#include <iostream>

using namespace std;

class Node {
	public:
		int value;
		Node* next;
		Node* prev;
	
	Node(int val, Node *nxt = NULL, Node *pre = NULL) {
		value = val;
		next = nxt;
		prev = pre;
	}
};

class LinkedList {
	Node *head;
	Node *tail;
	
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		void append(int val){
			Node *newNode = new Node(val);
			
			if(head == NULL) {
				head = newNode;
				tail = newNode;
			} else {
				Node *temp = head;
				while(temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->prev = temp;
				tail = newNode;
			}
		}
		
		void Display() {
			Node *temp = head;
			while(temp != NULL){
				cout << temp->value << endl;
				temp = temp->next;
			}
			
			cout << "\nReversed" <<endl;
			temp = tail;
			while(temp != NULL){
				cout << temp->value << endl;
				temp = temp->prev;
			}
		}
		
		void swapping(){
			Node *temp = head;
			Node *temp2 = NULL;
			while(temp->next->next != NULL) {
//				cout<< "temp->next : "<<temp->next->value<<endl;
//				cout<< "temp->next->next : "<<temp->next->next->value<<endl;
				if(temp->next->value > temp->next->next->value) {
					temp2 = temp->next;
					temp->next = temp2->next;
					temp2->next->prev = temp;
					temp2->prev = temp->next;
					temp2->next = temp->next->next;
					temp->next->next = temp2;
					
					if(temp2->next == NULL) {
						tail = temp2;
					}
				}
				temp = temp->next;
			}
		}
		
		string Nodeexists(int val){
			if(head==NULL){
				return "False";
			} else {
				Node *temp = head;
				while(temp != NULL) {
					if(temp->value == val) {
						return "True";
					}
					temp = temp->next;
				}
				return "False";
			}
		}
};
int main() {
	LinkedList LL;
	LL.append(1);
	LL.append(3);
	LL.append(2);
	LL.append(5);
	LL.append(4);
//	LL.Display();
	LL.swapping();
	LL.Display();
//	cout << "Node exists: "<< LL.Nodeexists(7) << endl;
}
