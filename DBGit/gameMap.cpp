#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

class Map {
	public:
	    int key;
	    string name;
	    bool boss;
	    int cost;
	    bool visited;
		
		Map() {
			key = 0;
			name = "";
			boss = 0;
			cost = 0;
			visited = false;
		}
};

class Graph {
	public:
		int num_vertices;
		int **adjMatrix;
		int **preds;
		Map **maps;
		stack <int> s;
		
		Graph(int n) {
			num_vertices = n;
			adjMatrix = new int*[n];
		    for (int i = 0; i < n; i++) {
		        adjMatrix[i] = new int[n]{0};
		    }
		    
		    maps = new Map*[n]{0};
		    preds = new int*[n]{};
		    for (int i = 0; i < n; i++) {
		    	preds[i] = new int[n]{0};
			}
		}
		
		void setMaps() {
			for (int i = 0; i < num_vertices; i++) {
		    	if(maps[i] == 0) {
		    		maps[i] = new Map();
		    		maps[i]->key = i;
		    		fflush(stdin);
			    	cout << "Enter Label for Map " << i << ": ";
			    	cin >> maps[i]->name;
			    	fflush(stdin);
			    	cout << "Enter Cost of Map " << i << ": ";
			    	cin >> maps[i]->cost;
			    	fflush(stdin);
			    	cout << "Set Boss Value for Map " << i << ": ";
					cin >> maps[i]->boss;
					fflush(stdin);
				}
			}
		}
		
		void displayMapDetails() {
		    for (int i = 0; i < num_vertices; i++) {
		        cout << "Key: " << maps[i]->key << " Label: " << maps[i]->name << " Boss: " << maps[i]->boss << " Cost: " << maps[i]->cost << endl;
		    }
		}
		
		void insertEdge(int i, int j) {
			adjMatrix[i][j] = 1;
		}
		
		void displayGraph() {
		    for (int i = 0; i < num_vertices; i++) {
		        for (int j = 0; j < num_vertices; j++) {
		            cout << adjMatrix[i][j] << " ";
		        }
		        cout << endl;
		    }
		}
		
		// initializing all predecessors
		void initializePredecessors() {
			for(int i = 0; i < num_vertices; i++) {
				for(int j = 0; j < num_vertices; j++) {
					preds[i][j] = -1;
				}
			}
		}
		
		// setting predecessors for each Node
		void setPredecessors() {
			int k = 0;
			for(int i = 0; i < num_vertices; i++) {
				for(int j = 0; j < num_vertices; j++) {
					if (adjMatrix[i][j] == 1) {
						preds[j][k] = i;
					}
				}
				k++;
			}
		}
		
	    void findPath() {
	        int current = 5;
	        bool check = false;
	        
	        // starting with cost of last(goal) Node
	        int cost = maps[current]->cost;
	        // adding cost of starting node & setting it to visited
	        cost+= maps[0]->cost;
	 		maps[0]->visited = true;
	        int temp = 0;
	        int new_index = 0;
	 		
	 		// using stack to print path later in reverse
	 		s.push(maps[current]->key);
	        while(current != 0) {
	        	// condition for goal node
	        	if(current == 5) {
	        		for(int i = 0; i < num_vertices; i++) {
	        			if(preds[current][i] != - 1) {
	        				// checking predecessors and adding their costs if their boss value is true
	        				if(maps[preds[current][i]]->boss && !maps[preds[current][i]]->visited) {
	        					s.push(preds[current][i]);
	        					cost += maps[preds[current][i]]->cost;
								maps[preds[current][i]]->visited = true;
								if(!check) {
									// moving to the predecessor for DFS
									new_index = preds[current][i];
									check = true;
								} 		
							}
						}
					}
					current =  new_index;
				} else {
					// codition for other nodes
					for(int i = 0; i < num_vertices; i++) {
	        			if(preds[current][i] != - 1) {
	        				// checking predecessors and adding their costs if current node's boss value is true
	        				if(maps[current]->boss && !maps[preds[current][i]]->visited) {
	        					s.push(preds[current][i]);
	        					cost += maps[preds[current][i]]->cost;
								maps[preds[current][i]]->visited = true;
								new_index = preds[current][i]; 		
							} else if (maps[current]->visited) {
								// moving to the predecessor for DFS
								new_index = preds[current][i]; 
							}
						}
					}
					current =  new_index;
				}
			}
			s.push(0);
			
	        // Display the optimal path
	        cout << "Optimal path to win the game: [";
	        for (int i = 0; i < num_vertices; i++) {
	            if(!s.empty()) {
	            	cout << s.top() << " ";
	            	s.pop();
				} else {
					break;
				}
	        }
	        cout << "]" << endl;
	        cout << "Total cost: " << cost << endl;
	    }   
};
		
int main() {
    int n;
    cout << "Enter the total number of maps: ";
    cin >> n;
	
	Graph G(n);
		
	G.setMaps();
	G.displayMapDetails();
	
	G.insertEdge(0, 1);
	G.insertEdge(0, 2);
	G.insertEdge(0, 4);
	G.insertEdge(1, 3);
	G.insertEdge(2, 3);
	G.insertEdge(3, 5);
	G.insertEdge(4, 5);
	
	G.displayGraph();
	G.initializePredecessors();
	G.setPredecessors();
	G.findPath();
    return 0;
}
