#include<iostream>

using namespace std;
 
class Node {
	public:
		int key;
		string label; //for character labels
		
		Node () {
			key = 0;
			label = "";
		}
		
		Node(int k, string l) {
			key = k;
			label = l;
		}
};

int num_vertices = 5; // vertices in graph
int matrix[5][5] = {0}; // adjacency matrix to store costs between connected vertices
Node *Vertices[6] = {NULL}; // array to store Vertices to access via index

// marking connected nodes
void addEdge(int src, int dest, int cost) {
	matrix[src][dest] = cost;	
}

// Displaying connected Nodes
void Display() {
	for(int i = 0; i < num_vertices; i++) {
		cout << "Src Vertex : " << Vertices[i]->label << endl;
		for(int j = 0; j < num_vertices; j++) {
			if(matrix[i][j] != 0) {
				cout << "Neighbor : " << Vertices[j]->label << "  cost : "<< matrix[i][j] << "\t";
			}
		}
		cout << endl;
	}
}

int main() {
	
	// initializing Vertices
	Vertices[0] = new Node(0, "A");
	Vertices[1] = new Node(1, "B");
	Vertices[2] = new Node(2, "C");
	Vertices[3] = new Node(3, "D");
	Vertices[4] = new Node(4, "E");
	Vertices[5] = new Node(5, "F");
	
	// adding connections
	addEdge(0,1, 5);
	addEdge(0,2, 6);
	addEdge(1,3, 7);
	addEdge(1,4, 8);
	addEdge(2,5, 9);
	addEdge(3,5, 10);
	addEdge(4,5, 11);
	
	Display();
	
	return 0;
}
