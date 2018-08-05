#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int *way1();
int& way2();
void way3(int *&p3);


int main(){
	int value = 5;
	int *pointer=&value;
	int *p2 = NULL;
	int *p3 = NULL;

	cout << "pointer address: " << pointer << endl;
	cout << "pointer contents: " << *pointer << endl;
	
	pointer = way1();
	*pointer = 1;	
	cout << *pointer << endl;
	delete pointer;
	
	p2 = &way2();
	*p2 = 2;
	cout << *p2 << endl;
	delete p2;


	way3(p3);
	cout << *p3 << endl;
	delete p3;

	return 0;
}

int *way1(){
return new int;

}
int &way2(){
return *new int;

}
void way3(int *&p3){
p3 = new int;
*p3 = 3;

}

