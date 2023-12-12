#include <iostream>
#include <vector>

using namespace std;

int n = 7;
int chessboard[7][7] = {0};

int move_x[] = {2, 1, -1, -2, -2, -1, 1, 2};
int move_y[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValidMove(int x, int y, int n) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

void placeKnight(int x, int y) {
  chessboard[x][y] = 1;
}


void removeKnight(int x, int y) {
  chessboard[x][y] = 0;
}

void printChessboard(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << chessboard[i][j] << " ";
    }
    cout << endl;
  }
}

bool checkKnight(int n, int x, int y) {
	for (int i = 0; i < 8; i++) {
		int new_x = x + move_x[i];
		int new_y = y + move_y[i];
		if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < n) {
			if(chessboard[new_x][new_y] == 1) {
				return false;
			}
		}
	}
	return true;
}

bool placeKnights(int n, int k, int x, int y) {
	if(k == ((n * n) + 1)/2) {
		printChessboard(n);
		cout << endl;
		return true;
	}

	if (x > n-1) {
		return false;
	}
	
	if(y > n - 1) {
		x += 1;
		y = 0;
	}
	
	if (isValidMove(x, y, n)) { //here I am checking boundary values
		if (checkKnight(n, x, y)) { // here I am checking for Possible attacks
			placeKnight(x, y); // placing Knight
			placeKnights(n, k + 1, x, y + 1); // moving to the next cell
			//you can return here, But i just didn't cuz i wanted to sell all possible combinations
			removeKnight(x, y); // backtracking here
		}	
		placeKnights(n, k, x, y + 1); //if knight already there, just move to next column
	}
	
}

int main() {
	placeKnights(n, 0, 0, 0);
  	return 0;
}
