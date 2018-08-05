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
int num_digits(long long input);

int main(){
	cout << "10 digit isbn or 13 digit isbn?" << endl;
	int input;//for 10 or 13
	cin >> input; // get user choice of 10 or 13 isbn
	if (input % 10 == 0)
	{
		isbn10(); // if user enters 10 go to the isbn10 function
	}
	else if (input % 13 == 0)
	{
		isbn13(); // if user enters 13 go to the isbn13 function

	}
	else
	{
		cout << "Please write 10 or 13 for specific isbns" << endl;
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

	long long input; //needs to be a long long because 13 digits dont fit on a long or int 
	cout << "Please input the first 9 digits of the 10 digit isbn. " << endl;	
	cin >> input;//holds 9 digit user input
		
	int total = 0;
	int i = 2; // multiplier
	int remainder;
	int temp;
	string if10;
	//check if input is 9 digits long
	if (num_digits(input) != 9){
		while (num_digits(input) != 9){
			cout << "Please input the first 9 digits of the 10 digit isbn. " << endl;	
			cin >> input;
		}
	}
	long long original = input;//unchanged 9 digit user input has to be after check
	//checksum to find 10th digit
	while (input > 0){
		remainder = input % 10;	//get current right most digit
		total = total + (remainder * i); //multiply current right most digit by the counter
		input = (long long)input / 10;	//get rid of last digit that we already looked at
		i++;
	}
	temp = 11 - (total % 11);//makes final isbn a multiple of 11 by subtracting the functions totals right most digit from 11 to append to the original isbn given

	//if 10 print X otherwise print the checksum number
	if (temp == 10){
		if10 = "X";
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
	long long input;
	int i = 3;	//start multiple at 3
	int total = 0;
	int remainder;
	int temp;
	cin >> input; 	//holds 12 digit user input
	if (num_digits(input) != 12){ 	//if input doesnt have 12 digits ask again
		while (num_digits(input) != 12){
			cout << "Please input the first 12 digits of the 13 digit isbn. " << endl;	
			cin >> input;
		}
	}
	long long original = input;	//unchanged 12 digit user input has to be after check
		
	//checksum to find 13th digit
	while (input > 0){
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
	}
	temp = 10 - (total % 10);	//subtract 10 by the remainder of the ending function to make the entire isbn divisible by 10
	cout << "\n13 digit isbn = " << original << temp << endl;
}


/****************************************************************
 ** Function: num_digits
 ** Description: calculates the amount of digits of an inputted number
 ** Parameters: a long long input
 ** Pre-Conditions: Already asked user for a number and passed it
 ** Post-Conditions: N/A
 ** Return: The amount of digits in the passed number
 *****************************************************************/
int num_digits(long long input){

	int i = 0;//counter
	/* 
	 * This does not count 0 as a digit *
	 *
	 for (i=0; input > 0; i++){
	 input /= 10;
	 }
	 */

	//counts each digit including 0
	do {
		input = input / 10;
		i++;
	} while (input != 0);



	return i;
}
