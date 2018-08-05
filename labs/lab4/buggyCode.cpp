
#include <iostream>

using namespace std;

int main(){

	int x=3;
	int y;
	char myAnswer;
	int num =0;
	y = x;
	cout << "y is set to: " << y << endl;


	bool again = true;
	while(again){
	cout << "Please input a number: ";
	cin >> y;
	if(x > y){
			cout << x << " is greater than " << y << endl;
			cout << "would you like to input another number? yes (1) no (0)" << endl;
			cin >> again;
		}
		else{
			cout << x << " is less than or equal to " << y << endl;
			cout << "would you like to input another number? yes (1) no (0)" << endl;
			cin >> again;
		}
	}
	for(x = 0; x < 10; x++){
		cout << x << endl;
	}
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;
	for(int x = num - 1; x > 0; --x){
		num = num * x;
	}
	cout << num << endl;

	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
	if(myAnswer == 'y'){
		cout << "YAY" << endl;
	}
	else{
		cout << "YOU WILL SOON!" << endl;
	}
	return 0;
}
