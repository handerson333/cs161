#include <iostream>
#include <cmath>
//Defines the specific weight of water
#define WATER_WEIGHT 62.4;
using namespace std;


int main (){
	//Variables needed to calculate buoyancy
	double radius;
	double bforce;
	double volume;
	double weight;
	double PI = 3.14;
	//Prompt user for weight and radius of sphere
	cout << "Please enter the weight (lbs): "<< endl;
	cin >> weight;
	cout << "Please enter the radius: "<<endl;
	cin >> radius;
	//Calculate the volume and buoyancy force
	volume = 4/3 * PI;
	bforce = volume * WATER_WEIGHT;
	//Determine if the sphere will sink or float
	if(bforce >= weight){ 
		cout << "The sphere will float!\n";
	}
	else{
		cout << "The sphere will sink!\n";
	}
	return 0;
}
