#include<iostream>
#include<cmath>
using namespace std;

double computeBond(double F, double c, double y, int t) {
	//compute Bond
	double B = 0;
	double temp = (1 + (0.01*y/2));
	
	for(int i=1; i<t; i++) {
		B = B + ((c/2)/(pow(temp,i)));
	}
	
	B = B + ((F+(c/2))/(pow(temp,t)));
	
	return B;
}


int main() {
	
	double F = 0;
	double c = 0;
	int t =  3;
	cout << "Please input the F of the bond : ";
	cin >> F;
	//in midterm 1 F will be 100
	
	cout << "Please input the c of the bond : ";
	cin >> c;
	//in midterm 1 c will be 4
	cout << endl;
	
	for(int i=0; i<10; i++) {
		double Btemp = computeBond(F, c, i, t);
		cout << "y(%) = " << i << ", B = " << Btemp << endl;
	}
	
	//**************************************************************************************************************
	
	double BM = 0 ;
	int yMid = 0;
	cout << endl <<"Please input the B-market : ";
	cin >> BM;
	
	double yMin = 0;
	int yMax = 9;
	
	while(true) {
		
		yMid = (yMin+yMax) / 2;
		
		double B_Mid =  computeBond(F, c, yMid, t);
		
		if( (BM == B_Mid) || (yMid-yMin<=1 && yMax-yMid<=1 && yMax-yMin == 1)) {
			//the while loop will stop, if
			//1. find the same Bond value
			//2. the distance from y-Min to y-low & y-high is smaller than 1
			cout << "y-low : " << yMin << endl;
			cout << "y-high : " << yMax << endl;
			cout << "y-mid : " << (yMin+yMax)/2 << endl;
			cout << "B-mid : " << computeBond(F, c, (yMin+yMax)/2, t) << endl;
			break;
		}
		else if(BM < B_Mid) yMin = yMid;
		
		else yMax = yMid;
	}
	
	cout << "In Question 5, B3.25 : " << computeBond(F, c, 3.25, t) << endl;
		
	return 0;
}
