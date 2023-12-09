#include <iostream>

using namespace std;

class Node {
	public:
		int key;
		int value;
		Node* next;
		Node* prev;
	
	Node(int k, int val, Node *nxt = NULL, Node *pre = NULL) {
		key = k;
		value = val;
		next = nxt;
		prev = pre;
	}
};

class LinkedList {
	public:
	Node *head;
	Node *tail;
	
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		bool NodeExists(int key) {
			if (head == NULL) {
				return false;
			}
			
			if(key == head->key){
				return true;		
			} else {
				Node *temp = head->next;
				while (temp!=head) {
					if(key == temp->key) {
						return true;
					}
					temp = temp->next;
				}
			}
			
			return false;
		}
		
		void append(int key, int val){
			if(NodeExists(key)) {
				cout << "Node already exists" << endl;
			} else {
				Node *newNode = new Node(key, val);
				if(head == NULL) {
					head = newNode;
					tail = newNode;
				} else {
					if(key < head->key) {
						newNode->next=head;
						head->prev=newNode;
						head=newNode;
						head->prev=tail;
						tail->next=head;
						return;
					}
					
					if(key > tail->key) {
						tail->next=newNode;
						newNode->prev=tail;
						tail=newNode;
					} else {
						Node *temp = head;
						while(key > temp->next->key) {
							temp = temp->next;
						}
						newNode->next=temp->next;
						newNode->prev=temp;
						temp->next->prev=newNode;
						temp->next=newNode;
					}
					
				}
				
				tail->next = head;
				head->prev = tail;
			}
			
		}
		
		void Display() {
			if (head == NULL) {
				cout << "List is empty" << endl;
			} else {
				cout << "Key = " << head->key << " Value = " << head->value << endl;
				Node *temp = head->next;
				while(temp != head){
					cout << "Key = " << temp->key << " Value = " << temp->value << endl;
					temp = temp->next;
				}
			}
			
			cout << "\nReversed" <<endl;
			cout << "Key = " << tail->key << " Value = " << tail->value << endl;
			Node *temp = tail->prev;
			while(temp != tail){
				cout << "Key = " << temp->key << " Value = " << temp->value << endl;
				temp = temp->prev;
			}
		}
		
		void swapping(){
			Node *temp = head;
			Node *temp2 = NULL;
			while(temp->next->next != NULL) {
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
};












int main() {
	LinkedList LL;
	LL.append(3, 1);
//	cout << LL.head->value << endl;
//	LL.append(3, 2);
	LL.append(4, 2);
//	cout << LL.head->value << endl;
	LL.append(2, 5);
//	cout << LL.head->value << endl;
	LL.append(6, 2);
	LL.append(1, 5);
	LL.append(5, 15);
//	LL.swapping();
	LL.Display();
}






