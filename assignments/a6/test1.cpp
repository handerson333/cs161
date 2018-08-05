#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

//FUNCTIONS
bool is_pos(int);
void print_data(int, int, int);
void make_hidden_map2(char**, int, int, int);
int make_hidden_map3(char**, int, int, int, int, int);
int make_hidden_map4(char**, int, int, int, int, int);
void menu(char**, char**, int, int, int);
void user_board(char**, char**, int, int, int, int, int, int);
void print_board(char**, char**, int, int, int);
void new_board(char**, int, int, int);
void gameover(char**, char**);
void main2();
void winner_search(char**, char**, int, int, int);
void place_mines(char**, int, int, int);
void get_args(int argc, char *argv[], int &rows,int &cols, int &mines);
int is_num(string input);



/*********************************************************************************
* Function: main
* Description: runs through functions
* Parameters: int, char*
* Pre-Conditions: 3 positive integers entered with command lines -c -m - r
* Post-Conditions: none
* Line Count: 19
*********************************************************************************/
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int rows=10, cols=10, mines =10;
	get_args(argc, argv, rows,cols,mines);
	print_data(rows, mines, cols);
}

/*********************************************************************************
* Function: print_data
* Description: prints the ammount of rows, columns, and mines
* Parameters: int, int, int
* Pre-Conditions: must be positive integers
* Post-Conditions: none
* Line Count: 18
*********************************************************************************/
void print_data(int rows, int mines, int columns) {
	if (mines >= (columns*rows)) {
		cout << "Too Many Mines!!!" << endl;
		exit(0);
	}
	cout << endl << rows << " rows" << endl;
	cout << columns << " columns" << endl;
	cout << mines << " mines\n" << endl;
	char **myArray = new char*[rows];
	for (int i = 0; i < rows; ++i) {
		myArray[i] = new char[columns];
	}
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			myArray[i][j] = '0';
		}
	}
	place_mines(myArray, rows, columns, mines);
}

/*********************************************************************************
* Function: place_mines
* Description: randomly places mines, loops if the same random number is used
* Parameters: char** , int, int, int
* Pre-Conditions: positive integers, must fit inside array
* Post-Conditions: none
* Line Count: 9
*********************************************************************************/
void place_mines(char** myArray, int rows, int columns, int mines) {
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (myArray[i][j] == '*') {
				count++;
			}
		}
	}
	if (count == mines) {
		make_hidden_map2(myArray, rows, columns, mines);
	}
	myArray[rand() % rows][rand() % columns] = '*';
	place_mines(myArray, rows, columns, mines);
}

/*********************************************************************************
* Function: make_hidden_map2
* Description: fills the array with numbers in relation to mines
* Parameters: char **, int, int, int
* Pre-Conditions: positive numbers, within range of array
* Post-Conditions: none
* Line Count: 10
*********************************************************************************/
void make_hidden_map2(char** myArray, int rows, int columns, int mines) {
	int num = 0, i = 0, j = 0, num1 = 0, num2 = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			num = 0, num1 = 0, num2 = 0;
			if (myArray[i][j] != '*') {
				num1 = make_hidden_map3(myArray, rows, columns, num, i, j);
				num2 = make_hidden_map4(myArray, rows, columns, num1, i, j);
				char num_check = 48 + num2;
				myArray[i][j] = num_check;
			}
		}
	}

	new_board(myArray, rows, columns, mines);


}


/*********************************************************************************
* Function: make_hidden_mp3
* Description: extension of make_hidden_mp2 in order to meet line limit
* Parameters: char**, int, int, int, int, int
* Pre-Conditions: positive integers, in range of array
* Post-Conditions: num must be a positive integer
* Line Count: 13
*********************************************************************************/
int make_hidden_map3(char** myArray, int rows, int columns, int num, int i, int j) {
	if (i > 0) {
		if ((myArray[i - 1][j] == '*'))
			num++;
	}
	if (i < rows - 1) {
		if (myArray[i + 1][j] == '*')
			num++;
	}
	if (j < columns - 1) {
		if (myArray[i][j + 1] == '*')
			num++;
	}
	if (j > 0) {
		if (myArray[i][j - 1] == '*')
			num++;
	}
	return num;
}

/*********************************************************************************
* Function: make_hidden_mp4
* Description: extension of make_hidden_mp2 in order to meet line limit
* Parameters: char**, int, int, int, int, int
* Pre-Conditions: positive integers, in range of array
* Post-Conditions: num1 must be a positive integer
* Line Count: 13
*********************************************************************************/
int make_hidden_map4(char** myArray, int rows, int columns, int num1, int i, int j) {
	if ((j > 0) && (i>0)) {
		if (myArray[i - 1][j - 1] == '*')
			num1++;
	}
	if ((i < rows - 1) && (j < columns - 1)) {
		if (myArray[i + 1][j + 1] == '*')
			num1++;
	}
	if ((i < rows - 1) && (j>0)) {
		if (myArray[i + 1][j - 1] == '*')
			num1++;
	}
	if ((i > 0) && (j < columns - 1)) {
		if (myArray[i - 1][j + 1] == '*')
			num1++;
	}
	return num1;
}

/*********************************************************************************
* Function: new_board
* Description: creates an array that will be shown to the user
* Parameters: char**, int, int, int
* Pre-Conditions: must be positive integers within range of array
* Post-Conditions: none
* Line Count: 8
*********************************************************************************/
void new_board(char **myArray, int rows, int columns, int mines) {
	char **user_array = new char*[rows];
	for (int i = 0; i < rows; ++i) {
		user_array[i] = new char[columns];
	}
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			user_array[i][j] = ' ';
		}
	}
	print_board(myArray, user_array, rows, columns, mines);
	menu(myArray, user_array, rows, columns, mines);
}

/*********************************************************************************
* Function: print_board
* Description: prints out the array in the correct shape
* Parameters: char**, char**, int, int, int
* Pre-Conditions: integers must be in range of arrays, arrays are same size
* Post-Conditions: none
*********************************************************************************/
void print_board(char **myArray, char **user_array, int rows, int columns, int mines) {
	int rows_temp = 0;	
	cout << "   ";
	for (int i = 0; i < columns; i++) {
		cout << i + 1 << "  ";
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		cout << "  ";
		for (int k =0; k < (columns*3)+1; k++){
			cout << "-";
		}
		cout << endl;
		cout << rows_temp + 1;
		if (rows_temp < 9) {
			cout << " ";
		}
		for (int j = 0; j < columns; j++) {
			cout << "| " << user_array[i][j];
		}
		cout <<"|";
		rows_temp = rows_temp + 1;
		cout << endl;
	}
	cout << "  ";
	for (int k =0; k < (columns*3)+1; k++){
			cout << "-";
	}cout << endl;

}
/*********************************************************************************
* Function: menu
* Description: shows a menu to the user
* Parameters: char**, char**, int, int, int
* Pre-Conditions: arrays must be the same size, positive integers
* Post-Conditions: none
* Line Count: 18
*********************************************************************************/
void menu(char **myArray, char **user_array, int rows, int columns, int mines) {
	int choice = 0, x, y;
	string temp;
	cout << "1. Flag 2. Open" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << "Enter row and column to flag" << endl;
		cin >> temp; x = is_num(temp);
		cin >> temp; y = is_num(temp);
	}
	else {
		cout << "Enter row and column to open" << endl;
		cin >> temp; x = is_num(temp);
		cin >> temp; y = is_num(temp);
	}
	user_board(myArray, user_array, rows, columns, choice, x, y, mines);
}

/*********************************************************************************
* Function: user_board
* Description: edits the array shown to the user by comparing to hidden array
* Parameters: char**, char**, int, int, int, int, int, int
* Pre-Conditions: integers must be in range of arrays, arrays are same size
* Post-Conditions: none
* Line Count: 17
*********************************************************************************/
void user_board(char **myArray, char **user_array, int rows, int columns, int choice, int x, int y, int mines) {
	if ((x > columns) || (y > rows)) {
		cout << "That's not even on the board" << endl;
		print_board(myArray, user_array, rows, columns, mines);
		menu(myArray, user_array, rows, columns, mines);
	}
	if (choice == 1) {
		user_array[y - 1][x - 1] = 'F';
	}
	else {
		user_array[y-1][x - 1] = myArray[y-1][x - 1];
		if (user_array[y - 1][x - 1] == '*') {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					cout << "[" << myArray[i][j] << "]";
				}
				cout << endl;
			}
			cout << "YOU LOSE" << endl;
			gameover(myArray, user_array);
		}
	}

	winner_search(myArray, user_array, rows, columns, mines);
	print_board(myArray, user_array, rows, columns, mines);
	menu(myArray, user_array, rows, columns, mines);
}
/*********************************************************************************
* Function: gameover
* Description: deallocates memory and prompts for a restart
* Parameters: char**, char**
* Pre-Conditions: none
* Post-Conditions: none
* Line Count: 13
*********************************************************************************/
void gameover(char **myArray, char **user_array) {

	delete[] user_array;
	delete[] myArray;
	cin.ignore();
	cout << "Play Again? (1)yes, (2)no" << endl;
	int ans;
	cin >> ans;
	if (ans == 1) {
		cin.ignore();
		cin.clear();
		main2();
	}
	else {
		exit(1);
	}
}
/*********************************************************************************
* Function: main2
* Description: gets user input without command lines for next game
* Parameters: none
* Pre-Conditions: all 2d arrays should be deleted
* Post-Conditions: none
*********************************************************************************/
void main2() {
	string temp;
	cout << "How Many Rows?" << endl;
	cin >> temp;
	int rows = is_num(temp);

	cout << "How Many Columns?" << endl;
	cin >> temp;
	int cols = is_num(temp);

	cout << "How Many Mines?" << endl;
	cin >> temp;
	int mines = is_num(temp);
	print_data(rows, mines, cols);
}

/*********************************************************************************
* Function: winner_search
* Description: checks if the board has been cleared without tripping any mines
* Parameters: char**, char**, int, int, int
* Pre-Conditions: integers must be in range of arrays, arrays are same size
* Post-Conditions: none
* Line Count: 17
*********************************************************************************/
void winner_search(char **myArray, char **user_array, int rows, int columns, int mines) {
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (user_array[i][j] != ' ') {
				count++;
			}
		}
	}
	int flag = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (user_array[i][j] == 'F') {
				flag++;
			}
		}
	}
	if ((count == rows*columns) && (flag == mines)) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << "[" << myArray[i][j] << "]";
			}
			cout << endl;
		}
		cout << "YOU WON!!!" << endl;
		gameover(myArray, user_array);
	}
}


/*********************************************************************************
* Function: is_pos
* Description: tests for positive integers
* Parameters: int
* Pre-Conditions: none
* Post-Conditions: true or false
* Line Count: 4
*********************************************************************************/
bool is_pos(int input) {
	if (input > 0) {
		return true;
	}
	return false;
}





int is_num(string input){
	int num;
	bool bad_input = true;
	while (bad_input){
		for (int i = 0; i < input.length(); i++){
			if (isdigit(input[i])){
				bad_input = false;
				if(is_pos(atoi(input.c_str()))){
					num = atoi(input.c_str());
					return num;
				}
				}
			
			else
			{
				bad_input = true;
				cout << "that was bad input.  enter a good number" << endl;
				cin >> input;
				break;
			}
		}
	}
}

void get_args(int argc, char *argv[], int &rows,int &cols, int &mines){
	for (int i = 0; i<argc; ++i){
		string arg = argv[i];
		if (arg == "-r" || arg == "-rows"){
			rows = is_num(argv[i+1]);
		}
		if (arg == "-c" || arg == "-cols"){
			cols = is_num(argv[i+1]);
		}
		if (arg == "-m" || arg == "-mines"){
			mines = is_num(argv[i+1]);
		}
	}

}