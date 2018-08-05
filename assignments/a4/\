#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <wctype.h>
#include <algorithm>
using namespace std;
string reverse(string s);
void palindrome();
void string_reversal();
bool determine_palindrome(string *sentence, int length);

int main(){
	while (1){
		cout << "Do you want to palindrome (1), reverse string (2), or stop the program (anythign else)" << endl;
		int answer = 0;
		cin >> answer;
		if (answer == 1){
			palindrome();
		}
		else if(answer == 2){
			string_reversal();
		}
		else
			break;
	}
	return 0;
}


void palindrome(){
	string sentence;
	cout << "enter string to check if it's a palindrome: " << endl;
	cin.ignore();      
	getline(cin, sentence);
	string fixed;
	for(int i =0; i<sentence.length();i++){
		if (isalnum(sentence[i])){
			fixed += sentence.substr(sentence[i];
					}

					}
					if (sentence == string(sentence.rbegin(),sentence.rend())){
					cout << sentence << ": is a palindrome!" << endl;
					}
					else{
					cout << sentence << ": is not a palindrome!" << endl;
					}
					}


					void string_reversal(){
					string sentence;
					cout << "enter string to reverse: " << endl;
					cin.ignore();      
					getline(cin, sentence);
					string reversed_string = reverse(sentence);
					cout << "reversed string: " << reversed_string << endl;
					}

/*********************************************************************
 * ** Function: reverse
 * ** Description: reverses an inputed line
 * ** Parameters: a string
 * ** Pre-Conditions: The user inputs for program 3 and enters a sentence.
 * ** Post-Conditions: reverses the inputed sentence
 * *********************************************************************/ 
string reverse(string s){
	if (s.length() <= 1){ //check if string is has any length
		return s;
	}
	else{
		string reversed = reverse(s.substr(1, s.length())) + s[0]; //continuously calls reverse until substring reaches the end of the string, then as it ends each sub-iteration of the reverse() print out the first character
		return reversed;	
	}
}

void fix_sentence(string &sentence){
	int i = 0;
	while (i > sentence.length()){
		if (!(isalnum(sentence[i]))){ 
			replace(sentence.begin(), sentence.end(), sentence[i], ' '); 
		}
		i++;
	}
	i = 0;
	while (i < sentence.length()){
		char c = sentence[i];
		putchar(tolower(c));

		i++;
	}
}
