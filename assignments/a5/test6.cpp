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
void check_cla(int argc, char *arg[]);
void choose_die(char* keep);
void print_dice(int dice[], int amount);
void show_categories();
void check_category(int category, int *die,int **scorecard, int player);
void check_ones(int *die,int **scorecard, int player);
void check_twos(int *die,int **scorecard, int player);
void check_threes(int *die,int **scorecard, int player);
void check_fours(int *die,int **scorecard, int player);
void check_fives(int *die,int **scorecard, int player);
void check_six(int *die,int **scorecard, int player);
void check_threekind(int *die,int **scorecard, int player);
void check_fourkind(int *die,int **scorecard, int player);
void check_fullhouse(int *die,int **scorecard, int player);
void check_small_straight(int *die,int **scorecard, int player);
void check_large_straight(int *die,int **scorecard, int player);
void check_chance(int *die,int **scorecard, int player);
void check_yahtzee(int *die,int **scorecard, int player);
int pick_again();
void play_again(char*arg[]);
void scores(int **scorecard, int player);
void do_roll(char *keep, int *die);
void do_turn(int players, int *die, int **scorecard,int k);



int main(int argc, char*arg[]){
	check_cla(argc, arg);
	//initialize variables
	srand(time(NULL));
	int dice_rolls = 5;
	int die[5];
	int players = atoi(arg[1]);
	int **scorecard = new int*[players];
	for (int i = 0; i < players; ++i){
		scorecard[i] = new int[16];	
	}
	for (int rows = 0;rows < players; rows++){
		for (int cols = 0; cols < 16; cols++){
			scorecard[rows][cols] = -1;
		}
	}
	//create scorecard

	//play until all categories are filled (13)
	for (int k = 0;k < 13; k++){

		//choose categorry till player count
		do_turn(players,die,scorecard, k);


	}
	scores(scorecard, players);
	//clean up
	for (int i = 0; i< players; ++i){
		delete [] scorecard[i];
	}
	delete [] scorecard;
	play_again(arg);
	return 0;
}
void do_turn(int players, int *die, int **scorecard, int k){
	for (int j = 0; j < players; j++){
		char keep[255];
		int chosen_category = 0;
		cout << "Player: " << j+1 << endl;

		//roll and ask three times
		do_roll(keep, die);

		string input;
		show_categories();
		print_dice(die,5);
		cin >> input;
		chosen_category = is_num(input);
		check_category(chosen_category,die, scorecard,j);
		cin.ignore();
		cout << k+1 << " categories filled." << endl;


	}

}




void do_roll(char *keep, int *die){
	for (int i = 0; i < 3; i++){
		for (int d = 0; d< 5; d++){
			if (keep[d] != 'y')
				die[d] = roll_dice();
		}
		print_dice(die, 5);
		if (i<2){
			choose_die(keep);
		}

	}

}

void scores(int **scorecard, int player){
	for (int i = 0; i < player; i++){
		scorecard[player][6] =0;
		for (int j = 0; j<6; j++){
			scorecard[player][6] += scorecard[player][j];
		}
		if(scorecard[player][6] > 62){
			scorecard[player][7] = 35;
		}
		else{
			scorecard[player][7] = 0;
		}
		for (int j = 8; j<15; j++){
			scorecard[player][15] += scorecard[player][j];
		}
		scorecard[player][15] += (scorecard[player][6] + scorecard[player][7]);
		cout << "player " << i << " score is: " << scorecard[player][15] << endl;
	}
}





void check_category(int category, int *die,int **scorecard, int player){
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
	return;



}
int pick_again(){
	int cat = 0;
	cout << "You've already chosen that category! pick another." << endl;
	string input;
	cin >>input;
	cat = is_num(input);
	return cat;
}

void choose_die(char keep[]){
	cout << "What dice to you want to keep? y for keep n for not keep ie: yynnn will keep the first 2 and roll the other 3 again." << endl;
	cin.getline(keep,255);

}



void get_dice(int *array, int amount){
	for (int i = 0;i<amount;i++){
		array[i] = roll_dice();
	}
	sort(array, array + 5);
	print_dice(array, amount);

}
void print_dice(int dice[], int amount){
	cout << "your roll is: ";
	for (int i = 0; i < amount; i++){
		cout << dice[i];
	}
	cout << endl;

}
//DIFFERENT CATEGORY CHECKERS
void check_ones(int *die,int **scorecard, int player){
	int amount = 0;
	for (int i = 0; i < 5; i++){
		if (die[i] == 1){
			amount++;
		}
	}
	scorecard[player][0] = amount;
	cout << "scorecard ones: " << scorecard[player][0] << endl;
}
void check_twos(int *die,int **scorecard, int player){
	int amount = 0;
	for (int i = 0; i < 5; i++){
		if (die[i] == 2){
			amount+=2;
		}
	}
	scorecard[player][1] = amount;
	cout << "scorecard twos: " << scorecard[player][1] << endl;
}
void check_threes(int *die,int **scorecard, int player){
	int amount = 0;
	for (int i = 0; i < 5; i++){
		if (die[i] == 3){
			amount += 3;
		}
	}
	scorecard[player][2] = amount;
	cout << "scorecard threes: " << scorecard[player][2] << endl;
}
void check_fours(int *die,int **scorecard, int player){
	int amount = 0;
	for (int i = 0; i < 5; i++){
		if (die[i] == 4){
			amount+=4;
		}
	}
	scorecard[player][3] = amount;
	cout << "scorecard fours: " << scorecard[player][3] << endl;
}
void check_fives(int *die,int **scorecard, int player){
	int amount = 0;
	for (int i = 0; i < 5; i++){
		if (die[i] == 5){
			amount+=5;
		}
	}
	scorecard[player][4] = amount;
	cout << "scorecard fives: " << scorecard[player][4] << endl;
}
void check_six(int *die,int **scorecard, int player){
	int amount = 0;
	for (int i = 0; i < 5; i++){
		if (die[i] == 6){
			amount+=6;
		}
	}
	scorecard[player][5] = amount;

	cout << "scorecard sixes: " << scorecard[player][5] << endl;
}
void check_threekind(int *die,int **scorecard, int player){
	sort(die, die + 5);
	if(die[0] == die[1] && die[1] == die[2] ||
			die[1] == die[2] && die[2] == die[3] ||
			die[2] == die[3] && die[3] == die[4]){
		int amount = 0;
		for (int i = 0; i<5; i++){
			amount += die[i];
		}
		scorecard[player][8] = amount;
	}
	else{
		scorecard[player][8] = 0;
	}


	cout << "scorecard three of a kind: " << scorecard[player][8] << endl;
}
void check_fourkind(int *die,int **scorecard, int player){
	sort(die, die + 5);
	if(die[0] == die[1] && die[1] == die[2] && die[2] == die[3] ||
			die[1] == die[2] && die[2] == die[3] && die[3] == die[4]){
		int amount = 0;
		for (int i = 0; i<5; i++){
			amount += die[i];
		}
		scorecard[player][9] = amount;
	}
	else{
		scorecard[player][9] = 0;
	}
	cout << "scorecard four of a kind: " << scorecard[player][9] << endl;
}
void check_fullhouse(int *die,int **scorecard, int player){
	sort(die, die + 5);
	if (die[0] == die[1] && die[2] == die[3] && die[3] == die[4] ||
			die[0] == die[1] && die[1] == die[2] && die[3] == die[4]){
		scorecard[player][10] = 25;
	}
	else{
		scorecard[player][10] = 0;
	}

	cout << "scorecard fullhouse: " << scorecard[player][10] << endl;
}
void check_small_straight(int *die,int **scorecard, int player){
	sort(die, die + 5);
	int amount1 = 0,amount2 = 0,amount3=0,amount4=0,amount5=0,amount6=0;
	for (int i = 0; i< 5; i++){
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
			amount6++;
	}
	if(amount1>0 && amount2>0 && amount3>0 && amount4>0 ||
			amount2>0 && amount3>0 && amount4>0 && amount5>0 ||
			amount3>0 && amount4>0 && amount5>0 && amount6>0){
		scorecard[player][11] = 30;
	}
	else{
		scorecard[player][11] = 0;
	}
	cout << "scorecard small straight: " << scorecard[player][11] << endl;
}

void check_large_straight(int *die,int **scorecard, int player){
	sort(die, die + 5);
	if(die[0] == 1 && die[1] == 2 && die[2] == 3 && die[3] == 4 && die[4] == 5 ||
			die[0] == 2 && die[1] == 3 && die[2] == 4 && die[3] == 5 && die[4] == 6){
		scorecard[player][12] = 40;
	}
	else{
		scorecard[player][12] = 0;
	}

	cout << "scorecard large straight: " << scorecard[player][12] << endl;
}
void check_chance(int *die,int **scorecard, int player){
	sort(die, die + 5);
	int amount = 0;
	for (int i = 0; i < 5; i++){
		amount += die[i];
	}
	scorecard[player][13] = amount;

	cout << "scorecard chance: " << scorecard[player][13] << endl;
}
void check_yahtzee(int *die,int **scorecard, int player){
	sort(die, die + 4);
	cout << "bag of dicks" << endl;
	if(die[0] == die[1] && die[1] == die[2] && die[2] == die[3] && die[3] == die[4]){
		scorecard[player][14] = 50;
		cout << "bag of dicks2" << endl;
	}
	else{
		scorecard[player][14] = 0;
		cout << "bag of dicks3" << endl;
	}
	cout << "scorecard yahtzee: " << scorecard[player][14] << endl;
}



//COMMAND LINE ARTGUMENTS
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
//INPUT VALIDATION
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
int roll_dice(){
	return ((rand()%6)+1);
}

void play_again(char*arg[]){
	string input;
	cout << "\n\nWould you like to play again?? yes (1) no (2)" << endl;
	cin >> input; // for 1 or 2
	int next = is_num(input);
	cout << endl;
	if (next == 1){//to restart program
		main(2,arg);
	}

}
