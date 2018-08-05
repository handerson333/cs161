/****************************************************************
 ** Program Filename: binary_to_decimal.cpp
 ** Author: R. Hayden Anderson
 ** Date: 9/27/16
 ** Description: converts a 4 bit binary number into decimal
 ** Input: 4 bit binary number
 ** Output: the 4 bit binary into decimal
 *****************************************************************/
#include <iostream>


using namespace std;

int main (){
	cout << "\nPlease enter a 4 bit binary number" << endl;
	int remainder;				//holds remainder after modulo
	int input;				//takes original input
	int output = 0;				//running total for the conversion (starts at 0)

	cin >> input;				//gets 4 bit number from user

	/* First iteration, check 4 bit number for the right most bit */
	remainder = input % 10; 		//checks the "1's" place for a present bit
	output = remainder; 			//adds the 1's place to the running total
	input = (int)input/10; 			//no longer need 1's place and divides it away

	/* Second iteration, check 4 bit number for the bit representing 2 */
	remainder = input % 10;			//checks the 2's place for a present bit
	output = output + (remainder * 2);	//adds the 2's place bit if present
	input = (int)input /10;			//divides away the 2's place

	/* Third iteration, check 4 bit number for the bit representing 4 */
	remainder = input % 10;			//checks the 4's place bit for a present bit
	output = output + (remainder * 4);	//adds 4 to running total if present
	input = (int)input /10;			//divides the 4's place bit away

	/* Fourth iteration, check 4 bit number for the bit representing 8 */
	remainder = input % 10;			//checks for bit in the 8's bit slot
	output = output + (remainder * 8);	//adds 8 to running total if bit is present


	/*print decimal number*/
	cout << "decimal: " <<  output << endl;


	return 0;
}
