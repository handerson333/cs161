#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <cstring>

//prototypes

using namespace std;
bool is_integer_one_to_three(const char* temp);
void print_clean(int array[22][42]);
void print(int array[22][42]);
void copy(int array1[22][42], int array2[22][42]);
void life(int array[22][42], char choice);
bool compare(int array1[22][42], int array2[22][42]);
void print(int array[22][42]);
void decoration (int i);
void user_next();
void is100(int i, char should_continue);
bool do_compare(int todo[22][42], int backup[22][42]);
int what_shape();
bool is_integer(const char* temp);
int place_where();
void place_shape(int shape, int x, int y,int array[22][42]);

//main

int main()
{
	//variable declarations

	int beginning_generation[22][42];
	int todo[22][42];
	int backup[22][42];
	char neighborhood;
	char again;
	char cont;
	bool comparison;
	
	what_shape();
	place_where();

	//Loop to check if user wants to keep simulating.
	do
	{	
		//Clears the screen so the program can start fresh.
		system("clear");
		int i = 0;
		//Loop that does the bulk of the simulation.
		do
		{
			decoration(i);
			//Initializes the arrays by copying the beginning array to the todo array.
			if(i == 0)
			{
				copy(beginning_generation, todo);  
			}
			copy(todo, backup);			
			if (i ==0)
			{
				print_clean(todo);

			}	
			else
			{
				print(todo);		
			}
			life(todo, neighborhood);
			i++;
			user_next();
			is100(i, cont);
			break;
			comparison = do_compare(todo, backup);
		}while(comparison == false); 
		//Loop to check for proper inputs.
		do
		{
			cout << "Would you like to run another simulation? (y/n): ";
			cin >> again;

		}while(again != 'y' && again != 'n');
	}while(again == 'y');
}



//Functions
void place_shape(int shape, int x, int y, int array[22][42])
{
	switch (shape)
	{
		case 1:
	
		break;
		case 2:

		break;
		case3:

		break;
		default:
		break;
	};
}

int place_where()
{
cout << "enter the coordinates of where you want the shape to start on the 20 x 40 grid " << endl;
int x;
int y;
cout << "x value: ";
cin >> x;
cout << "Y: value: ";
cin >> y;
	
	
	
}

int what_shape()
{
	int returner;
	string input;
	cout << "what shape would you like to use? " << endl;
	cout << "(1) Oscillator " << endl;
	cout << "(2) Glider " << endl;
	cout << "(3) Glider Gun " << endl;
	cin >> input;
		while (is_integer_one_to_three(input.c_str()) == false)
	{
		cout << "enter a valid number!" << endl;
		cin >> input;
	}
	returner = atoi(input.c_str());

	return returner;
}
bool is_integer(const char* temp)
{
	int len = strlen(temp);
	if(len == 0)
		return false;
	for (int i = 0; i < len; i++)
	{
		if(temp[i] > '9' || temp[i] < '1')
		{
			return false;

		}

	}

return true;
}
bool is_integer_one_to_three(const char* temp)
{
	int len = strlen(temp);
	if(len == 0)
		return false;
	for (int i = 0; i < len; i++)
	{
		if(temp[i] > '9' || temp[i] < '1')
		{
			return false;

		}

	}

return true;
}





bool do_compare(int todo[22][42], int backup[22][42])
{
	bool comparison;		
	w
	comparison = compare(todo, backup);
	if(comparison == false)
		system("clear");
	if(comparison == true)
		cout << endl;

	return comparison;
}


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
void user_next()
{
	string input;
	cout << "Hit enter to go to the next generation: ";
	getline(cin,input);



}
void decoration(int i)
{
	string decoration;
	//Determines how big the decoration should be.
	if(i < 10)
		decoration = "-------------";
	else if(i >= 10 && i < 100)
		decoration = "--------------";
	else if(i >= 100 && i < 1000)
		decoration = "---------------";
	else if(i >= 1000 && i < 10000)
		decoration = "----------------";
	else
		decoration = "-----------------";
	//Prints the generation.  If i == 0, the beginning generation array is copied to the 
	//todo array, and is printed before any functions act upon it.
	cout << decoration << endl << "Generation " << i 
		<< ":" << endl << decoration << endl << endl;
}



//Checks to see if two arrays are exactly the same. 
//This is used to end the simulation early, if it 
//becomes stable before the 100th generation. This
//occurs fairly often in the Von Neumann neighborhood,
//but almost never in the Moore neighborhood.
bool compare(int array1[22][42], int array2[22][42])
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

//portion of the array that we're really interested in. A live cell is marked
//by a '*', and a dead or vacant cell by a ' '.
void print(int array[22][42])
{
	for(int j = 1; j < 21; j++)
	{
		for(int i = 1; i < 41; i++) 			
		{	
			if(array[j][i] == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}
//Copies one array to another.
void copy(int array1[22][42], int array2[22][42])
{
	for(int j = 0; j < 21; j++)
	{
		for(int i = 0; i < 41; i++) 			
			array2[j][i] = array1[j][i]; 
	}
}

//The life function is the most important function in the program.
//It counts the number of cells surrounding the center cell, and 
//determines whether it lives, dies, or stays the same.
void life(int array[22][42], char choice)
{
	//Copies the main array to a temp array so changes can be entered into a grid
	//without effecting the other cells and the calculations being performed on them.
	int temp[22][42];
	copy(array, temp);
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
	copy(temp, array);
}
void print_clean(int array[22][42])
{
	for(int j = 1; j < 21; j++)
	{
		for(int i = 1; i < 41; i++) 			
		{	
			if(array[j][i] == 1)
				cout << ' ';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

