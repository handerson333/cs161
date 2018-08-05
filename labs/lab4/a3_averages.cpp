#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctype.h>

using namespace std;
bool check_input(string input);

float lab_average(int num_iterations);


int main(){
   int lab_num = 3;
   float lab = lab_average(lab_num);
   cout << "lab average: " << lab << endl;

   return 0;
}


float lab_average(int num_iterations){
   int i = 1;
   int score = 0;
   int possible = 0;
   string input;
   int temp;
   for (num_iterations; num_iterations > 0; num_iterations--){
      cout << "For lab " << i << " what was your score?" << endl;
      cin >> input;
      check_input(input);
      temp = atoi(input.c_str());
      score += temp;

      cout << "For lab " << i << " what was the highest possible score?" << endl;
      cin >> input;
      check_input(input);
      temp = atoi(input.c_str());
      possible += temp;
      i++;

   }
   cout << "Total Score :  " << score<< endl;
   cout << "Total possible Score :  " << possible<< endl;

   return (float)score/possible;

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
