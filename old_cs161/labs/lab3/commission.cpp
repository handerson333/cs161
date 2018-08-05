#include <iostream>
using namespace std;
int main () {

	int sellPrice = NULL;
	int commission = NULL;
	int eom = NULL;
	cout <<  "how much is the selling price?" << endl;
	cin >> sellPrice ;
	if (sellPrice < 50000){
		commission = sellPrice * .01;
	}
	else if (sellPrice >49999 && sellPrice <100000){
		commission = sellPrice * .03;
	}
	else if (sellPrice > 99999 && sellPrice < 200000){
		commission = sellPrice * .05;
		
	}
	else if (sellPrice >199999 && sellPrice < 500000){
		commission = sellPrice * .075;
		eom += 1;
	}
	else if (sellPrice >499999 && sellPrice < 1000000){
		commission = sellPrice * .1;
		eom += 1;
	}
	else if (sellPrice > 1000000){
		commission = sellPrice * .02;
		eom += 1;
	}

	else { 
		cout << "That is not a number!!!!" << endl;
	}
	cout << "you get $" << commission << " of commission!" << endl;
	if (eom > 0 ) {
		cout << " and you are the salesperson of the MONTH!" << endl;
		}
}
