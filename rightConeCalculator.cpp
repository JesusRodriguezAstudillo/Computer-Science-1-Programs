/* Name:	Calculator for the Volume and Surface Area of a Right Cone
   Author:	Jesus Rodriguez
   Version:
   Copyright:
   Description:	This program was created to  promt a user for a radius
		and a height in order to calculate the volume and
		the surface area of a right cone. For the volume, the
		equation used was V = (PI * r^2 * h) / 3. For the 
		surface area, the equation used was
		SA = (PI * r^2) + ( sqrt ((r^2) + (h^2))).
*/
#include <iostream>
#include <math.h>		// Library that includes square roots and powers.
#include <string>		// Library to allow entry of user's name.
using namespace std;

int main ()
{
	string name_of_user;	// Name of string variable.
				/* Isolated number variables from the string
				   so that they are easier to read. */
	double height;		// Name of the height variable as a decimal
	double radius;		// Name of the radius variable as a decimal.
	double volume;		// Name of the volume variable as a decimal.
	double surface_area;	// Name of the surface area variable as a decimal.
	double const PI = 3.14159265358979; /* Name of the constant pi in all capitals
					       Assigned  pi to 14 decimal places.*/
				// accounted for decimal places.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(8);	// Added decimal precision to 8 decimal places.
				// Introduction banner
	cout << "+-----------------------------------------------+ \n";
	cout << "|	Computer Science and Engineering	| \n";
	cout << "|	CSCE 1030 - Computer Science I		| \n";
	cout << "| 	Jesus Rodriguez		 jr0463		| \n";
	cout << "|	jr0463@unt.edu				| \n";
	cout << "+-----------------------------------------------+ \n";
				/* Prompt for the user's name
				   and display a welcome message.*/
	cout << "Please enter yout first name: ";
	cin  >> name_of_user;
	cout << endl;
	cout << "Hello, " << name_of_user << "! Welcome to CSCE 1030. \n";
	cout << "Let us calculate the volume and surface area of a cone. \n"; 
				// Prompt for the radius and height.
	cout << "Please enter the radius of a cone: ";
	cin  >> radius;
	cout << "Next, please enter the height of a cone: ";
	cin  >> height;
	cout << endl;		// Added an end line so that results are easier to read
				/* Assigned the the variables of volume
				   and surface area*/
	volume = (PI * (pow (radius, 2)) * height) / 3;

	surface_area = (PI * (pow (radius, 2))) + (( PI * radius) * ( sqrt((pow (radius, 2))+ (pow (height, 2)))));
				// Output of the results.
	cout << "The volume of your cone is: " << volume << endl;
	cout << "The surface area of your cone is: " << surface_area << endl;

	return 0;
}

