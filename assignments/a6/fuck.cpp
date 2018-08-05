#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
void try_this(char **board, char **user_array,int );




/*********************************************************************************
 * Function: main
 * Description: runs through functions
 * Parameters: int, char*
 * Pre-Conditions: 3 positive integers entered with command lines -c -m - r
 * Post-Conditions: none
 *********************************************************************************/
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int rows=10, cols=10, mines =10;
	char **board = new char*[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new char[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = '0';
		}
	}
		char **user_array = new char*[rows];
	for (int i = 0; i < rows; i++) {
		user_array[i] = new char[cols];
	}
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			user_array[i][j] = ' ';
		}
	}

		for(int i = 0 ; i < rows;i++){
		delete [] board[i]; 
		delete [] user_array[i];
		}
	delete [] user_array;
	delete [] board;

	try_this(board, user_array, rows);
}

void try_this(char **board, char **user_array, int rows){
	

	
}
