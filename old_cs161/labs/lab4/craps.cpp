#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int phase1();
int phase2(int winningNum);
int point;
int main(){
	cout << "The game's Craps, ready to start? (yes = 1/no = 0)"<< endl;
	int start;
	cin >> start;
	if (start == 1){
		point = phase1();
		if (point > 0){
			phase2(point);

		}
	}
	else{
		cout << "maybe later..."<< endl;
	}

	return 0;

}

int phase1(){
	srand (time(NULL));

	int die1 =0;
	int die2 =0;
	die1 = rand() % 6 + 1;
	cout << "die1 landed on "<< die1<< endl;
	die2 = rand() % 6 +1;
	cout << "die2 landed on " << die2 << endl;
	cout << "total is "<< die1 + die2 << endl;

	if ((die1 + die2) == 2 || (die1 + die2) == 3 || (die1+die2) == 12){
		cout << "you lose!!!" << endl;
		return 0;
	}	
	else if ((die1 + die2) == 7 || (die1+die2) == 11){
		cout << "YOU WIN!!!!!!!!!!!!" << endl;
		return 0;
	}
	else
		point = die1 + die2;
	return point;
}


int phase2(int winningNum){
	cout << "                      PHASE 2" << endl;

	srand (time(NULL));

	int die1 =0;
	int die2 =0;
	int i =0;	
	do {
		die1 = rand() % 6 + 1;
		cout << "die1 landed on "<< die1<< endl;
		die2 = rand() % 6 +1;
		cout << "die2 landed on " << die2 << endl;
		cout << "total is "<< die1 + die2 << endl;

		if (die1+die2 == 7){
			cout << "you lose!" << endl;
			i++;
		}
		else if (die1 + die2 == winningNum){
			cout << "you win!" << endl;
			i++;
		}
		else {
			cout << "you need to roll again!" << endl;
			i = 0;
		}

	}while (i =0);
	return 1;

}













