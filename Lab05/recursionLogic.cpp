#include<iostream>

using namespace std; 


void printFunctions(int i) {
	if (i > 3) {
		return;
	}
	
	cout << "First function : " << i << endl;
	printFunctions(i + 1);
	
	cout << "Second function : " << i << endl;
	printFunctions(i + 1);
	
	cout << "Last thing in each function : " << i << endl;  
}

int main() {
	printFunctions(0);	
	return 0;
}
