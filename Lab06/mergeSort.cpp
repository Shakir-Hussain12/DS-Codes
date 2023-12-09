#include<iostream>

using namespace std;


void merge(int arr[], int left[], int right[], int first, int second){
	int i = 0, j = 0, k = 0;
	while( i < first && j < second) {
		if (left[i] < right[j]) {
			arr[k] = left[i];
			k++;
			i++;
		} else {
			arr[k] = right[j];
			k++;
			j++;
		}
	}
	
	while ( i < first ) {
		arr[k] = left[i];
		k++;
		i++;
	}
	
	while ( j < second ) {
		arr[k] = right[j];
		k++;
		j++;
	}
}

void divide(int arr[], int size) {
	if(size <= 1) {
		return;
	}
	
	int mid = size / 2;
	int left[mid];
	int right[size - mid];
	
	for(int i = 0;i < mid; i ++) {
		left[i] = arr[i];
	}
	
	for(int j = mid;j < size; j++ ) {
		right[j - mid] = arr[j];
	}
	
	divide(left, mid);
	divide(right, size - mid);
	merge(arr, left, right, mid, size - mid);
}

int main() {
	int arr[] = {38, 27, 43, 3, 9, 82, 10};
	divide(arr, 7);
	
	std::cout << "Sorted array: ";
    for (int i = 0; i < 7; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
	return 0;
}
