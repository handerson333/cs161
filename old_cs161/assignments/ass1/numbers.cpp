//This program prints the max and minimum of basic types
#include <iostream>
#include <ctime>
#include <climits>
#include <cfloat>
using namespace std;

int main (){

	cout << sizeof (int) << endl;
	cout << sizeof (float) << endl;
	cout << sizeof (bool) << endl;
	cout << sizeof (short) << endl;
	cout << sizeof (long) << endl;
	cout << sizeof (double) << endl;
	cout << sizeof (char) << endl;

	double minShort  = SHRT_MIN;
	minShort - 1;
	cout << sizeof (minShort)  << endl;

	double maxShort = SHRT_MAX;
	maxShort + 1;
	cout << sizeof (maxShort) << endl;
	
	double minLong = LONG_MIN;
	minLong - 1;
	cout << sizeof (minLong) << endl;

	double maxLong = LONG_MAX;
	maxLong +1;
	cout << sizeof (maxLong) << endl;

	double minInt = INT_MIN;
	minInt - 1;
	cout << sizeof(minInt) << endl;

	double maxInt = INT_MAX;
	maxInt + 1;
	cout << sizeof(maxInt) << endl;


}


