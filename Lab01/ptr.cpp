#include<iostream>

using namespace std;

int main() {
//	traditional
	int Arr[] = {1,2,3};
	cout<<Arr[0]<<endl;
	
	//new
	int *ptr = new int[3] {1,2,3};
	cout<<ptr<<endl;
	cout<<*ptr<<endl;
	cout<<ptr[0]<<endl;
	
	delete[] ptr;
	cout<<ptr<<endl;
	cout<<*ptr<<endl;
	
	return 0;
} 
