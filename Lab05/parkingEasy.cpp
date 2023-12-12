#include <iostream>
#include <algorithm>

using namespace std;

int destx = 0;
int desty = 3;
int mindist = 99999;
int paths[4][10];
int parkx = 0, parky = 0;

bool isvalid(int arr[][4], int i, int j) {
	return i < 3 && j < 4 && arr[i][j] == 1;
}

void park_car(int arr[][4], int i, int j, int mindest, int dist) {
//	cout << "Locating Parking Area" << endl;
	if (arr[i + 1][j] == 2) {
		parkx = i + 1;
		parky = j;
		return;
	}
	
	if (arr[i - 1][j] == 2) {
		parkx = i - 1;
		parky = j;
		return;
	}
	
	if (arr[i][j + 1] == 2) {
		parkx = i;
		parky = j + 1;
		return;
	}
	
	if (arr[i][j - 1] == 2) {
		parkx = i;
		parky = j - 1;
		return;
	}
	
	arr[i][j] = -1;
	
	if(isvalid(arr, i + 1, j)){
		park_car(arr, i + 1, j, mindest, dist + 1);
	}
	
	if(isvalid(arr, i - 1, j)){
		park_car(arr, i - 1, j, mindest, dist + 1);
	}
	
	if(isvalid(arr, i, j + 1)){
		park_car(arr, i, j + 1, mindest, dist + 1);
	}
	
	if(isvalid(arr, i, j - 1)){
		park_car(arr, i, j - 1, mindest, dist + 1);
	} 
	
	arr[i][j] = 1;
}

void find_path(int arr[][4], int i, int j, int mindest, int dist) {
	if (i == destx && j == desty) {
		mindist = min(dist, mindest);
		return;
	}
		
	arr[i][j] = 0;
	
	if(isvalid(arr, i + 1, j)){
		paths[0][dist] = arr[i + 1][j];
		find_path(arr, i + 1, j, mindest, dist + 1);
	}
	
	if(isvalid(arr, i - 1, j)){
		paths[1][dist] = arr[i - 1][j];
		find_path(arr, i - 1, j, mindest, dist + 1);
	}
	
	if(isvalid(arr, i, j + 1)){
		paths[2][dist] = arr[i][j + 1];
		find_path(arr, i, j + 1, mindest, dist + 1);
	}
	
	if(isvalid(arr, i, j - 1)){
		paths[3][dist] = arr[i][j - 1];
		find_path(arr, i, j - 1, mindest, dist + 1);
	} 
	
	arr[i][j] = 1;
}

int main() {
	int maze[3][4] = {{1, 0, 0, 1}, 
		              {1, 1, 1, 1},
		              {0, 1, 1, 0}};
	find_path(maze, 0, 0, mindist, 0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < sizeof(paths[i])/sizeof(paths[i][0]); j++) {
			cout << paths[i][j];
		}
		cout << "\n";
	}
	
//	int parkingArea [3][4] = {{1, 1, 1, 1},
//							  {1, 1, 1, 2},
//							  {1, 2, 1, 1}};  
//	
//	int i = 0;
//	while(i < 2) {
//		mindist = 99999;
//		park_car(parkingArea, 0, 0, mindist, 0);
//		parkingArea[parkx][parky] = 1;
//		cout<< "Parking location: " << parkx << " " << parky << endl;
//		i++;
//	}
	
	return 0;
}
