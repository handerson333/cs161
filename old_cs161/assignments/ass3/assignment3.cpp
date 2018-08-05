/*********************************************************************
 * ** Program Filename: assignment3
 * ** Author: Robert Hayden Anderson
 * ** Date: 4/25/15
 * ** Description: finds area under curves
 * ** Input: starting point and ending point, which function, number of quadralaterals, which quadralateral to use
 * ** Output: the function used, start and end points , area calculated
 * *********************************************************************/



#include<iostream>
#include<cmath>

using namespace std;

int get_curve();
int get_shape();
void get_input(int shape, int& n, int& x1, int& x2);
float width(int n, int x1, int x2);

void function_1r(int x1, int x2, float w);     
void function_2r(int x1, int x2, float w);    
void function_3r(int x1, int x2, float w);   
void function_4r(int x1, int x2, float w);   
void function_5r(int x1, int x2, float w);  

void function_1t(int x1, int x2, float w ); 
void function_2t(int x1, int x2, float w ); 
void function_3t(int x1, int x2, float w ); 
void function_4t(int x1, int x2, float w ); 
void function_5t(int x1, int x2, float w ); 

void trapezoid_if(int curve, int x1, int x2, float w);
void rectangle_if(int curve, int x1, int x2, float w);
void shape_if(int shape, int curve, int x1, int x2, float w);


int main() {
   
    int x1;
    int x2;
    int n;
    int curve = get_curve();
while (curve!=9){
    int shape = get_shape();
    get_input(shape, n, x1, x2);
    float w= width(n, x1, x2);
    shape_if(shape, curve, x1, x2, w);
    cout<<endl;
    cout<<"Do you want to find the area again?"<<endl;
    curve = get_curve();
}

return 0;
}


// prompts user for the curve they want to find the area under


int get_curve(){
	
	
   	int curve;
	int redo;
	redo=true;

	while (redo==true){
	cout<<"Which curve would you like to approximate area under? 1) 2x^5+x^3-10x+2  2) 6x^2-x+10   3) 5x+3   4) 2x^2+120   5) 2x^3 or 9) quit"<<endl;
	cin>>curve;

		if((curve==1)||(curve==2)||(curve==3)||(curve==4)||(curve==5)||(curve==9))
		   redo=false;
		else {
		   redo=true;
		   cout<<"please enter one of the given numbers"<<endl;
		}
	}
return curve; 
}

// prompts user for trapezoid or rectangle

int get_shape(){
        int shape;
	int redo;
	
	redo=true;
	while (redo==true){

	cout<<"Do you want to find the area with trapezoids or with rectangles? Type 1 for trapezoids or 2 for rectangles or 3 for both"<<endl;
	cin>>shape;
		
		if (shape==1)
		   redo=false;
		else if(shape==2)
		   redo=false;
		else if (shape==3)
		   redo=false;
		else {
		   redo=true;
		   cout<<"please enter one of the given numbers"<<endl;
		}
	}	

return shape;
}


// getting values from the user
// shape= rectangle or trapezoid given by user
// n= number of shapes
// x1= left most side of the area
// x2= right most side of the area

void get_input(int shape, int& n, int& x1, int& x2) {

	if (shape==1){
	   cout<<"How many trapezoids do you want to use to find the area?"<<endl;
	}
   
	   else if(shape==2){
	   cout<<"How many rectangles do you want to use to find the area?"<<endl;
	}

	else {
	   cout<<"How many rectangles and trapazoids do you want to use to find the area?"<<endl;
	}

	cin>>n;

	cout<<"Put in a starting x value for the area"<<endl;
	cin>>x1;

	cout<<"Put in a ending x value for the area"<<endl;
	cin>>x2;;

}



// defining the width with the users values
// n= number of shapes given by user
// x1= left most side of the area
// x2= right most side of the area

float width(int n, int x1, int x2) {
	float w;
	w= float(float(x2-x1)/n);
	
	return w;
}






// rectangle area


// area f1(x)
// x1= left most side of the area
// x2= right most side of the area
// w= width of the rectangle

void function_1r(int x1, int x2,float  w) {    
   
	
	float y;
	float h;
	
	y=0;
	for (float i=x1; i<=(x2-w); i=(i+w)){
	     h=((2*(pow(i,5))+(pow(i,3))-(10*i)+2));	
 	     y=(y+(h*w));

	}

	cout<<"The area under the curve for rectangle using 2x^5 + x^3 - 10x + 2 is approximately "<<y<<endl;

}


// area f2(x)
// x1= left most side of the area
// x2= right most side of the area
// w= width of rectangle

void function_2r(int x1, int x2, float w) {   
        
 	float y;
  	float h;
  	
	y=0;
	for (float i=x1; i<=(x2-w); i=(i+w)) {
             h=((6*(pow(i,2))-i+10));
             y=(y+(h*w));
         
	}

    	cout<<"The area under the curve for rectangle using 6x^2 - x + 10 is approximately "<<y<<endl;

}




// area f3(x)
// x1= left most side of the area
// x2= right most side of the area
// w= width of rectangle

void function_3r(int x1, int x2, float w) {  

	float h;
	float y;

	y=0;
	for (float i=x1; i<=(x2-w);i=(i+w)) {
             h=((5*i)+3);
             y=(y+(h*w));
        
	     cout<<"y"<<y<<endl;
	     cout<<"h"<<h<<endl;
	}

 	cout<<"The area under the curve for rectangle using 5x + 3 is approximately "<<y<<endl;

}



// area f4(x)
// x1= left most side of the area 
// x2= right most side of the area
// w= width of rectangle

void function_4r(int x1, int x2, float w) {  
 
        float h;
        float y;
 
	y=0;
        for (float i=x1; i<=(x2-w); i=(i+w)) {
             h=(2*(pow(i,3))+120);
             y=(y+(h*w));
       
       	}
     
        cout<<"The area under the curve for rectangle 2x^3 + 120 is approximately "<<y<<endl;

}



// area f5(x)
// x1= left most side of the area
// x2= right most side of the area
// w= width of the rectangle

void function_5r(int x1, int x2, float w) { 

        float h;
        float y;

	y=0;
        for (float i=x1; i<=(x2-w); i=(i+w)) {
             h=(2*(pow(i,2)));
             y=(y+(h*w));
           
	}

        cout<<"The area under the curve for rectangle  is approximately "<<y<<endl;

}
	


// picking what area function to use
// picks between the rectangle area functions based on the user input 

void rectangle_if(int curve, int x1, int x2, float w) {

	if (curve==1)
	   function_1r(x1,x2,w);
	else if (curve==2)
	   function_2r(x1,x2,w);
	else if (curve==3)
	   function_3r(x1,x2,w);
	else if (curve==4)
	   function_4r(x1,x2,w);
	else if (curve==5)
	   function_5r(x1,x2,w);
}







// trapezoid areas


// trapezoid f1(x)
// finds area under f1(x) with trapezoids
//x1= left most end of the area
//x2= right most end of the area
//w= the width of each shape that the area is found with


void function_1t(int x1, int x2, float w ) {
	
        float h1;
        float h2;
        float y;
        float b;
   
        y=0;
        for (float i=x1; i<=(x2-w); i=(i+w)) {
             h1=((2*(pow(i,5)))+(pow(i,3)-(10*i)+2));
             b=(i+w);
             h2=((2*(pow(b,5)))+(pow(b,3)-(10*b)+2));
	     y=(y+(((h1+h2)/2)*w));
             }
        
	cout<<"The area under the curve for trapezoid using 2x^5 + x^3 - 10x + 2 is approximately "<<y<<endl;

}



// trapezoid f2(x)
// finds area under f2(x) with trapezoids
//x1= left most end of the area
//x2= right most end of the area
//w= the width of each shape that the area is found with


void function_2t(int x1, int x2, float w ) {

        float h1;
        float h2;
        float y;
        float b;

        y=0;
        for (float i=x1; i<=(x2-w); i=(i+w)) {
             h1=((6*(pow(i,2)))-i+10);
             b=(i+w);
             h2=((6*(pow(b,2)))-i+10);
             y=(y+(((h1+h2)/2)*w));
             }
      
       	cout<<"The area under the curve for trapezoid using 6x^2 - x + 10 is approximately "<<y<<endl;

}



// trapezoid f3(x)
// finds area under f3(x) with trapezoids
//x1= left most end of the area
//x2= right most end of the area
//w= the width of each shape that the area is found with

 
void function_3t(int x1, int x2, float w ) {

        float h1;
        float h2;
        float y;
        float b;

        y=0;
        for (float i=x1; i<=(x2-w); i=(i+w)) {
             h1=((5*i)+3);
             b=(i+w);
	     h2=((5*b)+3);
             y=(y+(((h1+h2)/2)*w));
             }	
       
	cout<<"The area under the curve for trapezoid using 5x + 3 is approximately "<<y<<endl;

}



// trapezoid f4(x)
// finds area under f4(x) with trapezoids
//x1= left most end of the area
//x2= right most end of the area
//w= the width of each shape that the area is found with


void function_4t(int x1, int x2, float w ) {
       
       float h1;
       float h2;
       float y;
       float b;

       y=0;
       for (float i=x1; i<=(x2-w); i=(i+w)) {
             h1=((2*(pow(i,3)))+120);
             b=(i+w);
             h2=((2*(pow(b,3)))+120);
             y=(y+(((h1+h2)/2)*w));
             }
   
       cout<<"The area under the curve for trapezoid using 2x^3 + 120 is approximately "<<y<<endl;

}



// trapezoid f5(x)
// finds area under f5(x) with trapezoids
//x1= left most end of the area
//x2= right most end of the area
//w= the width of each shape that the area is found with


 void function_5t(int x1, int x2, float w ) {

        float h1;
        float h2;
        float y;
        float b;

        y=0;
        for (float i=x1; i<=(x2-w); i=(i+w)) {
             h1=(2*(pow(i,2)));
             b=(i+w);
             h2=(2*(pow(b,2)));
             y=(y+(((h1+h2)/2)*w));
      	     }
      
       	cout<<"The area under the curve for trapezoid using 2x^2 is approximately "<<y<<endl;

}



// picking what trapeziod area fuction to use
//curve= the curve that the area is found under
//x1= left most end of the area
//x2= right most end of the area
//w= the width of each shape that the area is found with


void trapezoid_if(int curve, int x1, int x2, float w){
	
	if (curve==1)
		function_1t(x1,x2,w);
	else if (curve==2)
		function_2t(x1,x2,w);
	else if (curve==3)
		function_3t(x1,x2,w);
	else if (curve==4)
		function_4t(x1,x2,w);
	else if (curve==5)
		function_5t(x1,x2,w);


}



// calling rectangle trapezoid or both functions
// pick between the functions that find area with trapezoids or rectangles
//shape= type of shape to find area
//curve= the curve that the area is found under
//x1= left most end of the area
//x2= right most end of the area
//w= the width of each shape that the area is found with
void shape_if(int shape, int curve, int x1, int x2, float w){



		if (shape==2){
			rectangle_if(curve, x1, x2, w);
		}
		else if (shape==1){
			trapezoid_if(curve, x1, x2, w);
		}
	        else if (shape==3){
			rectangle_if(curve, x1, x2, w);
			trapezoid_if(curve, x1, x2, w);
			}

}
