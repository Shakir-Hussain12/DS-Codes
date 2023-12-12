#include <iostream>

using namespace std;

void printArr(int *arr, int i) {
	if(i >= 5) {
		return ;
	}
	
	cout << "Before Loop: " << arr[i] << endl;
	printArr(arr, i + 1);
	cout<< "\n\n";
	cout << "After Loop: " << arr[i] << endl;
}

int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	
	int i = 0;
	printArr(arr, i);
	return 0;
}
