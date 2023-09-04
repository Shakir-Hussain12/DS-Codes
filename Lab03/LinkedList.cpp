#include<iostream>

using namespace std;

class Node {
	
	public:
		
	int value;
	void *next;

	Node (int v, void *nxt = NULL) {
		value = v;
		next = nxt;
	}
};

class LinkedList {
	Node *head;
	
	public:
		LinkedList(Node* obj){
			head = obj;
		}
		
		void Display(){
			Node *temp = head;
			cout << temp->value <<endl;
		}
};

int main() {
	Node* first = new Node(6);
	LinkedList* LL = new LinkedList(first);
	LL->Display();
	return 0;
}
