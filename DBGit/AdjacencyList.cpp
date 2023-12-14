#include <iostream>
using namespace std;

class AdjNode {
	public:
		int cost; // for edge cost
	    int key; //Any one of your choice (key of Dest)
	//    Vertex obj; //Any one of your choice (obj of Dest)
	    AdjNode* next;
	    
	    AdjNode(int k, int c) {
	    	key = k;
			cost = c;
	    	next = NULL;
		}
};

class Vertex {
	public:
	    int data;
	    int key;
	    int cost; //if dijkstra
	    AdjNode* head; //List head    
	    
	    Vertex(int d, int k) {
	    	data = d;
	    	key = k;
	    	cost = 9999;
	    	head = NULL;
		}
};

class Graph {
	Vertex* arr[5] = {}; //array of vertices for adjacency list
    
    public:
	    Graph() {
	    	
		}
		
		void InsertEdge(Vertex *src, Vertex *dest, int cost) {
			//if directed
			if(arr[src->key] == NULL) {
				arr[src->key] = src;
			}	
			
			if(arr[src->key]->head == NULL) {
				arr[src->key]->head = new AdjNode(dest->key, cost);
			} else {
				AdjNode *temp = arr[src->key]->head;
				while(temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new AdjNode(dest->key, cost);
			}
			
			//if undirected
			if(arr[dest->key] == NULL) {
				arr[dest->key] = dest;
			}	
			
			if(arr[dest->key]->head == NULL) {
				arr[dest->key]->head = new AdjNode(src->key, cost);
			} else {
				AdjNode *temp = arr[dest->key]->head;
				while(temp->next != NULL) {
					temp = temp->next;
				}
				temp->next = new AdjNode(src->key, cost);
			}
		}
		
		void Display() {
			for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
	        	if (arr[i] != 0) {
	        		cout << "Parent Key : " << arr[i]->key << endl;
	        		AdjNode *temp = arr[i]->head;
	        		while(temp != NULL) {
	        			cout<<"Key : " << temp->key << " Cost : " << temp->cost << "\t";
	        			temp = temp->next;
					}
					cout<<endl;
				}
	    	}
		}
};

Vertex V1('S', 0);
Vertex V2('A', 1);
Vertex V3('B', 2);
Vertex V4('C', 3);
Vertex V5('D', 4);
	
int main () {
    
    Graph G;
    G.InsertEdge(&V1, &V2, 2);
    G.InsertEdge(&V1, &V3, 4);
    G.InsertEdge(&V2, &V3, 5);
    G.InsertEdge(&V2, &V4, 6);
    G.InsertEdge(&V3, &V4, 7);
    G.InsertEdge(&V4, &V5, 8);
    
    G.Display();
    return 0;
}

