/*********************************************************************
 ** Program Filename: Yahtzee.cpp
 ** Author: R. Hayden Anderson
 ** Date: 11/10/16	
 ** Description: game of yahtzee
 ** Input: amount of players
 ** Output: N/A
 *********************************************************************/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
long int roll_dice();
long int is_num(string input);
void check_cla(long int argc, char *arg[]);
void choose_die(char* keep);
void print_dice(long int dice[], long int amount);
void show_categories();
void check_category(long int category, long int *die,long int **scorecard, long int player);
void check_ones(long int *die,long int **scorecard, long int player);
void check_twos(long int *die,long int **scorecard, long int player);
void check_threes(long int *die,long int **scorecard, long int player);
void check_fours(long int *die,long int **scorecard, long int player);
void check_fives(long int *die,long int **scorecard, long int player);
void check_six(long int *die,long int **scorecard, long int player);
void check_threekind(long int *die,long int **scorecard, long int player);
void check_fourkind(long int *die,long int **scorecard, long int player);
void check_fullhouse(long int *die,long int **scorecard, long int player);
void check_small_straight(long int *die,long int **scorecard, long int player);
void check_large_straight(long int *die,long int **scorecard, long int player);
void check_chance(long int *die,long int **scorecard, long int player);
void check_yahtzee(long int *die,long int **scorecard, long int player);
long int pick_again();
void play_again(char*arg[]);
void scores(long int **scorecard, long int player);
void do_roll(char *keep, long int *die);
void do_turn(long int players, long int *die, long int **scorecard,long int k);
void create_scorecard(long int **scorecard, long int players);

/*********************************************************************
 ** Function: main
 ** Description: initializes variables and starts yahtzee
 ** Parameters: argument count and array of arguments
 ** Pre-Conditions: enters in an integer for a command line argument
 ** Post-Conditions:
 ** Return: 0
 *********************************************************************/ 
int main(int argc, char*arg[]){
	//check command line
	check_cla(argc, arg);
	//initialize variables
	srand(time(NULL));
	long int dice_rolls = 5;
	long int die[5];
	long int players = atoi(arg[1]);
	//create scorecard
	long int **scorecard = new long int*[players];
	create_scorecard(scorecard, players);
	//play until all categories are filled (13)
	for (long int k = 0;k < 13; k++){
		//choose categorry till player count
		do_turn(players,die,scorecard, k);
	}
	scores(scorecard, players);
	//clean up
	for (long int i = 0; i< players; i++){
		delete [] scorecard[i];
	}
	delete [] scorecard;
	play_again(arg);
	return 0;
}
/*********************************************************************
 ** Function: create_scorecard
 ** Description: initializes 2d array to -1
 ** Parameters: scorecard and player amount
 ** Pre-Conditions: N/A
 ** Post-Conditions: scorecard initialized all values to -1
 ** Return: N/A
 *********************************************************************/ 
void create_scorecard(long int **scorecard, long int players){
	//pout it on the heap for all players and 17 ints for each player
	for (long int i = 0; i < players; ++i){
		scorecard[i] = new long int[17];	
	}
	//initialize all values to -1
	for (long int rows = 0;rows < players; rows++){
		for (long int cols = 0; cols < 17; cols++){
			scorecard[rows][cols] = -1;
		}
	}
}

/*********************************************************************
 ** Function: do_turn
 ** Description: does a turn
 ** Parameters: total players, die, scorecard, and what player you're on
 ** Pre-Conditions: already created the parameters
 ** Post-Conditions: changes a singular categories value
 ** Return:N/A
 *********************************************************************/ 
void do_turn(long int players, long int *die, long int **scorecard, long int k){
	for (long int j = 0; j < players; j++){
		char keep[255];
		for(int i =0; i <5; i++){//initialize what to keep to n
			keep[i] = 'n';
		}
		long int chosen_category = 0;
		cout << "Player: " << j+1 << endl;
		//do rolls and ask three times
		do_roll(keep, die);
		string input;
		show_categories();
		print_dice(die,5);
		cin >> input;
		chosen_category = is_num(input);//check input is a number
		check_category(chosen_category,die, scorecard,j);
		cin.ignore();
		cout << k+1 << " categories filled." << endl;
		}
}
/*********************************************************************
 ** Function: do_roll
 ** Description: does 3 rolls of die and asks which ones to keep
 ** Parameters: character array to keep and dice array
 ** Pre-Conditions: paramters created already
 ** Post-Conditions: will come to a final position of dice
 ** Return: N/A
 *********************************************************************/ 
void do_roll(char *keep, long int *die){
	for (long int i = 0; i < 3; i++){//3 rolls
		for (long int d = 0; d< 5; d++){//roll for each dice that keep didnt have 'y' for
			if (keep[d] != 'y')
				die[d] = roll_dice();
		}
		print_dice(die, 5);
		if (i<2){
			choose_die(keep);//ask user to choose dice to keep on first two rolls
		}

	}

}
/*********************************************************************
 ** Function: scores
 ** Description: adds scorecard together
 ** Parameters: scorecard, and player amount
 ** Pre-Conditions: parameters created and all 13 categories filled
 ** Post-Conditions: scorecard top half, bonus, and sum filled
 ** Return: N/A
 *********************************************************************/ 
void scores(long int **scorecard, long int player){
	for (long int i = 0; i < player; i++){
		scorecard[i][6] = 0; //initialize to 0 since it was -1
		for (long int j = 0; j<6; j++){
			scorecard[i][6] += scorecard[i][j];//add all top half to this as sum
		}
		if(scorecard[i][6] > 62){
			scorecard[i][7] = 35;//add 35 if top half is greater than 62
		}
		else{
			scorecard[i][7] = 0;
		}
		for (long int j = 8; j<15; j++){
			scorecard[i][15] += scorecard[i][j];//add bottom half
		}
		scorecard[i][15] += (scorecard[i][6] + scorecard[i][7]);//add all sums and bonus
		cout << "\nplayer " << i+1 << " score is: " << scorecard[i][15] << endl;
	}
}
/*********************************************************************
 ** Function: pick_again
 ** Description: if category has already been picked, asks user to pick again
 ** Parameters: N/A
 ** Pre-Conditions: you need another category to pick
 ** Post-Conditions: returns a category to pick
 ** Return: the category to pick
 *********************************************************************/ 
long int pick_again(){
	long int cat = 0;
	cout << "You've already chosen that category! pick another." << endl;
	string input;
	cin >>input;
	cat = is_num(input);
	return cat;
}
/*********************************************************************
 ** Function: choose_die
 ** Description: asks what dice of the 5 to keep and gets the input
 ** Parameters: character array
 ** Pre-Conditions: parameters created
 ** Post-Conditions: you find out what they want to keep or reroll
 ** Return: N/A
 *********************************************************************/ 
void choose_die(char keep[]){
	//get y's or else
	cout << "What dice to you want to keep? y for keep n for not keep ie: yynnn will keep the first 2 and roll the other 3 again." << endl;
	cin.getline(keep,255);

}

/*********************************************************************
 ** Function: print_dice
 ** Description: prints an array of ints
 ** Parameters: an integer array and its size
 ** Pre-Conditions: parameters made
 ** Post-Conditions: N/A
 ** Return: N/A
 *********************************************************************/ 
void print_dice(long int dice[], long int amount){
	cout << "\nyour roll is: ";
	//print 5 dice
	for (long int i = 0; i < amount; i++){
		cout << dice[i];
	}
	cout << endl;
}
/*********************************************************************
 ** Function: check_ones
 ** Description: checks the amount of ones and adds it to the ones category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in ones place filled
 ** Return: N/A
 *********************************************************************/ 
void check_ones(long int *die,long int **scorecard, long int player){
	long int amount = 0;
	//count all ones and add them to running total
	for (long int i = 0; i < 5; i++){
		if (die[i] == 1){
			amount++;
		}
	}
	scorecard[player][0] = amount;
	cout << "\nscorecard ones: " << scorecard[player][0] << endl;
}
/*********************************************************************
 ** Function: check_twos
 ** Description: checks the amount of twos and adds it to the twos category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in twos place filled
 ** Return: N/A
 *********************************************************************/ 
void check_twos(long int *die,long int **scorecard, long int player){
	long int amount = 0;
	//count all twos and add them to running total
	for (long int i = 0; i < 5; i++){
		if (die[i] == 2){
			amount+=2;
		}
	}
	scorecard[player][1] = amount;
	cout << "\nscorecard twos: " << scorecard[player][1] << endl;
}
/*********************************************************************
 ** Function: check_threes
 ** Description: checks the amount of threes and adds it to the threes category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in threes place filled
 ** Return: N/A
 *********************************************************************/ 
void check_threes(long int *die,long int **scorecard, long int player){
	long int amount = 0;
	//count all threes and add them to running total
	for (long int i = 0; i < 5; i++){
		if (die[i] == 3){
			amount += 3;
		}
	}
	scorecard[player][2] = amount;
	cout << "\nscorecard threes: " << scorecard[player][2] << endl;
}
/*********************************************************************
 ** Function: check_fours
 ** Description: checks the amount of fours and adds it to the fours category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in fours place filled
 ** Return: N/A
 *********************************************************************/ 
void check_fours(long int *die,long int **scorecard, long int player){
	long int amount = 0;
	//count all fours and add them to running total
	for (long int i = 0; i < 5; i++){
		if (die[i] == 4){
			amount+=4;
		}
	}
	scorecard[player][3] = amount;
	cout << "\nscorecard fours: " << scorecard[player][3] << endl;
}
/*********************************************************************
 ** Function: check_fives
 ** Description: checks the amount of fives and adds it to the fives category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in fives place filled
 ** Return: N/A
 *********************************************************************/ 
void check_fives(long int *die,long int **scorecard, long int player){
	long int amount = 0;
	//count all fives and add them to running total
	for (long int i = 0; i < 5; i++){
		if (die[i] == 5){
			amount+=5;
		}
	}
	scorecard[player][4] = amount;
	cout << "\nscorecard fives: " << scorecard[player][4] << endl;
}
/*********************************************************************
 ** Function: check_six
 ** Description: checks the amount of sixes and adds it to the sixes category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in sixes place filled
 ** Return: N/A
 *********************************************************************/ 
void check_six(long int *die,long int **scorecard, long int player){
	long int amount = 0;
	//count all sixes and add them to running total
	for (long int i = 0; i < 5; i++){
		if (die[i] == 6){
			amount+=6;
		}
	}
	scorecard[player][5] = amount;

	cout << "\nscorecard sixes: " << scorecard[player][5] << endl;
}
/*********************************************************************
 ** Function: check_threekind
 ** Description: checks the amount of three of a kind and adds it to the three of a kind category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in three of a kind place filled
 ** Return: N/A
 *********************************************************************/ 
void check_threekind(long int *die,long int **scorecard, long int player){
	sort(die, die + 5);
	//check 1,2,3 or 2,3,4 or 3,4,5 are equal
	if(die[0] == die[1] && die[1] == die[2] ||
			die[1] == die[2] && die[2] == die[3] ||
			die[2] == die[3] && die[3] == die[4]){
		long int amount = 0;
		for (long int i = 0; i<5; i++){
			amount += die[i];
		}
		scorecard[player][8] = amount;
	}
	else{
		scorecard[player][8] = 0;
	}
	cout << "\nscorecard three of a kind: " << scorecard[player][8] << endl;
}
/*********************************************************************
 ** Function: check_fourkind
 ** Description: checks the amount of four of a kind and adds it to the four of a kind category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in four of a kind place filled
 ** Return: N/A
 *********************************************************************/ 
void check_fourkind(long int *die,long int **scorecard, long int player){
	sort(die, die + 5);
	//check 1,2,3,4 are equal or 2,3,4,5 are equal
	if(die[0] == die[1] && die[1] == die[2] && die[2] == die[3] ||
			die[1] == die[2] && die[2] == die[3] && die[3] == die[4]){
		long int amount = 0;
		for (long int i = 0; i<5; i++){
			amount += die[i];
		}
		scorecard[player][9] = amount;
	}
	else{
		scorecard[player][9] = 0;
	}
	cout << "\nscorecard four of a kind: " << scorecard[player][9] << endl;
}
/*********************************************************************
 ** Function: check_fullhouse
 ** Description: checks the amount of full house and adds it to the full house category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in full house place filled
 ** Return: N/A
 *********************************************************************/ 
void check_fullhouse(long int *die,long int **scorecard, long int player){
	sort(die, die + 5);
	//check if first 3 dice are equal and last two are equal or first two are equal and last three are equal
	if (die[0] == die[1] && die[2] == die[3] && die[3] == die[4] ||
			die[0] == die[1] && die[1] == die[2] && die[3] == die[4]){
		scorecard[player][10] = 25;
	}
	else{
		scorecard[player][10] = 0;
	}

	cout << "\nscorecard fullhouse: " << scorecard[player][10] << endl;
}
/*********************************************************************
 ** Function: check_small_straight
 ** Description: checks the amount of small straight and adds it to the small straight category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in small straight place filled
 ** Return: N/A
 *********************************************************************/ 
void check_small_straight(long int *die,long int **scorecard, long int player){
	sort(die, die + 5);
	long int amount1 = 0,amount2 = 0,amount3=0,amount4=0,amount5=0,amount6=0;
	//count amount of each die
	for (long int i = 0; i< 5; i++){
		if(die[i] == 1)
			amount1++;
		else if(die[i] == 2)
			amount2++;
		else if(die[i] == 3)
			amount3++;
		else if(die[i] == 4)
			amount4++;
		else if(die[i] == 5)
			amount5++;
		else if(die[i] == 6)
			amount6++;}
		//make sure theres atleast 1 in 1,2,3,4 or 2,3,4,5 or 3,4,5,6
	if(amount1>0 && amount2>0 && amount3>0 && amount4>0 ||
			amount2>0 && amount3>0 && amount4>0 && amount5>0 ||
			amount3>0 && amount4>0 && amount5>0 && amount6>0){
		scorecard[player][11] = 30;}
	else{
		scorecard[player][11] = 0;}
	cout << "\nscorecard small straight: " << scorecard[player][11] << endl;
}
/*********************************************************************
 ** Function: check_large_straight
 ** Description: checks the amount of large straight and adds it to the large straight category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in large straight place filled
 ** Return: N/A
 *********************************************************************/ 
void check_large_straight(long int *die,long int **scorecard, long int player){
	sort(die, die + 5);
	//check 1,2,3,4,5 or 2,3,4,5,6
	if(die[0] == 1 && die[1] == 2 && die[2] == 3 && die[3] == 4 && die[4] == 5 ||
			die[0] == 2 && die[1] == 3 && die[2] == 4 && die[3] == 5 && die[4] == 6){
		scorecard[player][12] = 40;
	}
	else{
		scorecard[player][12] = 0;
	}

	cout << "\nscorecard large straight: " << scorecard[player][12] << endl;
}
/*********************************************************************
 ** Function: check_chance
 ** Description: checks the amount of chance and adds it to the chance category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in chance place filled
 ** Return: N/A
 *********************************************************************/ 
void check_chance(long int *die,long int **scorecard, long int player){
	sort(die, die + 5);
	long int amount = 0;// initialize as 0 instead of -1
	// add them all together
	for (long int i = 0; i < 5; i++){
		amount += die[i];
	}
	scorecard[player][13] = amount;

	cout << "\nscorecard chance: " << scorecard[player][13] << endl;
}
/*********************************************************************
 ** Function: check_yahtzee
 ** Description: checks the amount of yahtzee and adds it to the yahtzee category
 ** Parameters: dice array, scorecard, and player amount
 ** Pre-Conditions: paramters created
 ** Post-Conditions: scorecard in yahtzee place filled
 ** Return: N/A
 *********************************************************************/ 
void check_yahtzee(long int *die,long int **scorecard, long int player){
	sort(die, die + 4);
	//check all are equal
	if(die[0] == die[1] && die[1] == die[2] && die[2] == die[3] && die[3] == die[4]){
		scorecard[player][14] = 50;
	}
	else{
		scorecard[player][14] = 0;
	}
	cout << "\nscorecard yahtzee: " << scorecard[player][14] << endl;
}
//COMMAND LINE ARGUMENTS
/*********************************************************************
 ** Function: check_cla
 ** Description: checks command line arguments
 ** Parameters: the command line arguments and their count
 ** Pre-Conditions: N/A
 ** Post-Conditions: if CLA are not met, program ends
 ** Return: N/A
 *********************************************************************/ 
void check_cla(long int argc, char *argv[]){

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
//INPUT VALIDATION
/*********************************************************************
 ** Function: is_num
 ** Description: forces an input to be an int
 ** Parameters: a string you need to be an int
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 ** Return: returns input as an int
 *********************************************************************/ 
long int is_num(string input){
	long int num;
	bool bad_input = true;
	while (bad_input){
		for (long int i = 0; i < input.length(); i++){
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
/*********************************************************************
 ** Function: check_category
 ** Description: checks what categfory user wants to do
 ** Parameters:  category, die, scorecard, and what player you're on
 ** Pre-Conditions: already finished 3 rolls
 ** Post-Conditions: chosen category is filled
 ** Return: N/A
 *********************************************************************/ 
void check_category(long int category, long int *die,long int **scorecard, long int player){
	while(1){
		if (category == 1 && scorecard[player][0] == -1){
			check_ones(die, scorecard, player);
			break;
		}
		else if(category == 2 && scorecard[player][1]  == -1){
			check_twos(die, scorecard, player);
			break;
		}
		else if(category == 3 && scorecard[player][2] == -1){
			check_threes(die, scorecard, player);
			break;
		}
		else if(category == 4 && scorecard[player][3]  == -1){
			check_fours(die, scorecard, player);
			break;
		}
		else if(category == 5 && scorecard[player][4] == -1){
			check_fives(die, scorecard, player);
			break;
		}
		else if(category == 6 && scorecard[player][5] == -1){
			check_six(die, scorecard, player);
			break;
		}
		else if(category == 7 && scorecard[player][8] == -1){
			check_threekind(die, scorecard, player);
			break;
		}
		else if(category == 8 && scorecard[player][9] == -1){
			check_fourkind(die, scorecard, player);
			break;
		}
		else if(category == 9 && scorecard[player][10]  == -1){
			check_fullhouse(die, scorecard, player);
			break;
		}
		else if(category == 10 && scorecard[player][11] == -1){
			check_small_straight(die, scorecard, player);
			break;
		}
		else if(category == 11 && scorecard[player][12] == -1){
			check_large_straight(die, scorecard, player);
			break;
		}
		else if(category == 12 && scorecard[player][13] == -1){
			check_chance(die, scorecard, player);
			break;
		}
		else if(category == 13 && scorecard[player][14] == -1){
			check_yahtzee(die, scorecard, player);
			break;
		}
		else{
			category = pick_again();
		}
	}
}
/*********************************************************************
 ** Function: show_categories
 ** Description: shows all categories of yahtzee
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 ** Return: N/A
 *********************************************************************/ 
void show_categories(){
	long int i = 1;
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
	cout << "\nenter the category you want to place this roll long into" << endl;

}
/*********************************************************************
 ** Function: roll_dice
 ** Description: rolls a die
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: N/A
 ** Return: int between 1 and 6
 *********************************************************************/ 
long int roll_dice(){
	return ((rand()%6)+1);
}
/*********************************************************************
 ** Function: play_again
 ** Description: asks user if they want to go back to the beginning of the program
 ** Parameters: character array
 ** Pre-Conditions: N/A
 ** Post-Conditions: either exits or restarts
 ** Return: N/A
 *********************************************************************/ 
void play_again(char*arg[]){
	string input;
	cout << "\n\nWould you like to play again?? yes (1) no (2)" << endl;
	cin >> input; // for 1 or 2
	long int next = is_num(input);
	cout << endl;
	if (next == 1){//to restart program
		cin.ignore();
		main(2,arg);
	}

}
