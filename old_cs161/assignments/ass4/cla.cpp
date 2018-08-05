/**********************************************************************
 * ** Program Filename: assignment4
 * ** Author: Robert Hayden Anderson
 * ** Date: 5/7/15
 * ** Description: finds area under curves using CLA
 * ** Input: starting point and ending point, which function, number of quadralaterals, which quadralateral to use
 * ** Output: the function used, start and end points , area calculated
 * *********************************************************************/



#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

// initializing functions
void function1(int argc, char* argv[], int shape, int x1, int x2, int num, float width);
void function2(int argc, char* argv[], int shape, int x1, int x2, int num, float width);
void function3(int argc, char* argv[],int shape, int x1, int x2, int num, float width);
void function4(int argc, char* argv[],int shape, int x1, int x2, int num, float width);
void function5(int argc, char* argv[],int shape, int x1, int x2, int num, float width);
int shape(int argc, char* argv[]);
float width(int x1, int x2, int num);
int firstX(int argc, char* argv[]);
int secondX(int argc, char* argv[]);
int number(int argc, char* argv[]);
int f(int argc, char* argv[]);

//main
int main(int argc, char* argv[]){
	int shp = shape(argc, argv);
	int x1 = firstX(argc, argv);
	int x2 = secondX(argc, argv);
	int num = number(argc, argv);
	int wid = width(x1,x2,num);
	int which_function = f(argc, argv);	
	if (which_function == 1){
		function1(argc, argv, shp, x1, x2, num, wid);
	}
	else if (which_function == 2){
		function2(argc, argv, shp, x1, x2, num, wid);
	}
	else if (which_function == 3){
		function3(argc, argv, shp, x1, x2, num, wid);
	}
	else if (which_function == 4){
		function4(argc, argv, shp, x1, x2, num, wid);
	}
	else if (which_function == 5){
		function5(argc, argv, shp, x1, x2, num, wid);
	}



}
//input functions
int shape(int argc, char* argv[]){
	for (int i = 1; i< argc; i++){
		char temp[] = "-s";
		char temp2[] = "-t";
		char temp3[] = "-r";
		if (strcmp(argv[i],temp) == 0){
			if (strcmp(argv[i+1], temp2) ==0){
				return 1;
			}
			else if (strcmp(argv[i+1], temp3) ==0){
				return 2;
			}

		}


	}
}
float width(int x1, int x2, int num){
	float wide =0;
	wide = ((x2-x1)/num);
	return wide;

}
int firstX(int argc, char* argv[]){
	int int_temp = 0;
	for (int i = 1; i <= argc; i++){
		char temp[] = "-x1";
		if (strcmp(argv[i], temp) == 0){
			int_temp = atoi(argv[i+1]);
			return int_temp;

		}
	}

}
int secondX(int argc, char* argv[]){
	int int_temp = 0;
	for (int i = 1; i <= argc; i++){
		char temp[] = "-x2";
		if (strcmp(argv[i], temp) == 0){
			int_temp = atoi(argv[i+1]);
			return int_temp;

		}
	}



}
int number(int argc, char* argv[]){

	int int_temp = 0;
	for (int i = 1; i <= argc; i++){
		char temp[] = "-n";
		if (strcmp(argv[i], temp) == 0){
			int_temp = atoi(argv[i+1]);
			return int_temp;

		}
	}


}
int f(int argc, char* argv[]){

	int int_temp = 0;
	for (int i = 1; i <= argc; i++){
		char temp[] = "-f";
		if (strcmp(argv[i], temp) == 0){
			int_temp = atoi(argv[i+1]);
			return int_temp;

		}
	}


}
// end functions




void function1(int argc, char* argv[], int shape, int x1, int x2, int num, float width){
	float h1;
	float h2;
	float y;
	float b;
	y=0;
	char *point;
	for (float i=x1; i<=(x2-width); i=(i+width)) {
		h1=((2*(pow(i,5)))+(pow(i,3)-(10*i)+2));
		b=(i+width);
		h2=((2*(pow(b,5)))+(pow(b,3)-(10*b)+2));
		if (shape == 1 || shape == 2){
			y=(y+(h1*width));
			if (shape == 2){
				y=(y+(((h1+h2)/2)*width));
				char quad[10] = "trapezoid";
				point = &quad[10];
			}
			else{	
				char quad[10] = "rectangle";
				point = &quad[10];
			}
		}
	}


	cout<<"The area under the curve for a "<< *point <<" using 2x^5 + x^3 - 10x + 2 is approximately "<<y<<endl;



}
void function2(int argc, char* argv[], int shape, int x1, int x2, int num, float width){
	float h1;
	float h2;
	float y;
	float b;
	y=0;
	char *point;


	for (float i=x1; i<=(x2-width); i=(i+width)) {
		h1=((6*(pow(i,2)))-i+10);
		b=(i+width);
		h2=((6*(pow(b,2)))-i+10);
		if (shape == 1 || shape == 2){
			y=(y+(h1*width));
			if (shape == 2){
				y=(y+(((h1+h2)/2)*width));
				char quad[10] = "trapezoid";
				point = &quad[10];
			}
			else{	
				char quad[10] = "rectangle";
				point = &quad[10];
			}
		}


	}


	cout<<"The area under the curve for a "<< *point <<" using 2x^5 + x^3 - 10x + 2 is approximately "<<y<<endl;





}
void function3(int argc, char* argv[],int shape, int x1, int x2, int num, float width){
	float h1;
	float h2;
	float y;
	float b;
	y=0;
	char *point;
	for (float i=x1; i<=(x2-width); i=(i+width)) {
		h1=((5*i)+3);
		b=(i+width);
		h2=((5*b)+3);

		if (shape == 1 || shape == 2){
			y=(y+(h1*width));
			if (shape == 2){
				y=(y+(((h1+h2)/2)*width));
				char quad[10] = "trapezoid";
				point = &quad[10];
			}
			else{	
				char quad[10] = "rectangle";
				point = &quad[10];
			}
		}
	}


	cout<<"The area under the curve for a "<< *point <<" using 2x^5 + x^3 - 10x + 2 is approximately "<<y<<endl;




}
void function4(int argc, char* argv[],int shape, int x1, int x2, int num, float width){
	float h1;
	float h2;
	float y;
	float b;
	y=0;
	char *point;
	for (float i=x1; i<=(x2-width); i=(i+width)) {
		h1=((2*(pow(i,3)))+120);
		b=(i+width);
		h2=((2*(pow(b,3)))+120);
		if (shape == 1 || shape == 2){
			y=(y+(h1*width));
			if (shape == 2){
				y=(y+(((h1+h2)/2)*width));
				char quad[10] = "trapezoid";
				point = &quad[10];
			}
			else{	
				char quad[10] = "rectangle";
				point = &quad[10];
			}
		}

	}


	cout<<"The area under the curve for a "<< *point <<" using 2x^5 + x^3 - 10x + 2 is approximately "<<y<<endl;

}
void function5(int argc, char* argv[],int shape, int x1, int x2, int num, float width){
	float h1;
	float h2;
	float y;
	float b;
	y=0;
	char *point;
	for (float i=x1; i<=(x2-width); i=(i+width)) {
		h1=((2*(pow(i,2))));
		b=(i+width);
		h2=((2*(pow(b,2))));
		if (shape == 1 || shape == 2){
			y=(y+(h1*width));
			if (shape == 2){
				y=(y+(((h1+h2)/2)*width));
				char quad[10] = "trapezoid";
				point = &quad[10];
			}
			else{	
				char quad[10] = "rectangle";
				point = &quad[10];
			}
		}
	}


	cout<<"The area under the curve for a "<< *point <<" using 2x^5 + x^3 - 10x + 2 is approximately "<<y<<endl;



}




