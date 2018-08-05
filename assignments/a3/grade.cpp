/****************************************************************
 ** Program Filename: grade.cpp
 ** Author: R. Hayden Anderson
 ** Date: 10/22/16
 ** Description:  Calculates the grade in a cs161 class after all the information needed is entered
 ** Input: none
 ** Output: the grade of the individual
 *****************************************************************/
#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
int get_num();
bool is_final();
void get_recitation_weights(float &quiz, float &critiques, float &designs, int quiz_num, int crit, int des);
int check_input(string input);
float average(int num_iterations, string category);
float weight(int num, string category);

int main(){
	//initialize variables
	string test_string = "test";
	string lab_string = "lab";
	string ass_string = "assignment";
	string rec_quiz_string = "recitation quiz";
	string rec_crit_string = "recitation critique";
	string rec_des_string = "recitation design";
	string final_string = "final";
	string recitation_string = "recitation";
	float recitation_quiz_weight = 0;
	float recitation_critique_weight = 0;
	float recitation_design_weight = 0;

	//ask general questions
	//and get the amount of each
	cout << "How many tests?" << endl;
	int num_tests = get_num();
	cout << "How many assignments?" << endl;
	int num_ass = get_num();
	cout << "How many labs?" << endl;
	int num_labs = get_num();
	cout << "How many recitation quizzes?" << endl;
	int num_rec_quiz = get_num();
	cout << "How many recitation critiques?" << endl;
	int num_rec_crit = get_num();
	cout << "How many recitation designs?" << endl;
	int num_rec_des = get_num();
	int num_final = 0;
	if (is_final())//if there is a final theres only one
		num_final = 1;
	cout << num_final << endl;

	//get averages/scores
	cout << endl;
	float test_average = average(num_tests, test_string);
	cout << "test average: " << test_average << endl;	
	float assignment_average = average(num_ass, ass_string);
	cout << "assignment average: " << assignment_average << endl;	
	float lab_average = average(num_labs, lab_string);
	cout << "lab average: " << lab_average << endl;	
	float rec_des_average = average(num_rec_des, rec_des_string);
	cout << "rec des average: " << rec_des_average << endl;	
	float rec_crit_average = average(num_rec_crit, rec_crit_string);
	cout << "rec crit average: " << rec_crit_average << endl;	
	float rec_quiz_average = average(num_rec_quiz, rec_des_string);
	cout << "rec quiz average: " << rec_quiz_average << endl;	
	float final_average = average(num_final, final_string);
	cout << "final average: " << final_average << endl;	

	//get weights
	cout << endl;
	//recitation weights with pass by reference
	get_recitation_weights(recitation_quiz_weight, recitation_critique_weight, recitation_design_weight, num_rec_quiz, num_rec_crit, num_rec_des);

	//rest of weights
	float test_weight = 0;
	test_weight = weight(num_tests, test_string);
	float lab_weight = 0;
	lab_weight = weight(num_labs, lab_string);
	float assignment_weight = 0;
	assignment_weight = weight(num_ass, ass_string);
	float final_weight = 0;

	//make the recitation weights all add up to 100%
	float recitation_weight = 0;
	float coef = (1/(recitation_quiz_weight + recitation_design_weight + recitation_critique_weight));
	recitation_quiz_weight *= coef;
	recitation_design_weight *= coef;
	recitation_critique_weight *= coef;
	recitation_weight = weight((num_rec_des + num_rec_quiz + num_rec_crit), recitation_string);
	//make ALL the weights add up to 100%
	coef = (1/(recitation_weight + lab_weight + assignment_weight + test_weight + final_weight));
	recitation_weight *= coef;
	lab_weight *= coef;
	assignment_weight *= coef;
	test_weight *= coef;
	final_weight *= coef;
	//final scores
	//weight times the each of their (individual weights times their averages)
	float recitation_score = (recitation_weight*((rec_des_average*recitation_design_weight) + (rec_crit_average*recitation_critique_weight) + (recitation_quiz_weight*rec_quiz_average)));
	//each section average times their weights and added together
	float score = ((test_weight*test_average) + (assignment_weight*assignment_average) + (lab_weight*lab_average) +  (final_weight*final_average) + recitation_score);
	cout << "\nyour grade in the class is: " << 100*score << "%" << endl;
	return 0;
}
/****************************************************************
 ** Function: weight
 ** Description: asks user for the weight of a category
 ** Parameters: an int making sure there are at least 1 of the category that needs the weight
 ** Pre-Conditions: passed int > 0 for this to take effect
 ** Post-Conditions: none
 ** Return: an entered percentage
 *****************************************************************/
float weight(int num, string category){
	int i = 1;
	if (num > 0){
		cout << "What is the weight for the " << category << "s as a whole number?" << endl;
		string input;
		cin >> input;
		float output = check_input(input);
		return output/100;
		i++;
	}
}
/****************************************************************
 ** Function: average
 ** Description: asks user for the score and highest possible score for a passed number of iterations
 ** Parameters: the number of iteratioons ytou want as an int and a string that has the subject you need the score of
 ** Pre-Conditions: you have a number of iterations already
 ** Post-Conditions: none
 ** Return: returns the average score as a float
 *****************************************************************/
float average(int num_iterations, string category){
	int i = 1;
	int score = 0;
	int possible = 0;
	string input;
	int temp;
	if (num_iterations == 0){
		return 0;
	}
	for (num_iterations; num_iterations > 0; num_iterations--){

		cout << "For " << category << " " << i << " what was your score?" << endl;
		cin >> input;
		temp = check_input(input);
		score += temp;
		cout << "For " << category << " " << i << " what was the highest possible score?" << endl;
		cin >> input;
		temp = check_input(input);
		possible += temp;
		i++;
	}
	cout << "Total Score :  " << score<< endl;
	cout << "Total possible Score :  " << possible << "\n\n" <<  endl;
	return (float)score/possible;
}
/****************************************************************
 ** Function: get recitation weights
 ** Description: asks user for the weights of the three different recitation sections if there are any and changes their weights at their address
 ** Parameters: 3 floats for storage of each section, 3 ints that represent the amount of each section
 ** Pre-Conditions: you have 3 floats you need a percentage for and 3 ints that represent the amount of percentages needed
 ** Post-Conditions: the three floats are now percentages
 ** Return: none
 *****************************************************************/
void get_recitation_weights(float &quiz, float &critiques, float &designs, int quiz_num, int crit, int des){
	string input;
	if (quiz_num != 0){
		cout << "what is the weight of recitation quizzes?" << endl;
		string input;
		cin >> input;
		quiz = (float)check_input(input)/100;
	}
	if (crit != 0){
		cout << "what is the weight of recitation critiques?" << endl;
		string input;
		cin >> input;
		critiques = (float)check_input(input)/100;

	}
	if (des != 0){
		cout << "what is the weight of recitation designs" << endl;
		cin >> input;
		designs = (float)check_input(input)/100;
	}
}
/****************************************************************
 ** Function: get num
 ** Description: gets a number and makes sure it is a positive integer
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ** Return: returns that number as an int
 *****************************************************************/
int get_num(){
	string input;
	cin >> input;
	int num = check_input(input);
	return num;
}
/****************************************************************
 ** Function: is final
 ** Description: asks user if there is a final
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns 
 ** Return: the answer
 *****************************************************************/
bool is_final(){
	cout << "Is there a final? yes(1) no(0)" << endl;
	string input;
	cin >> input;
	int answer = check_input(input); 
	return answer;
}

/****************************************************************
 ** Function: check input
 ** Description: forces user to input a positive integer
 ** Parameters: an input
 ** Pre-Conditions: already requested an original input as a string
 ** Post-Conditions: none
 ** Return: the final positive as an integer
 *****************************************************************/
int check_input(string input){
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
	num = atoi(input.c_str());
	return num;
}


