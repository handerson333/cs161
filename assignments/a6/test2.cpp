#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

//FUNCTIONS
bool is_pos(int);
void print_data(int, int, int);
void place_mines2(char**, int, int, int);
int place_mines3(char**, int, int, int, int, int);
int place_mines4(char**, int, int, int, int, int);
void place_mines(char**, int, int, int);
void get_args(int argc, char *argv[], int &rows,int &cols, int &mines);
int is_num(string input);
void winner_search(char**, char**, int, int, int);
void menu(char**, char**, int, int, int);
void user_board(char**, char**, int, int, int, int, int, int);
void print_board(char**, char**, int, int, int);
void new_board(char**, int, int, int);
void play_again(char**, char**, int rows);
void main2();
void set_mines(char** board, int rows, int cols, int mines);
void set_numbers(char** board, int rows, int cols, int mines);


/*********************************************************************************
 * Function: main
 * Description: runs through functions
 * Parameters: int, char*
 * Pre-Conditions: 3 positive integers entered with command lines -c -m - r
 * Post-Conditions: none
 *********************************************************************************/
int main(int argc, char *argv[]) {
	system("clear");
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
 *********************************************************************************/
void print_data(int rows, int mines, int cols) {
	if (mines >= (cols*rows)) {
		cout << "Too Many Mines!!!" << endl;
		exit(0);
	}
	cout << endl << rows << " rows" << endl;
	cout << cols << " columns" << endl;
	cout << mines << " mines\n" << endl;
	char **board = new char*[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new char[cols];
	}
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = '0';
		}
	}
	//place_mines(board, rows, cols, mines);
	set_mines(board, rows, cols, mines);
	set_numbers(board, rows, cols, mines);
	new_board(board, rows, cols, mines);
}

void set_mines(char** board, int rows, int cols, int mines){
	int count  = 0;
	while(count != mines){
		int x = rand() % cols;
		int y = rand() % rows;
		if(board[y][x] != '*'){
			board[y][x] = '*';
			count++;
		}	
	}
}
void set_numbers(char** board, int rows, int cols, int mines){
	for(int cell = 0; cell < cols*rows; cell++){
		int num = 0;
		for(int y = 0; y < rows; y++){
			for (int x = 0; x < cols; x++){
				if(board[y][x] != '*'){
					if (y > 0) {
						if ((board[y - 1][x] == '*'))
							num++;
					}
					if (y < rows - 1) {
						if (board[y + 1][x] == '*')
							num++;
					}
					if (x < cols - 1) {
						if (board[y][x + 1] == '*')
							num++;
					}
					if (x > 0) {
						if (board[y][x - 1] == '*')
							num++;
					}
					if ((x > 0) && (y>0)) {
						if (board[y - 1][x - 1] == '*')
							num++;
					}
					if ((y < rows - 1) && (x < cols - 1)) {
						if (board[y + 1][x + 1] == '*')
							num++;
					}
					if ((y < rows - 1) && (x>0)) {
						if (board[y + 1][x - 1] == '*')
							num++;
					}
					if ((y > 0) && (x < cols - 1)) {
						if (board[y - 1][x + 1] == '*')
							num++;
					}
					board[y][x] = num;
				}
			}
		}
	}
}

/*********************************************************************************
 * Function: place_mines
 * Description: randomly places mines, loops if the same random number is used
 * Parameters: char** , int, int, int
 * Pre-Conditions: positive integers, must fit inside array
 * Post-Conditions: none
 *********************************************************************************/
/*void place_mines(char** board, int rows, int cols, int mines) {
  int count = 0;
  for (int i = 0; i < rows; i++) {
  for (int j = 0; j < cols; j++) {
  if (board[i][j] == '*') {
  count++;
  }
  }
  }
  if (count == mines) {
  place_mines2(board, rows, cols, mines);
  }
  board[rand() % rows][rand() % cols] = '*';
  place_mines(board, rows, cols, mines);
  }
  */
/*********************************************************************************
 * Function: place_mines2
 * Description: fills the array with numbers in relation to mines
 * Parameters: char **, int, int, int
 * Pre-Conditions: positive numbers, within range of array
 * Post-Conditions: none
 *********************************************************************************/
/*void place_mines2(char** board, int rows, int cols, int mines) {
  int num = 0, i = 0, j = 0, num2 = 0, num3 = 0;
  for (i = 0; i < rows; i++) {
  for (j = 0; j < cols; j++) {
  num = 0, num2 = 0, num3 = 0;
  if (board[i][j] != '*') {
  num2 = place_mines3(board, rows, cols, num, i, j);
  num3 = place_mines4(board, rows, cols, num2, i, j);
  char num_check = 48 + num3;
  board[i][j] = num_check;
  }
  }
  }
  new_board(board, rows, cols, mines);
  }

*/
/*********************************************************************************
 * Function: make_hidden_mp3
 * Description: extension of make_hidden_mp2 in order to meet line limit
 * Parameters: char**, int, int, int, int, int
 * Pre-Conditions: positive integers, in range of array
 * Post-Conditions: num must be a positive integer
 *********************************************************************************/
/*int place_mines3(char** board, int rows, int cols, int num, int i, int j) {
  if (i > 0) {
  if ((board[i - 1][j] == '*'))
  num++;
  }
  if (i < rows - 1) {
  if (board[i + 1][j] == '*')
  num++;
  }
  if (j < cols - 1) {
  if (board[i][j + 1] == '*')
  num++;
  }
  if (j > 0) {
  if (board[i][j - 1] == '*')
  num++;
  }
  return num;
  }
  */
/*********************************************************************************
 * Function: make_hidden_mp4
 * Description: extension of make_hidden_mp2 in order to meet line limit
 * Parameters: char**, int, int, int, int, int
 * Pre-Conditions: positive integers, in range of array
 * Post-Conditions: num1 must be a positive integer
 *********************************************************************************/
/*int place_mines4(char** board, int rows, int cols, int num, int i, int j) {
  if ((j > 0) && (i>0)) {
  if (board[i - 1][j - 1] == '*')
  num++;
  }
  if ((i < rows - 1) && (j < cols - 1)) {
  if (board[i + 1][j + 1] == '*')
  num++;
  }
  if ((i < rows - 1) && (j>0)) {
  if (board[i + 1][j - 1] == '*')
  num++;
  }
  if ((i > 0) && (j < cols - 1)) {
  if (board[i - 1][j + 1] == '*')
  num++;
  }
  return num;
  }
  */
/*********************************************************************************
 * Function: new_board
 * Description: creates an array that will be shown to the user
 * Parameters: char**, int, int, int
 * Pre-Conditions: must be positive integers within range of array
 * Post-Conditions: none
 *********************************************************************************/
void new_board(char **board, int rows, int cols, int mines) {
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
	print_board(board, user_array, rows, cols, mines);
	menu(board, user_array, rows, cols, mines);
}

/*********************************************************************************
 * Function: print_board
 * Description: prints out the array in the correct shape
 * Parameters: char**, char**, int, int, int
 * Pre-Conditions: integers must be in range of arrays, arrays are same size
 * Post-Conditions: none
 *********************************************************************************/
void print_board(char **board, char **user_array, int rows, int cols, int mines) {
	int rows_temp = 0;	
	cout << "   ";
	for (int i = 0; i < cols; i++) {
		cout << i + 1 << "  ";
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		cout << "  ";
		for (int k =0; k < (cols*3)+1; k++){
			cout << "-";
		}
		cout << endl;
		cout << rows_temp + 1;
		if (rows_temp < 9) {
			cout << " ";
		}
		for (int j = 0; j < cols; j++) {
			cout << "| " << user_array[i][j];
		}
		cout <<"|";
		rows_temp = rows_temp + 1;
		cout << endl;
	}
	cout << "  ";
	for (int k =0; k < (cols*3)+1; k++){
		cout << "-";
	}cout << endl;
}
/*********************************************************************************
 * Function: menu
 * Description: shows a menu to the user
 * Parameters: char**, char**, int, int, int
 * Pre-Conditions: arrays must be the same size, positive integers
 * Post-Conditions: none
 *********************************************************************************/
void menu(char **board, char **user_array, int rows, int cols, int mines) {
	int choice = 0, x, y;
	string temp;
	cout << "1. Flag  2. Open" << endl;
	cin >> temp; choice = is_num(temp);
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
	system("clear");
	user_board(board, user_array, rows, cols, choice, x, y, mines);
}
/*********************************************************************************
 * Function: user_board
 * Description: edits the array shown to the user by comparing to hidden array
 * Parameters: char**, char**, int, int, int, int, int, int
 * Pre-Conditions: integers must be in range of arrays, arrays are same size
 * Post-Conditions: none
 *********************************************************************************/
void user_board(char **board, char **user_array, int rows, int cols, int choice, int x, int y, int mines) {
	if ((x > cols) || (y > rows)) {
		cout << "That's not even on the board" << endl;
		print_board(board, user_array, rows, cols, mines);
		menu(board, user_array, rows, cols, mines);
	}
	if (choice == 1) {
		user_array[y - 1][x - 1] = 'F';
	}
	else {
		user_array[y-1][x - 1] = board[y-1][x - 1];
		if (user_array[y - 1][x - 1] == '*') {
			print_board(board, user_array, rows, cols, mines);
			cout << "YOU LOSE" << endl;
			play_again(board, user_array, rows);
		}
	}
	winner_search(board, user_array, rows, cols, mines);
	print_board(board, user_array, rows, cols, mines);
	menu(board, user_array, rows, cols, mines);
}
/*********************************************************************************
 * Function: play_again
 * Description: deallocates memory and prompts for a restart
 * Parameters: char**, char**
 * Pre-Conditions: none
 * Post-Conditions: none
 *********************************************************************************/
void play_again(char **board, char **user_array, int rows) {
	for(int i = 0 ; i < 10;i++){
		delete [] board[i]; 
		delete [] user_array[i];
	}
	delete [] user_array;
	delete [] board;
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
 *********************************************************************************/
void winner_search(char **board, char **user_array, int rows, int cols, int mines) {
	int count = 0, flag = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (user_array[i][j] != ' ') {
				count++;//counts everything filled in so far
			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (user_array[i][j] == 'F') {
				flag++;
			}
		}
	}
	if ((count == rows*cols) && ((flag == mines) || (count == (rows*cols) - mines))) {
		print_board(board, user_array, rows, cols, mines);
		cout << "Winner winner chicken dinner!!!" << endl;
		play_again(board, user_array,rows);
	}
}

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
/*********************************************************************************
 * Function: is_pos
 * Description: tests for positive integers
 * Parameters: int
 * Pre-Conditions: none
 * Post-Conditions: true or false
 *********************************************************************************/
bool is_pos(int input) {
	if (input > 0) {
		return true;
	}
	return false;
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
