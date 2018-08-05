#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
srand(time(NULL));
	cout << "enter in rows and cols" << endl;
string rows,cols;
cin >> rows;
cin >> cols;
cout << "rows: " << rows << endl;
cout << "cols: " << cols << endl;
cout << (rand() % atoi(rows.c_str())) << endl;
return 0;
}
