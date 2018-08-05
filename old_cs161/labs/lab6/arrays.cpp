#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int menu(){
	int input;
	cout << "(1) Merge arrays"<< endl;
	cout << "(2) reverse array"<< endl;
	cout << "(3) reverse arrays with less functions" << endl;
	cout << "(4) convert input to string" << endl;
	cout << "(5) exit"<<endl;
	cin >> input;
	if (input == 1)
		return 1;
	else if (input == 2)
		return 2;
	else if (input == 3)
		return 3;
	else if (input == 4)
		return 4;
	else 
		return 0;
}
void print_array (int array[], int size) {
	for (int i=0; i<size; i++)
		cout << array[i] << " ";
	cout <<endl;
}
int fill_array(int array[],int size){
	cout << "fill in 5 numbers of this array" << endl;
	int i = 0;
	while (i <size){
		cin >> array[i];
		i++;
	}
	return i;
}
void reverse_array_with_output(int array[], int size){
	int temp_array[size];
	int i2 = size;
	for (int i =0; i < size; i++){
		temp_array[i] = array[i2-1];
		i2--;
	}

	for (int i=0;i<size;i++){
		array[i] = temp_array[i];
	}

	for (int i =0; i<size;i++)
		cout << array[i] << " ";
	cout << endl;
}
void reverse_array(int array[], int size){
	int temp_array[size];
	int i2 = size;
	for (int i =0; i < size; i++){
		temp_array[i] = array[i2-1];
		i2--;
	}

	for (int i=0;i<size;i++){
		array[i] = temp_array[i];
	}

}
void program2(){
	int array[5];
	fill_array(array, 5);	
	reverse_array(array, 5);
	print_array(array,5);




}
void program3(){
	int array[5];
	fill_array(array,5);
	reverse_array_with_output(array,5);




}
void program4(int argc, char* argv[]){

	//char arg1 = "-c1";
	//char arg2 = "-c2";
	char temp1[] = "-c1";
	char temp2[] = "-c2";
	//temp1 = &arg1;
	//temp2 = &arg2;
	float my_float = 0;
	int my_int = 0;
	int i = 1;
	if (strcmp(argv[i],temp1)==0){
		my_int = atoi(argv[i+1]);
		cout<< my_int << endl;
	}
	else if (strcmp(argv[i], temp2)==0){
		my_float = atof(argv [i+1]);
		cout << my_float << endl;
	}

}


void merge_array(int merged_array[], int array1[], int array2[], int size, int array1size, int array2size){
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	while ((i1 < array1size) && (i2 < array2size)){
		if (array1[i1] < array2[i2]){
			merged_array[i3] = array1[i1];
			i1++;
		}
		else{
			merged_array[i3] = array2[i2];
			i2++;
		}
		i3++;
	}	
	while (i1 < array1size){
		merged_array[i3] = array1[i1];
		i1++;
		i3++;
	}
	while (i2 < array2size){
		merged_array[i3] = array2[i2];
		i2++;
		i3++;
	}


}
int main (int argc, char* argv[])
{

	if (argc > 1){
		program4(argc, argv);
	}	
	else{
		int input = 0;
		input = menu();
		if (input == 0){
			return 0;
		}
		else if (input == 1){
			int array1size = 0;
			int array2size = 0;
			int array1[5];
			array1size = fill_array(array1,5);
			sort(array1, array1 + array1size);
			print_array(array1,5);
			int array2[5];
			array2size = fill_array(array2,5);
			sort(array2, array2 + array2size);
			print_array(array2,5);
			int merged_array[10];
			merge_array(merged_array, array1, array2, 10, array1size, array2size);
			print_array(merged_array, 10);

		}
		else if (input == 2) {
			program2();
		}
		else if (input == 3) {
			program3();
		}
		else
			return 0;
	}
}	
















