#include<iostream>

using namespace std;

void checkArr(int *Arr){
	cout << *(Arr + 1) << endl;
}

int main() {
	int Arr[][2][3] = {{{1,2,3}, {4, 5, 6}}};
//	int Arr[][3] = {{1, 2, 3}};
	
	checkArr(Arr[0][0]);
	return 0;
}



