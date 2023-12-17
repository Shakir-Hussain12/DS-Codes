#include<iostream>
#include<stack>

using namespace std;

class Node {
	public:
		int val;
		Node *left;
		Node *right;
		
		Node(int val) {
			this->val = val;
			left = NULL;
			right = NULL;
		}
};

stack<Node *> s1;

// function to implement DFS
void leftSide(Node *temp) {
	while(temp != NULL) {
		s1.push(temp);
		temp = temp->left;
	}
}

int main() {
	//setting output conditions
	int prev = -1;
	int target = 6;
	int ans = -1;
	
	//hard coding tree nodes
	Node n1(1);
	n1.left = new Node(2);
	n1.right = new Node(3);
	
	n1.left->left = new Node(4);
	n1.left->right = new Node(5);
	
	n1.right->left = new Node(6);
	n1.right->right = new Node(7);
	
	n1.left->left->left = new Node(8);
	n1.right->right->right = new Node(9);
	
	// main logic -> using stack to generate inorder traversal instead of recursion
	// pushing left side starting with root node
	leftSide(&n1);
	
	while(!s1.empty()) {
		// storing & popping top of stack(inorder-traversed node)
		Node *temp = s1.top();
		s1.pop();
		
		// checking predecessor node
		if(prev == target) {
			// storing successor node(output)
			ans = temp->val;
			break; //comment this line to see full in-order traversal
		}
		
		// updating predecessor node
		prev = temp->val;
		cout << temp->val << endl;
		 
		//checking if right side exists
		if (temp->right) {
			// pushing all left sided elements(if any), else pushes right Node 
			leftSide(temp->right);
		}
	}
	
	//printing output
	cout << "Successor Node : " << (ans == -1 ? "None" : to_string(ans)) << endl;
	return 0;
}

