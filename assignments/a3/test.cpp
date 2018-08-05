#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
int passed(string category);

int main(){

	string category = "tests ";
	string trying = "trying";
	int dude = passed(category);
	dude = passed(trying);
cout << dude << endl;



	return 0;
}

int passed(string category){

	cout << "category is " << category << endl; 

	return 1;
}

