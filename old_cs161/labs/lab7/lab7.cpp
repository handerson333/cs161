#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
const int array_size = 5;
//prototypes

void sort(int a[], int n);
void print_array(int array, int size);
float average(int argc,char *argv); 
void printTable(int start, int end);
int median(int d[], int M);
void program1(int argc,char *argv[]);
void program2(int argc,char* argv[]);
void program3();
void fill_array(int array[]);
//main function
int main(int argc, char *argv[]){
	char temp1[] = "-avg";
	char temp2[] = "-med";	
	if (argc>2){	
		if (strcmp(argv[1],temp1) == 0){
			program1(argc, argv);
			return 0;
		}
		else if (strcmp(argv[1],temp2)==0){
			program2(argc,argv);
			return 0;
		}
	}
	if (argc <= 2){
		program3();
	}
	else
		cout << "incorrect input" << endl;
}
// process

float average(int argc,char *argv[]){
	int sum = 0;
	int temp = 0;
	for (int i=2;i<7;i++){
		temp = atof(argv[i]);
		sum = sum +temp;

	}
	return sum/array_size;
}

void program1(int argc,char *argv[]){
	if (argc < 7){
		cout<< "too few arguments"<< endl;
	}	
	else if (argc > 7){
		cout << "too many arguments" << endl;
	}
	else if (argc == 7){
		float avg = average(argc, argv);
		cout << avg << endl;
	}
	else{
		cout << "incorrect input" << endl;
	}
}
void program2(int argc,char* argv[]){
	int array[5];
	int i= 0;
	int j=2;
	while (i<5){
		array[i] = atoi(argv[j]);
		i++;
		j++;
	}
	sort(array,i);
	cout << "the median is " << array[(i/2)]<< endl;



}
void sort(int a[],int n){ // code received from 'C++ Early Objects 8th Edition' pg. 607
	int temp;
	bool swap;
	do{
		swap = false;
		for (int i = 0; i < n-1; i++){
			if (a[i] > a[i+1]){
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				swap = true;
			}
		}
	}
	while (swap);

}
void program3(){
	/*	int size;
		cout << "enter size of array collumn: ";
		cin >> size;
		cout << "fill x values with integers!" << endl;
		int array[size+1][size+1];
		array[0][0] = 0;
		int dat;
		for(int i = 1; i < size; i++){ 
		cin >> dat;
		array = dat;
		}
		cout << "fill y values with integers!" << endl;
		int fat;
		for(int i = 1; i < size; i++){ 

		cin >> fat;
		= fat;
		}
		int nNumRows;
		int temp1;
		cin >> temp1;
		nNumRows = temp1 +1;
		cout << "how many collumns?" << endl;
		int nNumCols;
		int temp2;
		cin >> temp2;
		nNumCols = temp2 +1;
		int nProduct[nNumRows ][nNumCols ];

		for (int nRow = 0; nRow < nNumRows; nRow++)
		for (int nCol = 0; nCol < nNumCols; nCol++)
		nProduct[nRow][nCol] = nRow * nCol;

		for (int i =1; i<nNumCols;i++)
		cout<< "X\t";
		cout<<endl;
		for (int nRow = 1; nRow < nNumRows; nRow++)
		{
		for (int nCol = 1; nCol < nNumCols; nCol++)
		cout<< nProduct[nRow][nCol] << "\t";

		cout << endl;
		}
		*/




	int start;
	int end;
	cout << "Enter a starting value" << endl;
	cin >> start;
	cout << "Enter an ending value" << endl;
	cin >> end;
	for (int i = start; i <= end; i++) {
		if (i == start) {
			printTable(start, end);
		}
		for (int j = start; j <= end; j++) {
			if (j == start) {
				cout << setw(3)<<  i << "|";
			}
			cout << setw(3) << (i * j) << " ";
		}
		cout << endl;
	}

	cout << endl;







}
void printTable(int start, int end) {
	//Print lead space and then numbers from start to end
	cout << setw(4) << " ";
	for (int firstrow = start; firstrow <= end; firstrow++) { 
		cout << setw(3) << firstrow << " ";
	}
	cout << endl;
	// Second line, lead space then proper number of dashes
	cout << setw(4) << " ";
	for (int secondrow = start; secondrow <= end; secondrow++) { 
		cout << " -- ";
	}
	cout << endl;
}


