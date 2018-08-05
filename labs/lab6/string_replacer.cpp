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

void get_string(string &);
void get_search_replace_strings(string*,string*);
int search_replace(string &, string, string);



int main(){
	string input;
	string search;
	string replace;
	get_string(input);
	get_search_replace_strings(&search, &replace);
	int times = search_replace(input, search, replace);
	cout << "You made 1 replacement, and your new string is: " << input << endl;
}


void get_string(string &input){
	cout << "Enter your string: " << endl;
	getline(cin, input);

}
void get_search_replace_strings(string *search, string *replace){
	cout << "Enter a search string: " << endl;
	getline(cin, *search);
	cout << "Enter the replacement: " << endl;
	getline(cin, *replace);


}
//name: search_replace
//description: replaces an inputted part of an inputted string with an inputted string
//parameters:an original full sentence, a string that is part of that original sentence, and what to replace
//that selected string with
//input: 3 strings
//output: 
int search_replace(string &input, string search, string replace){
	int size = input.find(search);
	input.replace(input.find(search), search.length(), replace);
	
	return 1;
}


