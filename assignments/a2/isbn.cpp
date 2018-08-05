/****************************************************************
 ** Program Filename: isbn.cpp
 ** Author: R. Hayden Anderson
 ** Date: 10/5/16
 ** Description:  Calculates the checksum of either a 10 digit or 13 digit isbn.
 ** Input: an isbn number -1 digits
 ** Output: the isbn number with the checksum appended to it
 *****************************************************************/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;
int isbn10();
int isbn13();


int main(){
	cout << "10 digit isbn or 13 digit isbn?" << endl;
	int input = 0;//for 10 or 13
	cin >> input; // get user choice of 10 or 13 isbn
	while (1){
		if (input == 10)
		{
			isbn10(); // if user enters 10 go to the isbn10 function
			break;
		}
		else if (input == 13)
		{
			isbn13(); // if user enters 13 go to the isbn13 function
			break;
		}
		else
		{
			cout << "Please write 10 or 13 for specific isbns" << endl;
			cin >> input;
		}
	}
	cout << "\n\nWould you like to enter another number? yes (1) no (2)" << endl;
	cin >> input; // for 1 or 2
	cout << endl;
	if (input == 1){//to restart program
		main();
	}
	//otherwise end program

	return 0;
};

/****************************************************************
 ** Function: isbn10
 ** Description: asks user for the first 9 digits of an isbn and finds the checksum of the 10th digit
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ** Return: none
 *****************************************************************/
int isbn10(){

	long long input = 0; //needs to be a long long because 13 digits dont fit on a long or int 
	cout << "Please input the first 9 digits of the 10 digit isbn. " << endl;	
	cin >> input;//holds 9 digit user input
	int j = 9;
	int total = 0;
	int i = 2; // multiplier
	int remainder;
	int temp;
	string if10;
	long long original = input % 1000000000;//unchanged 9 digit user input has to be after check. Also truncates anything longer than 9 digits.
	//checksum to find 10th digit
	while (j > 0){
		remainder = input % 10;	//get current right most digit
		total = total + (remainder * i); //multiply current right most digit by the counter
		input = (long long)input / 10;	//get rid of last digit that we already looked at
		i++;
		j--;
	}
	temp = 11 - (total % 11);//makes final isbn a multiple of 11 by subtracting the functions totals right most digit from 11 to append to the original isbn given

	//if 10 print X otherwise print the checksum number
	if (temp == 10){
		if10 = "X";
		cout << "\n10 digit isbn = " << original << if10 << endl;
	}
	else if (temp == 11){	//if total is 0 then 11 - 0 = 0, so print 0 and not 11
		if10 = "0";	
		cout << "\n10 digit isbn = " << original << if10 << endl;
	}
	else{
		cout << "\n10 digit isbn = " << original << temp << endl;
	}


}

/****************************************************************
 ** Function: isbn13
 ** Description: asks user for the first 12 digits of an isbn and finds the checksum of the 13th digit
 ** Parameters: none
 ** Pre-Conditions:none
 ** Post-Conditions:none
 ** Return: none
 *****************************************************************/
int isbn13(){
	cout << "Please input the first 12 digits of the 13 digit isbn. " << endl;	
	long long input = 0;
	int i = 3;	//start multiple at 3
	int total = 0;
	int remainder;
	int j = 12; //counter
	int temp;
	string if10;
	cin >> input; 	//holds 12 digit user input
	long long original = input % 1000000000000;	//unchanged 12 digit user input has to be after check. Also truncates anything longer than 12 digits.

	//checksum to find 13th digit
	while (j > 0){
		remainder = input % 10;	//get current right most digit
		total = total + (remainder * i);//multiply the current right most digit by 1 or 3 depending on the last one multiplied with
		input = (long long)input / 10;	//get rid of digit we already looked at
		//make the multiple the opposite of what it was last time
		if (i == 1){
			i = 3;
		}
		else {
			i = 1;
		}	
		j--;
	}
	temp = 10 - (total % 10);	//subtract 10 by the remainder of the ending function to make the entire isbn divisible by 10
	if (temp == 10){		//if total is 0 then 10 - 0 = 0, so print 0 and not 10
		if10 = "0";
		cout << "\n13 digit isbn = " << original << if10 << endl;
	}
	else{
		cout << "\n13 digit isbn = " << original << temp << endl;
	}
}
