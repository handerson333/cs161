#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	
	
	int num;
	double result; 
	srand(time(NULL));
	cout << "Please enter an integer" << endl;
	cin >> num;
	
	result = rand() % num + 1;
	cout << "The " <<  num << " sided die landed on " << result << "!"
	  << endl;
return 0;
}




