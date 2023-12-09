#include<iostream>

using namespace std;

class Node {
	
	public:
		
	int value;
	Node *next;

	Node (int v, Node *nxt = NULL) {
		value = v;
		next = nxt;
	}
};

class LinkedList {
	
	public:
	Node *head;
	
	public:
		LinkedList(){
			head = NULL;
		}
		
		void Display(){
			Node *temp = head;
			while(temp != NULL) {
				cout << temp->value << endl;
				temp = temp->next;
			}
		}
		
		void append(int val, Node* temp) {
			if(head == NULL) {
				head = new Node(val);
				return;
			} else {
				if (temp->next == NULL) {
					temp->next = new Node(val);
					return;
				}
				
				append(val, temp->next);	
			}
		}
};

int main() {
	LinkedList LL;
	LL.append(1, LL.head);
	LL.append(2, LL.head);
	LL.append(3, LL.head);
	LL.Display();
	return 0;
}
