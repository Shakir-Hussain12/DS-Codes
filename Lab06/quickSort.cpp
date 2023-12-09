#include<iostream>

using namespace std;

int conquer(int arr[], int start, int end) {
	int pivot = arr[end];
	int ind = start;
	
	for (int i = start; i < end; i++) {
		if(arr[i] < pivot){
			swap(arr[ind++],arr[i]);
		}
	}
	
	swap(arr[ind],arr[end]);
	
	return ind;
}

void divide(int arr[], int start, int end) {
	if (start < end) {
		int p_index = conquer(arr, start, end);
		
		divide(arr, start, p_index - 1);
		divide(arr, p_index + 1, end);
	}
}

int main() {
	int arr[] = { 2, 1, 4, 7, 0, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	divide(arr, 0, size - 1);
	for(int i = 0; i < size; i++) {
		cout<<arr[i]<< " ";
	}
	cout << endl;
	return 0;
}

