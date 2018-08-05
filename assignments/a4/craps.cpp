/*********************************************************************
** Program Filename: craps.cpp	
** Author: R. Hayden Anderson
** Date: 11/6/2016
** Description: play a game of craps
** Input: N/A
** Output:N/A
*********************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;


int calculate_average();
void get_bank_balance(double &balance);
void get_wager_amount(double &wager, double &balance);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_or_loss_or_point(int sum_dice);//first roll
int is_point_loss_or_neither(int sum_dice, int point_value);//after rolls
void adjust_bank_balance(double &balance, double wager_amount, int add_or_subtract);
void get_all_beg(double &,double&,int&,int&,int&);
void win(double &, double&);
void lose(double &, double &);
int is_num(string input);
void roll1(double &,double&,int&,int&,int&,int& );
void rolln( double &,double&,int&,int&,int&,int& );

/*********************************************************************
** Function: main
** Description: gets the beginning roll info then calls a function tot start ther game
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: N/A
*********************************************************************/ 
int main(){
	srand(time(NULL));
	double balance,wager;
	int dice1,dice2,dice_sum,next;
	string input;
	get_all_beg(balance,wager,dice1,dice2,dice_sum);
	cout << " balance is: " << balance << endl;
	cout << " wager, is: " << wager << endl;
	cout << " dice1 is: " << dice1 << endl;
	cout << " dice2 is: " << dice2 << endl;
	cout << " dice sum for roll 1 is: " << dice_sum << endl;
	roll1(balance,wager,dice1,dice2,dice_sum,next); //do roll 1
	cout << "\n\nWould you like to play again?? yes (1) no (2)" << endl;
	cin >> input; // for 1 or 2
	next = is_num(input);
	cout << endl;
	if (next == 1){//to restart program
		main();
	}
	return 0;
}



/*********************************************************************
** Function: roll1
** Description: the first roll and checks if you win lose or point
** Parameters: 2 doubles and 4 ints of all the first roll and general variables
** Pre-Conditions: you've already received the beginning inputs
** Post-Conditions: N/A
** Return: N/A
*********************************************************************/ 
void roll1(double &balance,double&wager,int &dice1,int &dice2,int &dice_sum,int &next  ){
	while (balance > 0){
		next = is_win_or_loss_or_point(dice_sum);

		if (next == 1){ // if won
			win(balance,wager);
		}
		else if(next == -1){ //if point
			rolln(balance,wager,dice1,dice2,dice_sum,next);
		}
		else{
			lose(balance,wager); // if lose
		}
	}
	return;
}

/*********************************************************************
** Function: rolln
** Description: does the consecutive rolls after the first one
** Parameters: all the base variables
** Pre-Conditions: already done the first roll
** Post-Conditions: N/A
** Return: N/A
*********************************************************************/ 
void rolln(double &balance,double&wager,int &dice1,int &dice2,int &dice_sum,int&next){
	int point = dice_sum;
	cout << "point  is: " << point << endl;

	while (balance > 0){
		cout << "your bank balance is: " << balance << endl;
		get_wager_amount(wager,balance);
		dice1 = roll_die();
		cout << "dice1  is: " << dice1 << endl;

		dice2 = roll_die();
		cout << "dice2  is: " << dice2 << endl;

		dice_sum = calculate_sum_dice(dice1,dice2);
		cout << "sum of dice  is: " << dice_sum << endl;

		next = is_point_loss_or_neither(dice_sum,point);

		if (next){
			win(balance,wager);

		}
		else if(!next){
			lose(balance,wager);

		}

	}
	cout << "You lost all your money...bye felicia!" << endl;
	return;
}
/*********************************************************************
** Function: win
** Description: called when you win and calls a function to add your wager from balance
** Parameters: wager and balance
** Pre-Conditions: n/a
** Post-Conditions: balance + wager
** Return: N/A
*********************************************************************/ 
void win(double &balance, double&wager){
	cout << "you win!" << endl;
	adjust_bank_balance(balance,wager,1);
	cout << "balance  is: " << balance << endl;

}
/*********************************************************************
** Function: lose
** Description: called when you lose and calls a function to subtract your wager from balance
** Parameters: wager and balance
** Pre-Conditions: n/a
** Post-Conditions: balance - wager
** Return:N/A
*********************************************************************/ 
void lose(double &balance, double &wager){
	cout << "you lose!" << endl;
	adjust_bank_balance(balance,wager,0);
	cout << "balance is: " << balance << endl;



}
/*********************************************************************
** Function: get_all_beg
** Description: gets all the beginning information needed
** Parameters: all the variables created
** Pre-Conditions: you've established the orginal values
** Post-Conditions: the values passed are changed implicitly
** Return:N/A
*********************************************************************/ 
void get_all_beg(double &balance,double &wager, int&dice1,int&dice2,int &dice_sum){
	get_bank_balance(balance);
	get_wager_amount(wager,balance);
	dice1 = roll_die();

	dice2 = roll_die();
	dice_sum = calculate_sum_dice(dice1, dice2);
}


/*********************************************************************
** Function: get_bank_balance
** Description: Prompts the player for an initial bank balance from which wagering will be added or subtracted.
** Parameters: a balance you want changed implicitly
** Pre-Conditions: N/A
** Post-Conditions: balance is now the inputted balance
** Return:N/A
*********************************************************************/ 
void get_bank_balance(double &balance){
	cout << "What is your initial bank balance? " << endl;
	string temp;
	cin >> temp;
	balance = is_num(temp);

}

/*********************************************************************
** Function: get_wager_amount
** Description: Prompts the player for a wager on a particular roll.
** Parameters: 2 doubles you want changeed implicitly
** Pre-Conditions: N/A
** Post-Conditions: get a wager amount that's less than the balance
** Return: N/A
*********************************************************************/ 
void get_wager_amount(double &wager,double &balance){
	do{
		cout << "what is your wager?" << endl;
		string temp;
		cin >> temp;
		wager = is_num(temp);
	}while(!check_wager_amount(wager,balance));
}


/*********************************************************************
** Function: check_wager_amount
** Description: Checks to see if the
** wager is within the limits of the player's available balance. If the wager exceeds the
** player's allowable balance, then 0 is returned; otherwise 1 is returned.
** Parameters: two doubles
** Pre-Conditions:  N/A
** Post-Conditions: N/A
** Return: 0 or 1 depending on if wager is higher than balance
*********************************************************************/ 
int check_wager_amount(double wager, double balance){
	if (wager > balance){
		cout << "That wager is higher than your balance..." << endl;
		return 0;
	}
	else{
		return 1;
	}


}



/*********************************************************************
** Function:roll_die
** Description: Rolls one die. This function should randomly generate a value
** between 1 and 6, inclusively. Returns the value of the die.
** Parameters: void
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: a number between 1 and 6
*********************************************************************/ 
int roll_die(void){

	return ((rand() % 6) + 1);
}


/*********************************************************************
** Function:calculate_sum_dice
** Description: Sums together the
** values of the two dice and returns the result. Note: this result may become the player's
** point in future rolls.
** Parameters: 2 ints
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: sum of 2 numbers
*********************************************************************/ 
int calculate_sum_dice(int die1_value, int die2_value){
	int sum = die1_value + die2_value;
	return sum;
}




/*********************************************************************
** Function: is_win_or_loss_or_point
** Description: Determines the result of the first dice
** roll. If the sum is 7 or 11 on the roll, the player wins and 1 is returned. If the sum is 2, 3,
** or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins) and 0 is 
** returned. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the
** player's "point" and -1 is returned.
**  (5 pts) int is_point_loss_or_neither
** Parameters: an int
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: 1,0,or -1 depending on if you won lost or point
*********************************************************************/ 
int is_win_or_loss_or_point(int sum_dice){
	if (sum_dice == 7 || sum_dice == 11){
		cout << "you win! with a sum of "<< sum_dice << endl;
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12){
		cout << "craps! with a sum of " << sum_dice << endl;
		return 0;
	}
	else {
		cout << "point! Your point is " << sum_dice << "!" << endl;
		return -1;
	}
}


/*********************************************************************
** Function: is_point_loss_or_neither
** Description: Determines the result of any successive roll after the first roll. If the sum of the 
** roll is the point_value, then 1 is returned. If the sum of the roll is a 7, then 0 is
** returned. Otherwise, -1 is returned.
** Parameters: 2 ints
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: 1,0,or -1 depending on if you won lost or neither
*********************************************************************/ 
int is_point_loss_or_neither(int sum_dice, int point_value){
	if (sum_dice == point_value){
		return 1;
	}
	else if (sum_dice == 7){
		return 0;
	}
	else{
		return -1;
	}

}



/*********************************************************************
** Function: adjust_bank_balance
** Description: If add_or_subtract is 1, then the wager amount is added to the
** bank_balance. If add_or_subtract is 0, then the wager amount is subtracted from the
** bank_balance. Otherwise, the bank_balance remains the same.
** Parameters: 2 doubles and a 1 or 0 for add or subtract
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: N/A
*********************************************************************/ 
void adjust_bank_balance(double &bank_balance, double wager_amount, int add_or_subtract){
	if (add_or_subtract == 1){
		bank_balance += wager_amount;
	}
	else if (add_or_subtract == 0){

		bank_balance -= wager_amount;
	}
	else {
		return;
	}

}
/*********************************************************************
** Function: is_num
** Description: checks if input is an int
** Parameters: a string
** Pre-Conditions: N/A 
** Post-Conditions: returns the string as an int.
** Return: the inputted string as an int
*********************************************************************/ 
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
