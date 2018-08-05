
/*********************************************************************
 * ** Program Filename: gol
 * ** Author: Robert Hayden Anderson
 * ** Date: 5/20/15
 * ** Description: runs a game of life program with user inputs
 * ** Input: multiple inputs possible
 * ** Output: game of life program
 * *********************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

bool is_integer(const char* temp);
int main_menu();
int simple_test_menu();
int get_rows();
int get_collumns();
int place_shape_whereX();
int place_shape_whereY();
void decoration (int i);
void do_the_program(int collumns, int rows, int start_x, int start_y, int shape, int which_oscillator);
void life(int **array, char choice, int rows, int collumns);
void copy(int **array1, int **array2, int rows, int collumns);
void print(int **array, int rows, int collumns);
bool compare(int **array1, int **array2);
void is100(int i, char should_continue);
void is10(int i, char should_continue);
int which_oscillator();
void glider(int **array,int start_x,int start_y);




/*********************************************************************
 * ** Function: main
 * ** Description: runs the game of life program
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 


int main()
{
	int rows = 40;
	int collumns = 60;
	int temp;
	int oscillator;
	int start_x = 10;
	int start_y = 10;
	int shape;
	switch (main_menu())
	{	case 0:
		temp = simple_test_menu();
		if (temp == 2)
		{
			shape = 2;
			oscillator =  which_oscillator();
			do_the_program( collumns, rows, start_x, start_y, shape, oscillator);

		}
		else
			do_the_program( collumns, rows, start_x, start_y, shape, oscillator);
		{
		}
		break;
		case 1:
		shape = simple_test_menu();
		oscillator = which_oscillator();
		start_x = place_shape_whereX();
		start_y = place_shape_whereY();
		do_the_program( collumns, rows, start_x, start_y, shape, oscillator);

		break;
		default:
		break;


	}
}


/*********************************************************************
 * ** Function: print 
 * ** Description: prints a 2D array
 * ** Parameters: 2D array and row/collumn lengths
 * ** Pre-Conditions: array has been made and known size of x and y
 * ** Post-Conditions: prints the array
 * *********************************************************************/ 


void print (int **array, int rows, int collumns)
{
	for(int j = 10; j < rows ; j++)
	{
		for(int i = 10; i < collumns; i++)
		{
			if(array[j][i] == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

/*********************************************************************
 * ** Function: glider
 * ** Description: creates a 'glider' in an array at specified start points
 * ** Parameters: 2D array, and 2 start points
 * ** Pre-Conditions: 2d array has been amde and there is a start coordinate made
 * ** Post-Conditions: makes a glider in an 2D array
 * *********************************************************************/ 



void glider(int **array, int start_x, int start_y)
{
	array[start_x][start_y+1] = '*';
	array[start_x+3][start_y] = '*';
	array[start_x+3][start_y+1] = '*';
	array[start_x+3][start_y+1] = '*';
	array[start_x+2][start_y+3] = '*';

}

/*********************************************************************
 * ** Function: main menu
 * ** Description: is an input menu
 * ** Parameters: none 
 * ** Pre-Conditions: none
 * ** Post-Conditions: returns what kind of test user wants to run
 * *********************************************************************/ 

int main_menu()
{
	int returner;
	string input;
	cout << "would you like to do a simple test or a custom test?" << endl;
	cout << "(0) simple test" << endl;
	cout << "(1) custom test" << endl;
	cin >> input;
	while (is_integer(input.c_str()) == false)
	{
		cout << "enter a valid number" << endl;
		cin >> input;

	}
	returner = atoi(input.c_str());
	while (is_integer(input.c_str()) == false || returner > 1)
	{
		cout << "enter a valid number" << endl;
		cin >> input;
		returner = atoi(input.c_str());

	}
	return returner;
}


/*********************************************************************
 * ** Function: get rows
 * ** Description: asks height of array
 * ** Parameters: none 
 * ** Pre-Conditions: none
 * ** Post-Conditions: returns size of an array portion
 * *********************************************************************/ 

int get_rows()
{
	cout<< "how many rows?" << endl;
	int returner;
	string input;
	cin >> input;
	while (is_integer(input.c_str()) == false)
	{
		cout << "enter a valid number" << endl;
		cin >> input;

	}
	returner = atoi(input.c_str());
	return returner;

}

/*********************************************************************
 * ** Function: get collumns
 * ** Description: asks width of array
 * ** Parameters: none 
 * ** Pre-Conditions: none
 * ** Post-Conditions: returns size of an array portion
 * *********************************************************************/ 

int get_collumns()
{
	int returner;
	string input;
	cout << "how many collumns?" << endl;
	cin >> input;
	while (is_integer(input.c_str()) == false)
	{
		cout << "enter a valid number" << endl;
		cin >> input;

	}
	returner = atoi(input.c_str());
	return returner;

}


/*********************************************************************
 * ** Function: place shape where x
 * ** Description: asks where on x axis user wants to place a shape
 * ** Parameters: none
 * ** Pre-Conditions: a 2D array has been made
 * ** Post-Conditions: returns where user wants to put something
 * *********************************************************************/ 


int place_shape_whereX()
{
	int returner;
	string input;
	cout << "Where would you like to place the shape on the x axis? (shape starts in upper left of shape)" << endl;
	cin >> input;
	while (is_integer(input.c_str()) == false)
	{
		cout << "enter a valid number" << endl;
		cin >> input;

	}
	returner = atoi(input.c_str());
	return returner;

}


/*********************************************************************
 * ** Function: place shape where y
 * ** Description: asks where on y axis user wants to place a shape
 * ** Parameters: none
 * ** Pre-Conditions: a 2D array has been made
 * ** Post-Conditions: returns where user wants to put something
 * *********************************************************************/ 


int place_shape_whereY()
{
	int returner;
	string input;
	cout << "Where would you like to place the shape on the y axis? (shape starts in upper left of shape)" << endl;
	cin >> input;
	while (is_integer(input.c_str()) == false)
	{
		cout << "enter a valid number" << endl;
		cin >> input;

	}

	returner = atoi(input.c_str());
	return returner;

}

/*********************************************************************
 * ** Function: simple test menu
 * ** Description: a menu for what shape user wants to use
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: returns what shape user wants to use
 * *********************************************************************/ 


int simple_test_menu()
{
	int returner;
	string input;
	cout << "what would you like to do?" << endl;
	cout << "(0) simple glider" << endl;
	cout << "(1) glider gun" << endl;
	cout << "(2) Oscillators" << endl;
	cin >> input;
	while (is_integer(input.c_str()) == false)
	{
		cout << "enter a valid number" << endl;
		cin >> input;

	}
	returner = atoi(input.c_str());
	while (is_integer(input.c_str()) == false || returner > 2)
	{
		cout << "enter a valid number" << endl;
		cin >> input;
		returner = atoi(input.c_str());

	}
	return returner;
}

/*********************************************************************
 * ** Function: whioch oscillator
 * ** Description: asks which osillator user wants to use
 * ** Parameters: none
 * ** Pre-Conditions: non
 * ** Post-Conditions: returns which oscillator user wants
 * *********************************************************************/ 


int which_oscillator()
{
	int returner;
	string input;
	cout << "Which Oscillator would you like to use?" << endl;
	cout << "(0) blinker" << endl;
	cout << "(1) toad" << endl;
	cout << "(2) beacon"  << endl;
	cout << "(3) pulsar" << endl;
	cin >> input;
	while (is_integer(input.c_str()) == false)
	{
		cout << "enter a valid number" << endl;
		cin >> input;

	}
	returner = atoi(input.c_str());
	while (is_integer(input.c_str()) == false || returner > 3)
	{
		cout << "enter a valid number" << endl;
		cin >> input;
		returner = atoi(input.c_str());

	}
	return returner;

}


/*********************************************************************
 * ** Function: fill array
 * ** Description: fills an array with blank spots
 * ** Parameters: an array, and height and width
 * ** Pre-Conditions: a 2D array has been made and a height and width has been previous initialized
 * ** Post-Conditions: fills an array with blank spaces
 * *********************************************************************/ 


void fill_array(int **array, int collumns, int rows)
{
	for (int i = 0; i < collumns; i++)
	{	
		for (int j = 0; j < rows; j++)
		{
			array[i][j] = ' ';

		}


	}

}



/*********************************************************************
 * ** Function: do the program
 * ** Description: does the major portion of the program 
 * ** Parameters: all the menu inputs
 * ** Pre-Conditions: menu has been made and all user input has been made
 * ** Post-Conditions: does a simulation of an array changing like conways game of life
 * *********************************************************************/ 

void do_the_program(int collumns, int rows,int start_x, int start_y, int shape, int which_oscillator )
{
	char again;
	char cont;
	bool comparison;
	char neighborhood;
	int **array;
	array = new int* [collumns];
	for (int i = 0; i < collumns; i++)
		array[i] = new int [rows];
	fill_array(array, collumns, rows);

	int **backup;

	backup = new int* [collumns];
	for (int i = 0; i < collumns; i++)
		backup[i] = new int [rows];


	switch (shape)
	{
		case 0:
			break;

		case 1:

			break;

		case 2:

			break;
		default:
			break;
	}	

	glider(array, start_x, start_y);


	do
	{
		//Clears the screen so the program can start fresh.
		system("clear");
		int i = 0;
		//Loop that does the bulk of the simulation.
		do
		{
			decoration(i);
			print(array, rows, collumns);
			

			copy(array, backup, rows, collumns);
			life(array, neighborhood, rows , collumns);
			i++;
			system("sleep 1");
			is10(i, cont);
			is100(i, cont);
			break;
			comparison = compare(array, backup);
		}while(comparison == false);
		//Loop to check for proper inputs.
		do
		{
			cout << "Would you like to run another simulation? (y/n): ";
			cin >> again;

		}while(again != 'y' && again != 'n');
	}while(again == 'y');

}



/*********************************************************************
 * ** Function: copy
 * ** Description: copies one array to another
 * ** Parameters: 2 arrays
 * ** Pre-Conditions: 2 previously made 2-D arrays
 * ** Post-Conditions: arrays 2 is same as array 1 now
 * *********************************************************************/ 

void copy(int **array1, int **array2, int rows, int collumns)
{
	for(int j = 0; j < collumns; j++)
	{
		for(int i = 0; i < rows; i++)
			array2[j][i] = array1[j][i];
	}
}





/*********************************************************************
 * ** Function: decoration
 * ** Description: makes decoration of what generation it is
 * ** Parameters: counter i 
 * ** Pre-Conditions: in a loop with a counter 
 * ** Post-Conditions: prints a generation counter
 * *********************************************************************/ 


void decoration (int i)
{
	string decoration;
	if (i < 10)
		decoration = "-------------";
	else if(i >= 10 && i < 100)
		decoration = "--------------";
	else if(i >= 100 && i < 1000)
		decoration = "---------------";
	else if(i >= 1000 && i < 10000)
		decoration = "----------------";
	else
		decoration = "-----------------";
	cout << decoration << endl << "Generation " << i
		<< ":" << endl << decoration << endl << endl;
}


/*********************************************************************
 * ** Function: is integer
 * ** Description: checks to make sure input is an integer
 * ** Parameters: temp
 * ** Pre-Conditions: an input that requires a number input
 * ** Post-Conditions: answers whether the input is infact an integer
 * *********************************************************************/ 


bool is_integer(const char* temp)
{
	int length = strlen(temp);
	if(length == 0)
		return false;
	for (int i = 0; i < length; i++)
	{
		if(temp[i] > '9' || temp[i] < '0')
		{
			return false;
		}


	}
	return true;
}


/*********************************************************************
 * ** Function: compare
 * ** Description: compares 1 array to another
 * ** Parameters: 2 arrays
 * ** Pre-Conditions: 2 previously 2d arrays made
 * ** Post-Conditions: checks to see if they are the same
 * *********************************************************************/ 



bool compare(int** array1, int** array2)
{
	int count = 0;
	for(int j = 0; j < 22; j++)
	{
		for(int i = 0; i < 42; i++)
		{
			if(array1[j][i]==array2[j][i])
				count++;
		}
	}
	//Since the count gets incremented every time the cells are exactly the same,
	//an easy way to check if the two arrays are equal is to compare the count to
	//the dimensions of the array multiplied together.
	if(count == 22*42)
		return true;
	else
		return false;
}


/*********************************************************************
 * ** Function: is10
 * ** Description: checks to see if generation has ruyn 10 times but not 100
 * ** Parameters: counter, pass by reference value
 * ** Pre-Conditions: a simulation has been made witha  counter
 * ** Post-Conditions: just pauses the simulation till user hits 'enter'
 * *********************************************************************/ 


void is10(int i, char should_continue)
{
	if(i % 10 == 1 && i != 1 && i % 100 != 1)
	{
		cout << endl;
		//Loop to check for proper inputs.
		cout << "Hit enter to continue";
		cin.get();
	}		
}


/*********************************************************************
 * ** Function: is100
 * ** Description: checks to see if generation is at 100 runs
 * ** Parameters: a counter, and a pass by reference value
 * ** Pre-Conditions: a simulation using a counter has been made
 * ** Post-Conditions: asks user if they want to contuinue after 100 times running
 * *********************************************************************/ 


void is100(int i, char should_continue)
{
	if(i % 100 == 1 && i != 1)
	{
		cout << endl;
		//Loop to check for proper inputs.
		do
		{
			cout << "Would you like to continue this simulation? (y/n): ";
			cin >> should_continue;
		}while(should_continue != 'y' && should_continue != 'n');
		if(should_continue == 'n');
	}

}


/*********************************************************************
 * ** Function: Life
 * ** Description: Checfks neighborhood
 * ** Parameters: array and choice
 * ** Pre-Conditions: array has previously been made
 * ** Post-Conditions:	checks around the array slot if they are 'alive'
 * *********************************************************************/ 


void life(int **array, char choice, int rows, int collumns)
{
	//Copies the main array to a temp array so changes can be entered into a grid
	//without effecting the other cells and the calculations being performed on them.
	int **temp;
	copy(array, temp, rows, collumns);
	for(int j = 1; j < 21; j++)
	{
		for(int i = 1; i < 41; i++)
		{
			//checks all 8 cells surrounding the current cell in the array.
			int count = 0;
			count = array[j-1][i] +
				array[j-1][i-1] +
				array[j][i-1] +
				array[j+1][i-1] +
				array[j+1][i] +
				array[j+1][i+1] +
				array[j][i+1] +
				array[j-1][i+1];
			//cell dies
			if(count < 2 || count > 3)
				temp[j][i] = 0;
			//cell stays the same
			if(count == 2)
				temp[j][i] = array[j][i];
			//cell either stays alive, or is created
			if(count == 3)
				temp[j][i] = 1;
		}
	}
	//Copies the completed temp array back to the main array.
	copy(temp, array, rows, collumns);
}

