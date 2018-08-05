#include <iostream>
#define PROMPT "Please enter a whole number:"
#define NOT_PRIME "The number is not a prime number."
#define PRIME "The number is a prime number."
#define DONE 0 /* ends successful program */
#define FIRST_FACTOR 2 /* initial value in for loop */
using namespace std;
void isPrime();


int main()
{
	int i=0; /* loop counter */
	int  number=0; /* number provided by user */
	cout << PROMPT << endl;; /* promt user */
	cin >> number; /* wait for user input */
	/* Prime numbers are defined as any number
	 *  * greater than one that is only divisible
	 *   * by one and itself. Dividing the number
	 *    * by two shortens the time it takes to
	 *     * complete. */
	if (number == 1 || number == 2 || number == 3){
		cout << PRIME << endl;
		return 0;
	}
	if(number % 2 == 0 || number % 3 == 0){
		cout << NOT_PRIME << endl;
		return 0;
	}
	for ( int i = 5; i*i <= number; i += 6)
	{
		if (number % i == 0 || number % (i+2) == 0)
		{
			cout << NOT_PRIME << endl;
			return 0;
		}
	}	

	cout << PRIME << endl;
	return 0; /* exit program */
}


