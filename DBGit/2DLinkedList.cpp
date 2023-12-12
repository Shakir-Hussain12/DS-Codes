#include<iostream>

using namespace std;

class Node {
	public:
		int num;
		Node *next;
		Node *nhead;
		
		Node (int val) {
			num = val;
			next = NULL;
			nhead = NULL;
		}	
};

class Link {
	Node *head;
	
	public:
		Link() {
			head = NULL;
		}
		
		void appendParent(int index) {
			Node *newNode = new Node(index);
			if(head == NULL) {
				head = newNode;
			} else {
				Node *temp = head;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
		
		void appendChild(int index, int val){
			Node *temp = head;
			int i = 1;
			if(head == NULL) {
				head = new Node(0);
				head->nhead = new Node(val);
			} else {
				while(temp->next != NULL && i < index) {
					temp = temp->next;
					i++;
				}
				
				if (temp->next == NULL) {
					temp->next = new Node(i);
				}
				
				if (temp->next->nhead == NULL) {
					temp->next->nhead = new Node(val);
				} else {
					Node *temp1 = temp->next->nhead;
					while(temp1->next != NULL) {
						temp1 = temp1->next;
					}
					temp1->next = new Node(val);
				}
			}	
		}
		
		void Display() {
			Node *temp = head;
			while (temp != NULL) {
				cout << "Parent Node : " << temp->num << endl;
				Node *temp1 = temp->nhead;
				cout << "Child Nodes : "; 
				while(temp1 != NULL) {
					cout << temp1->num << " -> ";
					temp1 = temp1->next;
				}
				temp = temp->next;
				cout << endl;
			}
		}
};

int main() {
	Link L;
	L.appendParent(0);
	L.appendChild(1, 2);
	L.appendChild(1, 3);
	L.appendChild(1, 4);
	L.appendChild(2, 8);
	L.appendChild(2, 7);
	L.appendChild(3, 5);
	L.appendChild(3, 9);
	L.Display();
	
	return 0;
}
