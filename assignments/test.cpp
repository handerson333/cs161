#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string fix(string str1);

int main(){
	cout << "enter a string" << endl;
	string input1 = "what";
	string input2;

	getline(cin, input1);


	input2 = fix(input1);

	cout << "string1:" << input1 << endl;
	cout << "string2:" << input2 << endl;



	return 0;
}

string fix(string str1){
	string str2 = "";
	int i = (str1.length());
	int j = 0;
	while (i >= 0){
		cout << str1[j] << endl;
	i--;
	j++;
	}

return str2;
}
