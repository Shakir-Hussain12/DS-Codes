#include<iostream>

using namespace std;

class Node {
	public:
		int data;
		int level;
		Node *left;
		Node *right;
		
		Node(int d, int lvl) {
			data = d;
			level = lvl;
			left = NULL;
			right = NULL;
		}
};

void traversal(Node *root) {
	if (root == NULL) {
		return;
	}
	
	traversal(root->left);
	cout<<"Data : "<<root->data<<endl;
	traversal(root->right);
}

bool checkperfect(Node *root) {
	if(root){
		if(root->left && root->right && root->right->level!=root->left->level) {
			return false;
		}
		
		if(root->left==NULL&&root->right!=NULL||root->right==NULL&&root->left!=NULL){
		    return false;
		}
		
		if(root->left) {
			if(!checkperfect(root->left)){
				return false;
			}
		}
		
		if(root->right) {
			if(!checkperfect(root->right)){
				return false;
			}
		}
		
		return true;
    }
}
int main() {
	Node *root = new Node(4, 0);
	root->left = new Node(2, 1);
	root->right = new Node(6, 1);
	root->left->left = new Node(7, 2);
	root->left->right = new Node(1, 2);
	root->right->left = new Node(3, 2);
	root->right->right = new Node(8, 2);
	cout<<checkperfect(root)<<endl;
	return 0;
}
