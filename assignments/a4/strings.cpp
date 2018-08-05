/*********************************************************************
** Program Filename: strings.cpp	
** Author: R. Hayden Anderson
** Date: 11/6/2016
** Description: palindrome or reverse string
** Input: N/A
** Output:N/A
*********************************************************************/
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
string reverse(string);


/*********************************************************************
** Function: main
** Description: checks if you want to do palindrome or string reversal.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: N/A
*********************************************************************/ 
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

/*********************************************************************
** Function: palindrome
** Description: checks if an inputted string is a palinrome
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: N/A
*********************************************************************/ 
void palindrome(){
	string sentence;
	cout << "enter string to check if it's a palindrome: " << endl;
	cin.ignore();      
	getline(cin, sentence);
	//gets rid of all special characters and spaces character by character and resizes the string
	//by checking with isalnum otherwise remove the character and add nothing
	sentence.resize(remove_if(sentence.begin(), sentence.end(),[](char x){return !isalnum(x);})-sentence.begin()); 
	if (sentence == string(sentence.rbegin(),sentence.rend())){ //easier way to reverse the string non-recursively...
		cout << sentence << ": is a palindrome!" << endl;
	}
	else{
		cout << sentence << ": is not a palindrome!" << endl;
	}
}

/*********************************************************************
** Function: string reversal
** Description: gets a string and prints out the string reversed
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
** Return: N/A
*********************************************************************/ 
void string_reversal(){
	string sentence;
	cout << "enter string to reverse: " << endl;
	cin.ignore();      
	getline(cin, sentence);
	string reversed_string = reverse(sentence);
	cout << "reversed string: " << reversed_string << endl;
}

/*********************************************************************
 ** Function: reverse
 ** Description: reverses an inputed line
 ** Parameters: a string
 ** Pre-Conditions: there is already a string.
 ** Post-Conditions: 
 ** Return: reversed of the inputed sentence
 *********************************************************************/ 
string reverse(string s){
	if (s.length() <= 1){ //check if string is has any length
		return s;
	}
	else{
		//continuously calls reverse until substring reaches the end of the string, then as it ends each sub-iteration of the reverse() print out the first character
		string reversed = reverse(s.substr(1, s.length())) + s[0]; 
		return reversed;	
	}
}

