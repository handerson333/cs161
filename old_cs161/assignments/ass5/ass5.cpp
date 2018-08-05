/*********************************************************************
 * ** Program Filename: ass5
 * ** Author: Hayden Anderson
 * ** Date: 5/18/15
 * ** Description: 3 programs; a matrix, a string counter, and a string reverse
 * ** Input: menu options, either a sentence or more menu options
 * ** Output: a reversed string, a matrix and its smaller amtrix, or a count of words and letters of a sentence
 * *********************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <cstdio>
#include <string>
using namespace std;
//prototypes
void program1();
void program2();
void program3();
string reverse(string sentence);
int menu();
void count_word(char word_string[], char* token, const char delimiters[]);  
void count_letters(char letter_string[]);
void make_array(int **array, int i, int j, int col, int row);
void print_array(int **array, int i, int j, int col, int row);
void sum_array_it(int **array, int i, int j, int col, int row);
void sum_array_re(int **array, int i, int j, int col, int row);
void sum_if(int **array, int i, int j, int col, int row, int method);


/*********************************************************************
 * ** Function: main
 * ** Description: calls a menu to see what program the user wants
 * ** Parameters: none
 * ** Pre-Conditions: the user starts the program
 * ** Post-Conditions: prints which program the user picks
 * *********************************************************************/ 
int main(){
	int answer;
	answer = menu();
	if (answer == 1)
		program1();
	else if (answer == 2)
		program2();
	else if (answer == 3)
		program3();
	else
		cout<< "invalid input"<< endl;

}




// functions




/*********************************************************************
 * ** Function: Menu
 * ** Description: chooses what program you want
 * ** Parameters: none
 * ** Pre-Conditions: user enters a number
 * ** Post-Conditions: sends that number back to main
 * *********************************************************************/ 
int menu(){
	cout << "please pick one" << endl;
	cout << "matrix (1)"<<endl;
	cout << "get word/letter count (enter 2 and then your sentence)" << endl;	
	cout << "reverse a sentence (enter 3 and then your sentence) " << endl;
	int input;
	cin >> input;
	cout << endl;
	return input;

}
/*********************************************************************
 * ** Function: program 1
 * ** Description: makes an NxN array and turns it into N-1 x N-1
 * ** Parameters: none
 * ** Pre-Conditions: user picks it in the menu
 * ** Post-Conditions: it will make a matrix NxN (n = user input) and prints the matrix and the same matrix added together to produce an n-1 x n-1 matrix
 * *********************************************************************/ 
void program1(){


	int row, col, i=0, j=0, method;

	cout<<"enter size of array"<<endl;

	cin>>row;
	col=row;

	cout<<endl;

	cout<<"1=iterative 2=recursive"<<endl;

	cin>>method;

	cout<<endl;
	//makes a pointer that hold the address for the array

	int **array = new int*[row];
	for(i=0; i<row; i++)
		array[i]=new int[col];


	make_array(array, i, j, col, row);
	print_array(array, i, j, col, row);
	sum_if(array, i, j, col, row, method);





}


/*********************************************************************
 * ** Function: make array
 * ** Description: makes a 2-d array with random characters
 * ** Parameters: pointer array, counters i and j, and the columns and rows
 * ** Pre-Conditions: user enters the size of the desired matrix
 * ** Post-Conditions: returns a 2-d N x N array
 * *********************************************************************/ 

void make_array(int **array, int i, int j, int col, int row){
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			array[i][j]=(rand()%10);
}

/*********************************************************************
 * ** Function: print array
 * ** Description: prints the array
 * ** Parameters: the array, the counters, the collumns and rows
 * ** Pre-Conditions:a previously created 2-d array is made
 * ** Post-Conditions: prints out the previously created 2-d array
 * *********************************************************************/ 

void print_array(int **array, int i, int j, int col, int row){
	for(i=0; i<row; i++){
		for(j=0; j<col; j++)
			cout<<array[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;

}
/*********************************************************************
 * ** Function: sums the array and makes it n-1 x n-1 iteratively
 * ** Description: takes a previouslt created 2-d array and adds groups of 4 together to make it an n-1 x n-1 array 
 * ** Parameters: the array, the counters, the collumns and rows
 * ** Pre-Conditions: a 2-d array is created and passed to this function 
 * ** Post-Conditions:creates a new 2-d array that is 1 digit smaller than the previously created array by adding closest groups of 4 iteratively 
 * *********************************************************************/ 
void sum_array_it(int **array, int i, int j, int col, int row){
	for(i=0; i<row-1; i++){
		for(j=0; j<col-1; j++)
			array[i][j]=((array[i][j]+array[i+1][j])+(array[i][j+1]+array[i+1][j+1]));

	}

	print_array(array, i, j, (col-1), (row-1));
}
/*********************************************************************
 * ** Function: sums the array and makes it n-1 x n-1 recursively
 * ** Description:  takes a previouslt created 2-d array and adds groups of 4 together to make it an n-1 x n-1 array 
 * ** Parameters:the array, the counters, the collumns and rows
 * ** Pre-Conditions:  a 2-d array is created and passed to this function 
 * ** Post-Conditions: creates a new 2-d array that is 1 digit smaller than the previously created array by adding closest groups of 4 recursively 
 * *********************************************************************/ 

void sum_array_re(int **array, int i, int j, int col, int row){


	if ((j==0)&&(i==(row-1))){
		return;
	}

	// sums up 4x4 array inside the array

	else {
		array[i][j]=((array[i][j]+array[i+1][j])+(array[i][j+1]+array[i+1][j+1]));
		cout<<array[i][j]<<" ";



		if (j==col-2){
			j=0;
			i++;
			cout<<endl;
		}
		else if (j==0){
			j++;
		}
		else
			j++;
	}
	sum_array_re(array, i, j, col, row);

}


/*********************************************************************
 * ** Function: sum if
 * ** Description: calls the sum functions depending on which method user wants
 * ** Parameters: previously created 2-d array, counters i and j length of collumns and rows, and which method
 * ** Pre-Conditions: array is made and a mthod is chosen
 * ** Post-Conditions: chooses which function to use depending on user inpoutted method
 * *********************************************************************/ 


void sum_if(int **array, int i, int j, int col, int row, int method){


	if (method==1)
		sum_array_it(array, i, j, col, row);
	else if (method==2)
		sum_array_re(array, 0, 0, col, row);
	else
		cout<<"not a valid input"<<endl;

}

/*********************************************************************
 * ** Function: Program 2
 * ** Description: takes a user inputted sentence and prints out the amount of words and letters used
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: computes amount of words and letters used
 * *********************************************************************/ 

void program2(){
	char string[101];
	char word_string[101];
	char letter_string[101];
	char *token;
	const char delimiters[ ]= " .,-:;!?";


	//	cout << "enter a string of letters that is less then 100 characters " << endl;
	cin.getline(string,101);


	strcpy(word_string, string);
	strcpy(letter_string, string);


	count_word(word_string, token, delimiters);
	count_letters(letter_string);

}
/*********************************************************************
 * ** Function: count word
 * ** Description: counts the number of words in a character array
 * ** Parameters: a character array, a pointer to a variable in original program, constant of delimiters.
 * ** Pre-Conditions: user has inputted a sentence
 * ** Post-Conditions: prints out the amount of words in sentnence
 * *********************************************************************/ 

void count_word(char word_string[], char* token, const char delimiters[]){
	int x=1;
	token= strtok (word_string, delimiters);
	while (token != '\0') {
		x++;
		token= strtok (NULL, delimiters);
	}
	cout<<"you have "<<x-1<<" words"<<endl;
}
/*********************************************************************
 * ** Function: count letters
 * ** Description: counts the different letters by checking upon itself 
 * ** Parameters: a character array
 * ** Pre-Conditions: user has input a sentence
 * ** Post-Conditions: prints out amount of specific letters used
 * *********************************************************************/ 
void count_letters(char letter_string[]){
	int n, i, j, x=1;
	n = strlen(letter_string);
	char temp, hold;
	// turns all letters into lower case and place them in alpha order

	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++){
			int  s = tolower(letter_string[i]) - tolower(letter_string[j]);
			if ( s == 0 )
				s = letter_string[i] - letter_string[j];

			if (s > 0){
				// changes values in the string so that the string is in order from a-z
				temp = letter_string[i];
				letter_string[i] = letter_string[j];
				letter_string[j] = temp;
			}
		}
	}
	hold=letter_string[0];

	// counts the number of times a letter is used in the loop and prints out total with the coresponding leter

	for(j=0; j<(strlen(letter_string)); j++){
		if (letter_string[j]==' '){
			hold=letter_string[j+1];
		}
		else if ((letter_string[j]!=hold)&&(letter_string[j+1]!=hold)){
			cout<<letter_string[j]<<" "<<x<<endl;
			hold=letter_string[j];
		}

		else if ((letter_string[j]!=hold)&&(letter_string[j+1]==hold)){
			x++;
			hold=letter_string[j];
		}
		else if ((letter_string[j]==hold)&&(letter_string[j+1]!=hold)){
			cout<<letter_string[j]<<" "<<x<<endl;
			x=1;
			hold=letter_string[j+1];
		}
		else if ((letter_string[j]==hold)&&(letter_string[j+1]==hold)){
			x++;
			hold=letter_string[j+1];
		}


	}
}
/*********************************************************************
 * ** Function: program 3
 * ** Description: program to reverse an inputted sentence
 * ** Parameters: none
 * ** Pre-Conditions: user enters a 3 at the menu
 * ** Post-Conditions: returns the original sentence and the same sentence reversed
 * *********************************************************************/ 
void program3(){
	//	const int SIZE = 101;
	//	char sentence[SIZE];
	string sentence;
	string reversed_sentence;
	//	cout << "Write a sentence" << endl;
	getline(cin, sentence);
	reversed_sentence = sentence;
	cout << "string = " << sentence << endl;
	cout << "reverse string = " << reverse ( reversed_sentence) << endl;

}
/*********************************************************************
 * ** Function: reverse
 * ** Description: reverses an inputed line
 * ** Parameters: a string
 * ** Pre-Conditions: The user inputs for program 3 and enters a sentence.
 * ** Post-Conditions: reverses the inputed sentence
 * *********************************************************************/ 
string reverse(string sentence)
{
	if (sentence.length() == 1){
		return sentence;
	}
	else{
		return reverse(sentence.substr(1,sentence.length())) + sentence.at(0);
	}
}

