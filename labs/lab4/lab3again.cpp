#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctype.h>
using namespace std;
bool check_input(string input);


int main(){
	srand(time(NULL));
	int x;
	string input;	
	x = rand() % 50;
	int i = 5;
	int checked;
	while (checked != x){
		cout << "guess a number between 0 and 50. " << i << " tries left." << endl;
		cin >> input;
		check_input(input);
		int num = atoi(input.c_str());

		checked = num;

		cout << endl;
		if (checked > x){
			cout << checked << " was too high. " << (i - 1) << " tries left." << endl;
		}
		else if (checked < x){
			cout << checked << " was too low. " << (i - 1) << " tries left." << endl;
		}
		else{
			cout << checked << " was correct! and in only " << (5 - i) << " tries!" << endl;
			break;
		}

		i--;
		if (i == 0){
			cout << "you failed..." << endl;
			break;
		}
	}
	return 0;
}

bool check_input(string input){
	int num;
	bool bad_input = true;
	while (bad_input){
		for (int i = 0; i < input.length(); i++){
			if (isdigit(input[i])){
				bad_input = false;
			}
			else
			{
				bad_input = true;
				cout << "that was bad input.  enter a good number" << endl;
				cin >> input;
				break;
			}
		}
	}

		return bad_input;
}


