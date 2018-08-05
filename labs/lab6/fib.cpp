#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <wctype.h>
#include <algorithm>
using namespace std;

int fib_iter(int n);
int fib_recurs(int n);
int main(){
	cout << " what # do you want to find the fibonacci sequence of?" << endl;
	int n;
	cin >> n;
	int n2 = n;
	//fib recurs
	for (int i=1; i<=n; ++i){
		cout << "fib " << i << " recursively = " << fib_recurs(i) << endl;	

	}
	//fib iter1
	cout << endl;	
	int temp = fib_iter(n2);
	//fib iter2
	/*
	cout << "iteratively..." << endl;
	fib_iter(n);
	*/
	return 0;
}
//fib iter1
int fib_iter(int n){
	if (n==0){return 0;}
	int prev = 0;
        int curr = 1;
	cout << "fib " << curr << " iteratively = " << curr  << endl;
	for (int i = 1; i < n; ++i){
	int next = prev + curr;
     	prev = curr;
	curr = next;
	cout << "fib " << i << " iteratively = " << curr  << endl;
	}
	return curr;
}

//fib recurse
int fib_recurs(int n){
	if (n<=0){
		return 0;
	}
	else if (n==1){
		return 1;
	}
	else
		return fib_recurs(n-1)+fib_recurs(n-2);

}



//fib iter2
/*
int fib_iter(int n){
	int fib[] = {0,1,1}; //original 3 values
	for(int i=2; i<n; i++){
		fib[i%3] = fib[(i-1)%3] + fib[(i-2)%3];
		cout << "fibonacci of " << i << " = " << fib[i%3] << endl;
	}
	return fib[n%3];
}
*/
