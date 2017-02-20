/******************************************************************************
filename    pi.c
author      Daniel Bachler
course      CS120
due date   10/6/15

Brief Description:
  This file contains the main function for the pi assignment. It is used as
  a "driver" to test the circle_pi function and the leibniz_pi function.

******************************************************************************/
#include <stdio.h> /* scanf, printf */
#include <math.h> /*sqrt*/

double circle_pi(int rectangles);  /* Calculates PI using a quarter circle */
double leibniz_pi(int iterations); /* Calculates PI using a series         */

int main(void)
{
  int i; /* loop counter */

    /* Print out table header */
  printf("Approximations for pi\n");
  printf("Iterations      Circle Method   Leibniz Method\n");
  printf("----------------------------------------------\n");

    /* Print out values for each set of numbers */
  for (i = 1; i <= 100000; i *= 10)
  {
      /* Calculate PI with both methods */
    double pi_circle = circle_pi(i);
    double pi_leibniz = leibniz_pi(i);

      /* Print the results of the calculations */
    printf("%10i%20.12f%16.12f\n", i, pi_circle, pi_leibniz);
  }

  return 0; /* Return to the OS */
}
/*This is method that calculates pi using the lebniz method*/
double leibniz_pi(int iterations) {
   /*creates the variables that are used throught out method*/
	double leibniz = 0, a = 0;
	int temp = 0;
   /*The for loop that creates the values to calculate pi*/
	for(a = 1; a <= (iterations * 2); a += 2) {
   /*These 2 if statments control whether or not to add or subtract the fraction*/
		if (temp%2==0) {
			leibniz = leibniz + (1/a); 
		}
		if (temp%2==1) {
			leibniz = leibniz - (1/a); 
		}
		temp++;
	}
   /*Returns the value to the function*/
	leibniz = leibniz * 4;
	return (leibniz);
}
/*The method for calculating pi based on the area of rectangles*/
double circle_pi(int iterations) {
   /*Creates the variables that are needed to complete the function*/
	int a, b;
	double radius = 2.0, height = 0, midpoint = 0, widthOfRectangle, halfRectangle, heightRoot, printArea = 0;
   /*The for loop that runs based on the iterations given*/
	for(a = 1; a <= iterations; ++a) {
      /*Total area for each succesive quarter circle*/
		double totalArea = 0;
      /*Finding width of rectangles and their halfsizes*/
		widthOfRectangle = radius / a;
		halfRectangle = widthOfRectangle / 2;
      /*This for loop creates the area based on all the rectangles*/
		for(b = 1; b <= a; b++) {
			midpoint = (widthOfRectangle * (b - 1)) + halfRectangle;
			heightRoot = ((radius * radius) - (midpoint * midpoint));
			height = sqrt(heightRoot);
			totalArea += (height * widthOfRectangle);
      }
      /*Printer variable!*/
		printArea = totalArea;
	}
   /*Returns the value*/
	return (printArea);
}