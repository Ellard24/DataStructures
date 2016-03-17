/************************************************
**Author: Ellard Gerritsen van der Hoop
**Description: Program that converts from inches to centimeters and vice versa
**Input: All input received during runtime. 
**Output: Displays the value after conversion is finished
***********************/

#include <stdio.h>
#include <stdlib.h>


double convertToCent(double number);
double convertToInch(double number);


/************************************************
 * Function: main
 * Description: Runs simulation of converting numbers
 * Parameters: -
 * Pre-Conditions:-
 * Post-Conditions: Prints numbers to screen
 * **********************************************/

int main()
{
	int loopControl = 1;
	int choice = 0;
	double number1 = 0;

	printf("This Program will allow you to convert inches to centimeters as well as \n centimeters to inches\n");
	
	while (loopControl == 1)
	{
		printf("Which one would you prefer to do? Press 1 for Inch->Centimeters \n or 2 for Centimeters->Inch \n ");

		scanf("%d", &choice);

		printf("What number do you want to convert?\n");
		

		scanf("%lf", &number1);

		double total = 0;

		if (choice == 1)
		{
			total = convertToCent(number1);
			printf("%lf centimeters\n", total);
		}

		else if (choice == 2)
		{
		    total =	convertToInch(number1);
			printf("%lf inches \n", total);

		}
		printf("Do you want to try another? Press 1 for Yes and 2 for No\n");

		
		scanf("%d",  &loopControl);
		
	}

	printf("End of Program\n");

	return 0;

}


/*************************************************
 * Function: convertToCent
 * Description: Converts inches to centimeters
 * Parameters: double number
 * Pre-Condtions: Number needs to be passed to function
 * Post-Conditions: Converted number gets printed 
 * ************************************************/


double convertToCent(double number)
{
	
	return number*2.54;

}

/****************************************************
 * Function: convertToInch
 * Description: Converts centimeters to inches
 * Parameters: double number
 * Pre-Conditions: Number needs to be passed to function
 * Post-Condtions: Converted number gets printed 
 * ***********************************************/
double convertToInch(double number)
{

	return number/2.54;


}
