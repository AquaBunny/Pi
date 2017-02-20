/******************************************************
*Name: Daniel Bachler
*Date: 9-22-15
*pi.c
*Is the accesory to the main and prints out pi with 
*things
********************************************************/
#include <stdio.h>
double circle_pi(int rectangles) {
	int a;
	double radius = 2.0, height, midpoint;
	for(a = 0; a <= rectangles; ++a) {
		height = 0.0;
		midpoint = 0.0;
		
	}
	return 0;
}
double leibniz_pi(int iterations) {
	double leibniz = 0;
	int b = 0;
	for(int a = 1; a <= (iterations * 2) + 1; a += 2) {
		if(b == 0) {
			leibniz += 1.0/a; 
			b = 1;
		}
		if(b == 1) {
			leibniz -= 1.0/a;
			b = 0;
		}
	}
	leibniz = leibniz * 4;
	
	return leibniz;
}