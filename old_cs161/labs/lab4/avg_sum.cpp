#include <iostream>
using namespace std;

int main(){
	int input=0;
	int avg;
	int sum = 0;
	cout << "you give me positive numbers, Ill give you the sum and average of them." << endl;
	cout << "when done, enter -1" << endl;
	int i = 0;
	while (input >= 0){ 
		cin >> input;

		if (input>=0){
			i +=1;
			sum += input ;
		}
	}

	avg = sum / i;
	cout << "the sum is " << sum << endl;
	cout << "the average is " << avg << endl;











}
