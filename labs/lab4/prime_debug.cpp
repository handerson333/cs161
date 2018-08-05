#include <iostream>
#define PROMPT "Please enter a whole number:"
#define NOT_PRIME "This number is not a prime number. "
#define PRIME "This number is a prime number. "
#define DONE 0 /* ends successful program */
#define FIRST_FACTOR 5 /* initial value in for loop */
using std::cout;
using std::cin;
using std::endl;
int main(){
	int i = FIRST_FACTOR; /* loop counter */
	int number; /* number provided by user */
	cout << PROMPT; /* promt user */
	cin >> number; /* wait for user input */
	/* * Prime numbers are defined as any number
	 * * greater than one that is only divisible
	 * * by one and itself. Dividing the number
	 * * by two shortens the time it takes to
	 * * complete. */
	if (number == 1 || number == 2 || number == 3){
		cout << PRIME << endl;
		return 0;
	}
	if(number % 2 == 0 || number % 3 == 0){ /* if divisible */
		cout << NOT_PRIME << endl;
		return 0;
	}
	for (i; i*i <= number; i += 6)
	{
		if (number % i == 0 || number % (i + 2) == 0)
		{
			cout << NOT_PRIME << endl;
			return 0; /* exit program */
		}
	}	
	/* if number is not divisible by anything
	 * * than it must be prime */
	cout << PRIME << endl;
	return 0; /* exit program */
}

