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
void get_dice(int *array , int);
void create_scorecard(int argc, int *scorecard[]);
void check_cla(int argc, char *arg[]);
void choose_die(char* keep);
void print_dice(int dice[], int amount);
void show_categories();
void check_category(int category, int *die,int **scorecard, int player);
void check_ones(int *die,int **scorecard, int player);
void check_twos(int *die,int **scorecard);
void check_threes(int *die,int **scorecard);
void check_fours(int *die,int **scorecard);
void check_fives(int *die,int **scorecard);
void check_six(int *die,int **scorecard);
void check_threekind(int *die,int **scorecard);
void check_fourkind(int *die,int **scorecard);
void check_fullhouse(int *die,int **scorecard);
void check_small_straight(int *die,int **scorecard);
void check_large_straight(int *die,int **scorecard);
void check_chance(int *die,int **scorecard);
void check_yahtzee(int *die,int **scorecard);
int pick_again();





int main(int argc, char*arg[]){
	check_cla(argc, arg);
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
			scorecard[rows][cols] = 0;
		}
	}
	//create scorecard


	//play until all categories are filled (13)
	for (int k = 0;k < 13; k++){

		//do this roll and choose categorry till player count
		for (int j = 0; j < players; j++){
			char keep[6];
			for (int i = 0; i< 5; i++){
				keep[i] = 'n';
			}

			//roll and ask three times

			int i =0;
			for (int i = 0; i < 3; i++){
				for (int d = 0; d< 5; d++){
					if (keep[d] == 'y')
						d++;
					else
						die[d] = roll_dice();
				}
				print_dice(die, 5);
				choose_die(keep);

			}
			show_categories();
			check_category(chosen_category,die, scorecard,j);




		}
	}
	//clean up
	for (int i = 0; i< players; ++i){
		delete [] scorecard[i];
	}
	delete [] scorecard;

	return 0;
}

void check_category(int category, int *die,int **scorecard, int player){
	int ones,twos,threes,fours,fives,six,threekind,fourkind,fullhouse,small_straight,large_straight,chance,yahtzee = 0;
	while(1){
		if (category == 1 && ones == 0){
			check_ones(die, scorecard, player);
			ones++;
			break;
		}
		else if(category == 2 && twos == 0){
			check_twos(die, scorecard);
			twos++;
			break;
		}
		else if(category == 3 && threes == 0){
			check_threes(die, scorecard);
			threes++;
			break;
		}
		else if(category == 4 && fours == 0){
			check_fours(die, scorecard);
			fours++;
			break;
		}
		else if(category == 5 && fives == 0){
			check_fives(die, scorecard);
			fives++;
			break;
		}
		else if(category == 6 && six == 0){
			check_six(die, scorecard);
			six++;
			break;
		}
		else if(category == 7 && threekind == 0){
			check_threekind(die, scorecard);
			threekind++;
			break;
		}
		else if(category == 8 && fourkind == 0){
			check_fourkind(die, scorecard);
			fourkind++;
			break;
		}
		else if(category == 9 && fullhouse == 0){
			check_fullhouse(die, scorecard);
			fullhouse++;
			break;
		}
		else if(category == 10 && small_straight == 0){
			check_small_straight(die, scorecard);
			small_straight++;
			break;
		}
		else if(category == 11 && large_straight == 0){
			check_large_straight(die, scorecard);
			large_straight++;
			break;
		}
		else if(category == 12 && chance == 0){
			check_chance(die, scorecard);
			chance++;
			break;
		}
		else if(category == 13 && yahtzee == 0){
			check_yahtzee(die, scorecard);
			yahtzee++;
			break;
		}
		else{
			category = pick_again();
		}
	}
	return;



}
int pick_again(){
	int cat = 0;
	cout << "You've already chosen that category! pick another." << endl;
	cin >>cat;
}

void choose_die(char keep[]){
	cout << "What dice to you want to keep? y for keep n for not keep ie: yynnn will keep the first 2 and roll the other 3 again." << endl;
	cin.getline(keep,6);

}
void create_scorecard(int argc, int **scorecard){
	int players = 2;	
	if(isdigit(argc)){
		cout << "You need to input an amount of players in the command line" << endl;
		exit(0);
	}
	else{
		for (int i = 0; i < players-1; i++){
			*scorecard[i] = 0;
		}

	}
	for (int i = 0; i < players; i++){
		cout << *scorecard[i] << endl;
	}

}
int roll_dice(){
	return ((rand()%6)+1);
}

void get_dice(int *array, int amount){
	for (int i = 0;i<amount;i++){
		array[i] = roll_dice();
	}
	sort(array, array + 5);
	print_dice(array, amount);

}
void print_dice(int dice[], int amount){
	sort(dice, dice + 5);
	for (int i = 0; i < amount; i++){
		cout << dice[i];
	}
	cout << endl;

}
void check_ones(int *die,int **scorecard, int player){
	int amount = 0;
	for (int i = 0; i < 5; i++){
		if (die[i] == 1);
		scorecard[player][0]++;
	}
	cout << *scorecard[0];
}
void check_twos(int *die,int **scorecard){

}
void check_threes(int *die,int **scorecard){

}
void check_fours(int *die,int **scorecard){

}
void check_fives(int *die,int **scorecard){

}
void check_six(int *die,int **scorecard){

}
void check_threekind(int *die,int **scorecard){

}
void check_fourkind(int *die,int **scorecard){

}
void check_fullhouse(int *die,int **scorecard){

}
void check_small_straight(int *die,int **scorecard){

}
void check_large_straight(int *die,int **scorecard){

}
void check_chance(int *die,int **scorecard){

}
void check_yahtzee(int *die,int **scorecard){

}
void check_cla(int argc, char *argv[]){

	if (argc < 2){
		cout << "You need to enter a number as a command line argument for player amount" << endl;
		exit(0);
	}
	else if(argc > 2){
		cout << "that is too many arguments" << endl;
		exit(0);
	}
	else if(!isdigit(*argv[1])){
		cout << "your argument must be a digit" << endl;
		exit(0);
	}
	else
		cout << "Welcome to yahtzee" << endl;

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
void show_categories(){
	int i = 1;
	while (i <7){
		cout << "category " << i << ": " << i << "'s" << endl;
		i++;
	}
	cout << "category 7 is: 3 of a kind" << endl;
	cout << "category 8 is: 4 of a kind" << endl;
	cout << "category 9 is: full house" << endl;
	cout << "category 10 is: small straight" << endl;
	cout << "category 11 is: large straight" << endl;
	cout << "category 12 is: chance" << endl;
	cout << "category 13 is: YAHTZEE!!!" << endl;
	cout << "enter the category you want to place this roll into" << endl;

}
