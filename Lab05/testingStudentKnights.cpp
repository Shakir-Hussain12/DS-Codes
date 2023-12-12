#include <iostream>
#include <stdlib.h>
using namespace std;

int move_x[] = {2, 1, -1, -2, -2, -1, 1, 2};
int move_y[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int** arr,int x,int y,int n){
	//fixed this part
	for (int i = 0; i < 8; i++) {
		int new_x = x + move_x[i];
		int new_y = y + move_y[i];
		if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n) {
			if(arr[new_x][new_y] == 1) {
				return false;
			}
		}
	}
	return true;
}

bool nKnight(int **arr,int x,int y,int n,int count){
	if(count==0){
		return true;
	}
	
	//and this
	if(y >= n){
		y = 0;
		x += 1;
	}
	
	//additional check
	if(x > n - 1) {
		return false;
	}
	
	if(isSafe(arr,x,y,n)){
		arr[x][y]=1;
		//when working with recursion, pre increment/decrement or do itr -/+ 1
		if(nKnight(arr,x,y+1,n,count - 1)){
			return true;
		}
		arr[x][y]=0;
	}
	
	return nKnight(arr,x,y+1,n,count);
	
}

int main(){
	int n = 5,count=0;
	
	
	int **arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	if(n %2 ==0){
		count=(n*n)/2;
	}
	else{
		count=(n*n)+1;
		count=count/2;
	}
	
    if(nKnight(arr,0,0,n,count)){
		for(int i=0;i<n;i++){
		    for(int j=0;j<n;j++){
			cout << arr[i][j] << " ";
		    }
		    cout << endl;
	    }
	}
	
	return 0;	
}
