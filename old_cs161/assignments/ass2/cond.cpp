#include <iostream>
#include <cstdlib>
using namespace std;
void highestTen();
void yearsFM();
void average();
void dec2Bin();


int main(){
	int x = 0;
	int ans = NULL;
	while (x == 0)
	{
		int x = 0;  //resets x back to 0
		cout << "1. Highest of 10" << endl;
		cout << "2. Years for money" << endl;
		cout << "3. Average number" << endl;
		cout << "4. Decimal to binary" << endl; 
		cout << "5. Exit this program" << endl;
		cin >> ans;

		if (ans ==  1)
		{
			highestTen();
			x += 1;
		}
		else if (ans == 2)
		{
			yearsFM();
			x += 1;
		}
		else if (ans == 3){
			average();
			x += 1;
		}
		else if (ans == 4){
			dec2Bin();
			x +=1;
		}
		else if (ans == 5){
			return 0;
		}
		else{
			cout << "invalid input!" << endl;
		}
	}

}

void highestTen(){
	int lastNum = 0;
	int num;
	cout << "enter 10 numbers!" << endl; 
	for (int x = 1; x <= 10; x++)
	{
		cin >> num;
		if (num > lastNum)
			lastNum = num;



	}

	cout <<"The highest input was "<< lastNum << endl;
}

void yearsFM () {
	// Initializing variables
	double startValue;
	double targetValue;
	double aPR;
	int years;

	// Getting values from user
	cout << "We are going to see how many years it will take to reacch an amount with APR!" << endl;
	cout << "First off, how much money do you currently have?" << endl;
	cin >> startValue;
	cout << "Good! And how much did you want to end with?" << endl;
	cin >> targetValue;
	cout << "What is the Annual Percentage Rate you are receiving?" << endl;
	cin >> aPR;

	// process
	do {
		years += 1;
		startValue = startValue * ((1+ aPR)/100);
	}
	while (startValue < targetValue);
	cout << "You will reach " << targetValue << " in " << years << " years." << endl;
}

void average (){
	int input = 0;
	int total = 0;
	int numOfInputs = 0;
	int avg;
	cout<< "Give me some positive integers and Ill give you the average!" << endl;
	cout << "When you're finished just enter -1" << endl;
	while (input >= 0){
		cin >> input;
		if (input>=0){
			numOfInputs +=1;
			total  = total + input ;
		}
	}
	avg = total / numOfInputs;
	cout << "The average is " << avg<< "!" << endl;
}

void dec2Bin (){
	int arr [31] = {0};
	int input = 0;
	int output = 0;
	int rem = 0;
	cout << "What number do you want to convert to binary?" << endl;
	cin >> input;

	while (input > 1){
		rem = input %2;
		input = input/2;
		for (int i=0; i < 32; i++){
			arr[i] = rem;
		}
	}

		cout << -arr[31,30,29,28,27,26,25,24]<< endl;
}

