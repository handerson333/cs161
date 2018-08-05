#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <wctype.h>
#include <algorithm>
using namespace std;

void get_string(char *);
void get_search_replace_strings(char *,char *);
int search_replace(char *, char *, char *);
void print(char *array);
//char &way3(int amount);

int main(){
	cout << "how many characters would you like to make?" << endl;
	int amount = 20;
	cin >> amount;
	char sentence[256];
	char search[256];
	char replace[256];
	cin.ignore();	
	//way3(sentence,amount);
	get_string(sentence);
	get_search_replace_strings(search,replace);
	cout << "sentence: ";
	print(sentence);
	cout << "search: ";
	print(search);
	cout << "replace: ";
	print(replace);	
	int times = search_replace(sentence, search, replace);
	cout << "New sentence: " << sentence<< endl;


}
void print(char* array){
	for(int i = 0; i<=strlen(array); i++){
		cout << array[i];
	}
	cout << endl;
}

void get_string(char *sentence){
	cout << "Enter your string: " << endl;
	cin.getline(sentence, 256);


}
void get_search_replace_strings(char *search,char* replace){
	cout << "Enter a search string: " << endl;
	cin.getline(search, 256);
	cout << "Enter the replacement: " << endl;
	cin.getline(replace, 256);


}
//name: search_replace
//description: replaces an inputted part of an input:ted string with an inputted string
//parameters:an original full sentence, a string that is part of that original sentence, and what to replace
//that selected string with
//input: 3 strings
//output: 
int search_replace(char* sentence,char* search,char* replace){
	string input = sentence;
	string search_string = search;
	string replacement = replace;

	int size = input.find(search_string);
	string sent = input.replace(input.find(search_string), search_string.length(), replacement);
	strcpy(sentence,sent.c_str());	
	return 1;




	return 1;
}

//char &way3( int amount){
//	return *new char[amount+1];
//}
