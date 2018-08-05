#include <iostream>	
using namespace std;
int draw_box(int N);	
int draw_top_bottom(int N);	
int draw_sides(int N);
int triangle1(int N);
int triangle2(int N);
int diamond(int N, char symbol);

int main(){
	int patternInput;
	int N=0;
	char symbol;
	cout << "Pick a pattern" << endl;
	cout << "(1) box" << endl;
	cout << "(2) triangle 1" << endl;
	cout << "(3) triangle 2" << endl; 
	cout << "(4) diamond" << endl;
	cout << "(5) exit" << endl;
	cin >> patternInput;
	cout << "how large? (1-10)" << endl;
	cin >> N;

	cout << " " << endl;
	if (patternInput == 1){
		draw_box(N);	
	}
	else if (patternInput == 2){
		triangle1(N);
	}
	else if (patternInput == 3){
		triangle2(N);
	}
	else if (patternInput == 4){
	cout << "What symbol would you like to use for your diamond?" << endl;
	cin >> symbol;
		diamond(N,symbol);
	}
	else{
		return 0;}
	return	0;	
}	

int diamond(int N, char symbol){

	int spaces_amount = N/2 ;
	char space 
	for (int row = 1; row <= N; row++)	

	








}

int triangle2(int N){

cout << 7/2 << endl;

	for (int row =1 ; row<= N; row ++){
		int i = 1;
		while (i <= row){
			cout << i;
			i++;
		}	
		cout << endl;
	}
}











int triangle1(int N){	
	for (int row = 1; row <=  N; row++){

		for (int collumn = 1; collumn < row; collumn ++){
			cout << row;
		}
		cout << row<< endl;
	}
}






int draw_box(int N){	
	draw_top_bottom(N);	
	for (int times =0; times < N; times++){
		draw_sides(N);	
	}
	draw_top_bottom(N);	
}	
int draw_top_bottom(int N){

	cout << "+";
	for (int dashes =0; dashes < N;dashes++){
		cout << "-" ;
	}	
	cout <<"+" << endl;	
}	
int draw_sides(int N){

	cout << "|" ;	
	for (int spaces = 0; spaces < N; spaces ++){
		cout << " " ;
	}
	cout << "|"<< endl;
}

