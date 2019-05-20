/* Name:	Basic Integer Calculator
   Author:	Jesus Rodriguez
   Version:
   Copyright:
   Description:	This program was created to displays the results of
		simple arithmetic operations with integers. The program
		handles varibles with multiway branches to output
 		the value of the first integer and handle any integers
		greater than ten and less the than negative ten. The
		promgram then reads in another integer and displays
		the desired values of the operations, unless the user
		attempts to divide by zero.
*/
#include <iostream>
using namespace std;

int main ()
{
	int num1, num2, results;// Variables to allow input and output

	char operation;	// Variable that will allow a mathematical operation

			// Header banner
	cout << "+-----------------------------------------------+ \n";
	cout << "|	Computer Science and Engineering	| \n";
	cout << "|	CSCE 1030 - Computer Science I		| \n";
	cout << "| 	Jesus Rodriguez		 jr0463		| \n";
	cout << "|	jr0463@unt.edu				| \n";
	cout << "+-----------------------------------------------+ \n";
	cout << endl;

			// Start of do-while loop
	do
	{
					// Prompt for the first integer
		cout << "Please enter an integer in the range of -10 to 10: ";
		cin  >> num1;		// Read in first integer
		
		if (num1 < -10)		// Displays error message if value is less than -10
		{
			cout << "The number that you entered (" << num1 << ") is less than -10. \n";
		}
		else if (num1 > 10) 	// Displays error message if value is greater than 10
		{
			cout << "The number that you entered (" << num1 << ") is greater than 10. \n";
		}
		else if ((num1 > 0) && (num1 <= 10)) // Displays the integer as a positive number
		{
			cout << "The number that you entered (" << num1 << ") is positive. \n";
		}
		else if ((num1 < 0) && (num1 >= -10)) // Displays the integer as a negative number
		{
			cout << "The number that you entered (" << num1 << ") is negative. \n";
		}
		else
		{
			cout << "The number that you entered (" << num1 << ") is zero. \n";
		}
	}while ((num1 < -10) || (num1 >10)); /* End of while loop if the first value is 
						between -10 and 10*/
	
	cout << endl; 	// Added an endline reduce visual clutter

			// Prompt for the second integer
	cout << "Now enter another integer: ";
			// Read in value
	cin  >> num2;
			// Prompt for operation
	cout << "Enter an arithmetic operation (+, -, *, or /) that you would like to perform: ";
	cin  >> operation;
	
			// Start of if-else statment
	if ((operation == '/') && (num2 == 0))	// If statement outputs error messsage when dividing by zero
	{	
		cout << "This operation is not valid! \n";
	}
	else
	{
		switch (operation) // start of switch controlled by the operation variable
		{
			case '+':
				results = num1 + num2;
				cout << "Integer sum is: " << results << endl;
				break;
			case '*':
				results = num1 * num2;
				cout << "Integer multiplication is: " << results << endl;
				break;
			case '/':
				results = num1 / num2;
				cout << "Integer division is: " << results << endl;
				break;
			case '-':
				results = num1 - num2;
				cout << "Integer subtraction is: " << results << endl;
				break;
			// Default statement handles any invalid character as a sum of the two integers
			default:
				results = num1 + num2;
				cout << "Integer sum is: " << results << endl;
		}	
	}	
	
	return 0;
}
