#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
int check_is_fullhouse(int *input);
void convert_to_int(char*,int*);
int roll_dice();
int is_num(string input);
void get_dice(int *array);
void change_shit(int **scorecard, int players);
void create_scorecard(int argc, char *scorecard[]);
int main(int argc, char*arg[]){

	//initialize variables
	srand(time(NULL));
	int chosen_category = 0;
	int dice_rolls = 5;
	int die[6];
	int players = atoi(arg[1]);
	int **scorecard = new int*[players];
	for (int i = 0; i < players; ++i){
		scorecard[i] = new int[17];	
	}
	for (int rows = 0;rows < players; rows++){
		for (int cols = 0; cols < 17; cols++){
			scorecard[rows][cols] = -1;
		}
	}
	players = 0;
	change_shit(scorecard,players);
	//cout << scorecard[players][3] << endl;
	int amount = 0;
	cout << "amount1: " << amount << endl;
	for (int i = 1; i<5; i++){
		die[i] = roll_dice();
		cout << "die " << i << ":" << die[i] << endl;;
		amount += die[i];
	}
	cout << "amount2: " << amount;
	cout << endl;
	/* this works
	   int players = atoi(arg[1]);
	   int **scorecard = new int*[players];
	   for (int i = 0; i < players; ++i){
	   scorecard[i] = new int[17];	
	   }
	   for (int rows = 0;rows < players; rows++){
	   for (int cols = 0; cols < 17; cols++){
	   scorecard[rows][cols] = 6;
	   cout << scorecard[rows][cols];
	   }
	   cout << endl;
	   }
	   */



	/*
	   cout << argc << endl;
	   cout << arg[1] << endl;

	   create_scorecard(argc, arg);
	   int players = atoi(arg[1])+1;
	   int *scorecard[17];
	   scorecard[0] = new int[players];

	//	for  (int j = 0; j < players; j++){
	for (int i = 0; i<16; i++){
	scorecard[0][i] = i;

	}
	//	}
	for (int i=0; i<16; i++){
	cout << scorecard[0][i] << endl;
	}

	delete [] *scorecard; 
	*/
	return 0;
}
void change_shit(int **scorecard, int players){
	scorecard[players][3] = 25;
	scorecard[players][3]++;

}
void create_scorecard(int argc, char **scorecard){
}
int roll_dice(){
	return ((rand()%6)+1);
}

void get_dice(int *array){
	for (int i = 0;i<5;i++){
		array[i] = roll_dice();
	}

}
int is_num(string input){
	int num;
	bool bad_input = true;
	while (bad_input){
		for (int i = 0; i < input.length(); i++){
			if (isdigit(input[i])){
				bad_input = false;
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
	num = atoi(input.c_str());
	return num;
}
