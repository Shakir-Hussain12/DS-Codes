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
};
int main() {
	LinkedList LL;
	LL.append(1);
	LL.append(2);
	LL.append(3);
	LL.Display();
}
