/****************************************************************
 ** Program Filename: bits.cpp
 ** Author: R. Hayden Anderson
 ** Date: 9/27/16
 ** Description: Prints out library macros of INT_MIN,INT_MAX, and UINT_MAX.  Then asks user for an amount of bits and aprints out the signed min,max and unsigned max of the amount of bits.
 ** Input: amount of bits (long)
 ** Output: Macros and amount of bits
 *****************************************************************/
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main(){
	/*Prints out macros from the climits library*/	
	cout << "\nLibrary signed int min is: " << INT_MIN << endl; 		//shows min length of a signed int
	cout << "Library signed int max is: " << INT_MAX << endl; 		//shows max length of signed int
	cout << "Library unsigned max is: " << UINT_MAX << endl;  		//shows max length of unsigned int


	long bit_input; 							//input for bits
	cout << "\nHow many bits?" << endl;
	cin >> bit_input; 
	while (bit_input % 8 != 0) 						//loops until user inputs a number divisible by 8
	{
		cout << "write a number divisible by 8" << endl;
		cin >> bit_input;	
	}
	long smax = ((pow(2, bit_input)/2 ) - 1); 				//((2^n)/2)-1 formula for signed max
	long smin = (-1 * ((pow(2, bit_input))/2)); 				//(-(2^n)/2) formula for signed min
	unsigned long umax = (pow(2, bit_input) - 1); 				//(2^n)-1 formula for unsigned max
	cout << "signed min of " << bit_input << " bits is: " << smin << endl;  //prints signed min of number of bits inputted
	cout << "signed max of " << bit_input << " bits is: " << smax << endl;  //prints signed max of number of bits inputted
	cout << "unsigned max of " << bit_input << " bits is: " << umax << endl << endl;//prints unsigned max of number of bits inputted


	return 0;
}


