/*********************************************************************
** Program Filename: minesweeper.cpp
** Author:Robert Hayden Anderson
** Date: 12/1/2016
** Description: game of minesweeper without recursion...yet
** Input: takes cla for rows/cols/mines
** Output:minesweeper
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdio>

using namespace std;

void make_board(int rows, int mines, int cols);
void set_mines(string **board, int rows, int cols, int mines);
void set_numbers(string **board, int rows, int cols, int mines);
int check_sides(string **board, int rows, int cols, int num, int i, int j);
int check_corners(string **board, int rows, int cols, int num1, int i, int j);
void new_board(string **board, int rows, int cols, int mines);
void print_board(string **board, string **user_array, int rows, int cols, int mines);
void pick_coords(string **board, string **user_array, int rows, int cols, int mines);
void user_board(string **board, string **user_array, int rows, int cols, int choice, int x, int y, int mines);
void play_again(string **board, string **user_array, int rows);
void main2() ;
void check_win(string **board, string **user_array, int rows, int cols, int mines);
int is_num(string input);
void get_args(int argc, char *argv[], int &rows,int &cols, int &mines);

/*********************************************************************
** Function:main
** Description:starts minesweeper
** Parameters:int, string **
** Pre-Conditions: 3 positive integers entered with command lines -c -m - r
** Post-Conditions:n/a
** Return: 0
*********************************************************************/ 
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int rows=10, cols=10, mines =10;
	get_args(argc, argv, rows, cols, mines);
	make_board(rows, mines, cols);
	return 0;	
}
/*********************************************************************
** Function:make_board
** Description:prints the ammount of rows, columns, and mines
** Parameters:int, int, int
** Pre-Conditions:n/a
** Post-Conditions:n/a
** Return:n/a
*********************************************************************/ 
void make_board(int rows, int mines, int cols) {
	if (mines >= (cols*rows)) {
		cout << "Too Many Mines!!!" << endl;
		exit(0);
	}
	cout << endl << rows << " rows" << endl;
	cout << cols << " columns" << endl;
	cout << mines << " mines\n" << endl;
	string **board = new string*[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new string[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = "0";
		}
	}
	set_mines(board, rows, cols, mines);
}
/*********************************************************************
** Function:set_mines
** Description:loops until all mines are randomly placed
** Parameters:string ** , int, int, int
** Pre-Conditions:n/a
** Post-Conditions:mines are set
** Return:n/a
*********************************************************************/ 
void set_mines(string **board, int rows, int cols, int mines) {
	int count  = 0;
	while(count != mines){
		int x = rand() % cols;
		int y = rand() % rows;
		if(board[y][x] != "*"){//make sure mine isnt already there
			board[y][x] = "*";
			count++;
		}	
	}
	set_numbers(board, rows, cols, mines);
}
/*********************************************************************
** Function:set_numbers
** Description: sets actual board with numbers relative to nearby mines
** Parameters: char **, int, int, int
** Pre-Conditions: n/a
** Post-Conditions: actual board has numbers set
** Return: n/a
*********************************************************************/ 
void set_numbers(string **board, int rows, int cols, int mines) {
	int num, num2;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			num = 0, num2 = 0;
			if (board[i][j] != "*") {
				num = check_sides(board, rows, cols, 0, i, j); //add sides to total
				num2 = check_corners(board, rows, cols, num, i, j); // add corners to total
				char num_check = 48 + num2; //add num to start of ascii nums
				board[i][j] = num_check;
			}
		}
	}
	new_board(board, rows, cols, mines);
}

/*********************************************************************
** Function: check_sides
** Description: checks up,down,left,right of cell for mines
** Parameters: string **, int, int, int, int, int
** Pre-Conditions: board is made already and mines set
** Post-Conditions: n/a
** Return: amount of mines
*********************************************************************/ 
int check_sides(string **board, int rows, int cols, int num, int y, int x) {
	if (y < rows - 1) {
		if (board[y + 1][x] == "*")//top
			num++;
	}
	if (y > 0) {
		if ((board[y - 1][x] == "*"))//bottom
			num++;
	}

	if (x > 0) {
		if (board[y][x - 1] == "*")//left
			num++;
	}
	if (x < cols - 1) {
		if (board[y][x + 1] == "*")//right
			num++;
	}
	return num;
}
/*********************************************************************
** Function: check_corners
** Description: checks corners of a cell for mines
** Parameters: string **, int, int, int, int, int
** Pre-Conditions: board is made already and mines set
** Post-Conditions: n/a
** Return: amount of mines
*********************************************************************/ 
int check_corners(string **board, int rows, int cols, int num, int i, int j) {
	if ((i < rows - 1) && (j>0)) {//dont check if on top or left edge of board
		if (board[i + 1][j - 1] == "*")//top left
			num++;
	}
	if ((j > 0) && (i>0)) {//dont check if on bottom or left edge of board
		if (board[i - 1][j - 1] == "*")//bottom left
			num++;
	}
	if ((i < rows - 1) && (j < cols - 1)) {//dont check if on top or right edge of board
		if (board[i + 1][j + 1] == "*")//top right
			num++;
	}
	
	if ((i > 0) && (j < cols - 1)) {//dont check if on bottom or right edge of board
		if (board[i - 1][j + 1] == "*")//bottom right
			num++;
	}
	return num;
}
/*********************************************************************
** Function: new_board
** Description: creates 2-d array for user and starts actual game
** Parameters: string **, int, int, int
** Pre-Conditions: n/a
** Post-Conditions: users board is made
** Return: n/a
*********************************************************************/ 
void new_board(string **board, int rows, int cols, int mines) {
	string **user_array = new string*[rows];
	for (int i = 0; i < rows; i++) {
		user_array[i] = new string[cols];
	}
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			user_array[i][j] = " ";
		}
	}
	print_board(board, user_array, rows, cols, mines);
	pick_coords(board, user_array, rows, cols, mines);
}
/*********************************************************************
** Function: print_board
** Description: prints out board
** Parameters: string **, string **, int, int, int
** Pre-Conditions: board is already made
** Post-Conditions: prints board to screen works best for boards less than 13 columns
** Return: n/a
*********************************************************************/ 
void print_board(string **board, string **user_array, int rows, int cols, int mines) {
	int rows_temp = 0;	
	cout << "   ";//start a little to the right
	for (int i = 0; i < cols; i++) {
		cout << i + 1 << "  ";//print numbers
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		cout << "  ";
		for (int k =0; k < (cols*3)+1; k++){
			cout << "-";//print top
		}
		cout << endl;
		cout << rows_temp + 1;//print column number
		if (rows_temp < 9) {
			cout << " ";//print space to the right to make up for 2 digit numbers
		}
		for (int j = 0; j < cols; j++) {
			cout << "| " << user_array[i][j]; // print divider
		}
		cout <<"|";//end divider
		rows_temp = rows_temp + 1;//next row
		cout << endl;
	}
	cout << "  ";
	for (int k =0; k < (cols*3)+1; k++){
			cout << "-"; // print bottom
	}cout << endl;

}
/*********************************************************************
** Function: pick_coords
** Description: shows a menu to the user
** Parameters: string **, string **, int, int, int
** Pre-Conditions: arrays must be the same size, positive integers
** Post-Conditions: n/a
** Return: n/a
*********************************************************************/ 
void pick_coords(string **board, string **user_array, int rows, int cols, int mines) {
	int choice = 0, x, y;
	string temp;
	cout << "1. Flag  2. Open" << endl;
	cin >> temp; choice = is_num(temp);
	if (choice == 1) {
		cout << "Enter row and column to flag" << endl;
		cin >> temp; y = is_num(temp)-1;
		cin >> temp; x = is_num(temp)-1;
	}
	else {
		cout << "Enter row and column to open. ie: 3 4 for row 3 column 4" << endl;
		cin >> temp; y = is_num(temp)-1;
		cin >> temp; x = is_num(temp)-1;
	}
	user_board(board, user_array, rows, cols, choice, x, y, mines);
}
/*********************************************************************
** Function: user_board
** Description: takes user input and checks for mine or places flag
** Parameters: string **, string **, int, int, int, int, int, int
** Pre-Conditions: both boards created, mines placed, users picked what they want to do
** Post-Conditions: flags a cell on users board or checks board for mine
** Return: n/a
*********************************************************************/ 
void user_board(string **board, string **user_array, int rows, int cols, int choice, int x, int y, int mines) {
	if ((x > cols) || (y > rows)) {
		cout << "That's not even on the board" << endl;
		print_board(board, user_array, rows, cols, mines);
		pick_coords(board, user_array, rows, cols, mines);
	}
	if (choice == 1) {
		user_array[y][x] = "F";
	}
	else {
		user_array[y][x] = board[y][x];
		if (user_array[y][x] == "*") {
			print_board(board, user_array, rows, cols, mines);
			cout << "YOU LOSE" << endl;
			play_again(board, user_array,rows);
		}
	}
	check_win(board, user_array, rows, cols, mines);
	print_board(board, user_array, rows, cols, mines);
	pick_coords(board, user_array, rows, cols, mines);
}
/*********************************************************************
** Function: play_again
** Description:  deletes arrays and prompts for restart
** Parameters: string **, string **, int
** Pre-Conditions: n/a
** Post-Conditions: ends or new game
** Return: n/a
*********************************************************************/ 
void play_again(string **board, string **user_array, int rows) {
	for (int i=0;i<rows;i++){
		delete [] user_array[i];
		delete [] board[i];
	}
	delete [] user_array;
	delete [] board;
	cin.ignore();
	cout << "Play Again? (1)yes, (2)no" << endl;
	int ans; string temp;
	cin >> temp;
	ans = is_num(temp);
	if (ans == 1) {
		cin.ignore();
		cin.clear();
		main2();
	}
	else {
		exit(0);
	}
}
/*********************************************************************
** Function: main2
** Description: gets new rows/cols/mines for new game
** Parameters: n/a
** Pre-Conditions: all previous game deleted
** Post-Conditions: new game w/ user input for rows/cols/mines
** Return: n/a
*********************************************************************/ 
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
	make_board(rows, mines, cols);
}
/*********************************************************************
** Function: check_win
** Description: checks if everything has been filled in and all flags are set
** Parameters: string **, string **, int, int, int
** Pre-Conditions: everything made and user has played at least once
** Post-Conditions: n/a
** Return: n/a
*********************************************************************/ 
void check_win(string **board, string **user_array, int rows, int cols, int mines) {
	int count = 0, flag = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (user_array[i][j] != " ") {
				count++;//counts everything filled in so far
			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (user_array[i][j] == "F") {
				flag++;//counts amount of flags placed
			}
		}
	}
	if ((count == rows*cols) && ((flag == mines) || (count == (rows*cols) - mines))) {
		print_board(board, user_array, rows, cols, mines);
		cout << "Winner winner chicken dinner!!!" << endl;
		play_again(board, user_array,rows);
	}
}
/*********************************************************************
** Function:is_pos
** Description: checks if int is greater than 0
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: n/a
** Return: bool
*********************************************************************/ 
bool is_pos(int input) {
	if (input > 0) {
		return true;
	}
	return false;
}
/*********************************************************************
 ** Function: is_num
 ** Description: forces an input to be an int
 ** Parameters: a string you need to be an int
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 ** Return: returns input as an int
 *********************************************************************/ 
int is_num(string input){
	int num;
	bool bad_input = true;
	while (bad_input){
		for (int i = 0; i < input.length(); i++){
			if (isdigit(input[i]) && is_pos(atoi(input.c_str()))){
				bad_input = false;
				num = atoi(input.c_str());
				return num;
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
/*********************************************************************
** Function: get_args
** Description: gets command line arguments
** Parameters: int,string **,int,int,int
** Pre-Conditions: user made command line arguments
** Post-Conditions: sets rows, mines and cols
** Return: n/a
*********************************************************************/ 
void get_args(int argc, char *argv[], int &rows,int &cols, int &mines){
	for (int i = 0; i<argc; i++){
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