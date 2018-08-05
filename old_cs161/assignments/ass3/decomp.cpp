/********************************************************************
 ** Program Filename: 
 ** Author: R. Hayden Anderson
 ** Date: 4/25/15
 ** Description: This program gives the integral of 5 functions
 ** Input: which function, how they want to take the integral, amount of quadraletals they want to use, the starting point, and the ending point.
 ** Output:The area under the curve from the start point to the end point of chos	en function.
 *********************************************************************/
#include <iostream>
#include <cmath>
#define askFunction  "Choose a function (1,2,3,4,5,other(quit))"
#define askCalcHow   "Would you like to calculate the area using a rectangle(1), trapezoid(2)" 
#define askStartPoint "What is your starting point?"
#define askEndPoint "What is your ending point?"
#define actual_function1 "2x^5 + x^3 - 10x + 2"
#define actual_function2 "6x^2 -x + 10"
#define actual_function3 "5x + 3"
#define actual_function4 "2x^3 + 120"
#define actual_function5 "2x^2"
using namespace std;

//initializing functions
int inputFunction();
int inputCalcHow();
int inputQuadAmount(int calc);
int inputStartPoint();
int inputEndPoint();
int area_calc(int fNum, int how2Calc, int start, int end, int amount);
int output(int area,int fNum, int how2Calc, int start, int end, int amount);
int equation1(int fNum, int how2Calc, int start, int end, int amount); 
int equation2(int fNum, int how2Calc, int start, int end, int amount); 
int equation3(int fNum, int how2Calc, int start, int end, int amount); 
int equation4(int fNum, int how2Calc, int start, int end, int amount); 
int equation5(int fNum, int how2Calc, int start, int end, int amount); 






/*********************************************************************
 ** Function: main
 ** Description: executes all other functions to get inputs for final function
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions:none
 *********************************************************************/ 
int main(){
	int function_Num;
	int calcHow;
	int startPoint;
	int endPoint;
	int quadAmount;
	int area;
	function_Num = inputFunction();
	calcHow = inputCalcHow();
	startPoint = inputStartPoint();
	endPoint = inputEndPoint();



	quadAmount = inputQuadAmount(calcHow);
	area = area_calc(function_Num, calcHow, startPoint, endPoint, quadAmount); 
	output(area, quadAmount, endPoint, startPoint, calcHow, function_Num);

	return 0;
}








/*********************************************************************
 * ** Function: inputFunction
 * ** Description: asks and gets which function they want to use
 * ** Parameters:
 * ** Pre-Conditions:
 * ** Post-Conditions:
 * *********************************************************************/ 
int inputFunction(){
        int input = 0;
	cout << askFunction << endl;
	cin >> input;
	int i = 0;
	while (i=0){
		if (input == 1){
			return 1;
			i++;
		}
		else if (input == 2){
			return 2;
			i++;
		}
		else if (input == 3){
			return 3;
			i++;
		}
		else if (input == 4){
			return 4;
			i++;
		}
		else if (input == 5){
			return 0;
		}
		else
			return 0;
	}
}

int inputStartPoint(){
int input;
cout << "What value of x do you want to start at?" << endl;
cin >> input;

return input;

}



int inputEndPoint(){
int input;
cout << "What value of x do you want to end at?" << endl;
cin >> input;

return input;

}

int inputQuadAmount(int calc){
	int name;
		if (calc == 1){
			cout << "how many rectangles do you want to use?" << endl;
	}	
		else if (calc == 2){
			cout << "how many trapezoids do you want to use?" << endl;

		}


		else
			cout << "invalid input" << endl;

	
	cin >> name;
return name;
}

int inputCalcHow(){
	cout << askCalcHow << endl;

	int input = 0;
	cin >> input;

		if (input == 1){
			return 1;
		
		}
		else if (input == 2) {
			return 2;
		
		}
		else{
		cout << "invalid input" << endl;
		}


}


int area_calc(int fNum, int how2Calc, int start, int end, int amount){
	int area;
	int width;
	int height;
	width = (end - start)/ amount;

	if (fNum == 1){
		height = equation1(fNum, how2Calc, start, end, amount);
	}
	else if (fNum ==2){
		height = equation2(fNum, how2Calc, start, end, amount);
	}
	else if (fNum ==3){
		height = equation3(fNum, how2Calc, start, end, amount);
	}
	else if (fNum ==4){
		height = equation4(fNum, how2Calc, start, end, amount);
	}
	else if (fNum ==5){
		height = equation5(fNum, how2Calc, start, end, amount);
	}
	else{
		cout << "how you managed to print this... i'll have no idea" << endl;	
	}
	area = (width * height);
	return area;



}

int equation1(int fNum, int how2Calc, int start, int end, int amount){ 

	int a = start;
	int b = end;
	int n = amount;
	int total_height;
	int current_height;
	if (how2Calc == 1){
		while (a <= b){
			current_height = ((2*(pow(a,5)))   +    (pow(a,3))  + 2);
			a++;
			total_height += current_height;

		}
		return total_height;
	}
	else if (how2Calc == 2){
		while (a <= b){
			current_height = ((((2*(pow(a,5)))+(pow(a,3))+ 2) + ((2*(pow(a+1,5)))+(pow(a,3))+2))/2);
			a++;
			total_height += current_height;

		}


		return total_height;

	}
	else
		return 0;



}
int equation2(int fNum, int how2Calc, int start, int end, int amount){ 

	int a = start;
	int b = end;
	int n = amount;
	int total_height;
	int current_height;
	if (how2Calc == 1){
		while (a <= b){
			current_height = ((6*(pow(a,2)))- a + 10);
			a++;
			total_height += current_height;

		}
		return total_height;
	}
	else if (how2Calc == 2){
		while (a <= b){
			current_height =  ((((6*(pow(a,2)))- a + 10)  +  ((6*(pow(a+1,2)))- (a+1) + 10))/2);  
			a++;
			total_height += current_height;

		}

		return total_height;


	}
	else
		return 0;


}
int equation3(int fNum, int how2Calc, int start, int end, int amount){ 

	int a = start;
	int b = end;
	int n = amount;
	int total_height;
	int current_height;
	if (how2Calc == 1){
		while (a <= b){
			current_height = ((5*a)+3);
			a++;
			total_height += current_height;

		}
		return total_height;
	}
	else if (how2Calc == 2){
		while (a <= b){
			current_height = ((((5*a)+3)+((5*(a+1))+3))/2);     
			a++;
			total_height += current_height;

		}
		return total_height;



	}
	else
		return 0;


}
int equation4(int fNum, int how2Calc, int start, int end, int amount){ 

	int a = start;
	int b = end;
	int n = amount;
	int total_height;
	int current_height;
	if (how2Calc == 1){
		while (a <= b){
			current_height = ((2*(pow(a,3)))+120);
			a++;
			total_height += current_height;

		}
		return total_height;
	}
	else if (how2Calc == 2){
		while (a <= b){
			current_height = ((((2*(pow(a,3)))+120)+((2*(pow(a+1,3)))+120))/2);        
			a++;
			total_height += current_height;

		}

		return total_height;

	}
	else
		return 0;



}
int equation5(int fNum, int how2Calc, int start, int end, int amount){ 

	int a = start;
	int b = end;
	int n = amount;
	int total_height;
	int current_height;
	if (how2Calc == 1){
		while (a <= b){     
			current_height = (2*(pow(a,2)));   
			a++;
			total_height += current_height;


		}
		return total_height;
	}
	else if (how2Calc == 2){
		while (a <= b){
			current_height =   (((2*(pow(a,2))) + (2*(pow(a+1,2))))/2);    
			a++;
			total_height += current_height;

		}


		return total_height;

	}
	else
		return 0;



}




int output(int area,int fNum, int how2Calc, int start, int end, int amount){


if (fNum == 1){


cout << "The area under "<< actual_function1 << ", between " << start << " and "<< end << " is "<< area << endl;
 
}


else if (fNum == 2){


cout << "The area under "<< actual_function2 << ", between " << start << " and "<< end << " is "<< area << endl;
 
}


else if (fNum == 3){
    
 
cout << "The area under "<< actual_function3 << ", between " << start << " and "<< end << " is "<< area << endl;

}


else if (fNum == 4){
	

cout << "The area under "<< actual_function4 << ", between " << start << " and "<< end << " is "<< area << endl;
 
}

else if (fNum == 5){


cout << "The area under "<< actual_function5 << ", between " << start << " and "<< end  << " is "<< area << endl;
	
}









}




