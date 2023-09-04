#include<iostream>

using namespace std;

int main() {
	
	int cols = 2;
	int rows = 2;
	int elem;
	
	int **ptr = new int*[rows];
	
	for(int i = 0; i < rows; i++ ) {
		ptr[i] = new int[cols];
		for(int j = 0; j < cols; j++) {
			cin>>*(*(ptr + i)+j);
//			cin>>ptr[i][j]
		}
	}
	
	for(int i = 0; i < rows; i++ ) {
		for(int j = 0; j < cols; j++) {
			cout<<*(*(ptr+i)+j)<<"\t";
//			cout<<ptr[i][j]
		}
		cout<< endl; 
	}

	for(int i = 0; i < rows; i++ ) {
		delete[] ptr[i];
	}

	delete[] ptr;
	
	return 0;
}

