#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

void get_sentence(string &s);

int main (){
	string sentence;
	cout << "enter a string" << endl;
	get_sentence(sentence);
	cout << sentence << endl;

	return 0;
}

//preconditions: you have a string declared and passed to this function
//post conditions: that string is now the users input
void get_sentence(string &s){

	getline(cin, s);



}
