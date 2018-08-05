#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;
void dynamic_mult(int rows, int cols);
void dynamic_div(int rows, int cols);
void static_mult(int rows, int cols);
void static_div(int rows, int cols);

int main(int argc, char *argv[]){
	int rows = atoi(argv[1]), cols = atoi(argv[2]);

	//dynamic mult
	cout << "dynamic_mult" << endl;
	dynamic_mult(rows,cols);
	cout <<"\n";

	//dynamic div
	cout << "dynamic_div" << endl;
	dynamic_div(rows,cols);
	cout <<"\n";

	//static mult
	cout << "static_mult" << endl;
	static_mult(rows,cols);
	cout <<"\n";

	//static div
	cout << "static_div" << endl;
	static_div(rows,cols);
	cout <<"\n";




}
//dynamic mult
void dynamic_mult(int rows, int cols){

	int **table = new int*[rows];//pointer to pointers
	for (int i = 0; i < rows; ++i){
		table[i] = new int[cols];//pointer to info
	}

	for (int i=0; i<rows; i++){

		for (int j = 0; j<cols; j++)
		{
			table[i][j] = ((i+1)*(j+1));
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i< rows; i++){
		delete [] table[i];
	}
	delete [] table;


}
//dynamic div
void dynamic_div(int rows, int cols){
	float**table = new float*[rows];//pointer to pointers
	for (int i = 0; i < rows; ++i){
		table[i] = new float[cols];//pointer to info
	}


	for (int i=0; i<rows; i++){

		for (int j = 0; j<cols; j++)
		{
			table[i][j] = ((float)(i+1)/(float)(j+1));
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i< rows; i++){
		delete [] table[i];
	}
	delete [] table;


}
//static mult
void static_mult(int rows, int cols){

	float table[rows][cols];
	for (int i=0; i<rows; i++){

		for (int j = 0; j<cols; j++)
		{
			table[i][j] = ((i+1)*(j+1));
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}
}
//static div
void static_div(int rows, int cols){
	float table[rows][cols];

	for (int i=0; i<rows; i++){
		for (int j = 0; j<cols; j++)
		{
			table[i][j] = ((float)(i+1)/(float)(j+1));
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}
}

