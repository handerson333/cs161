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
void create_scorecard(int argc, char *scorecard[]);
int main(int argc, char*arg[]){

	cout << argc << endl;
	cout << arg[1] << endl;
	create_scorecard(argc, arg);
	int players = atoi(arg[1])+1;
	int *scorecard[17];

	for (int i =0; i < players-1; i++){
		scorecard[i] = new int[players];
	}
	for (int i = 0; i < players-1; i++){
		delete scorecard[i]; 
	}

	return 0;
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
