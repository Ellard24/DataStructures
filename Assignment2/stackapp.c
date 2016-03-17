/*****************************************************************************
 * Author: Ellard Gerritsen
 * Description: The program reads an input, uses a stack to discover whether a sting 
 * 		is balanced. 
 * Input: Input received before runtime in form of prog "insert string here"
 * Output: Displays whether the input string is balanced in regards to (){}[]
 *****************************************************************************/




/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post: Returns 1 or 0 and displays corresponding response in main
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	if (s == 0)
		return 0;
	char ch;

	struct DynArr *balArray = newDynArr(10);
	while((ch = nextChar(s)) != '\0')
	{
		
		//printf("%c\n",ch);	//test statement 
		
		//Push when ch = [,{,( 
		if(ch == '[' || ch == '(' || ch == '{')
			pushDynArr(balArray, ch);

		//Pop when ],},) and when array is not empty
		if(ch == ']' || ch == ')' || ch == '}')
		{		
			if (isEmptyDynArr(balArray))
				return 0;
			//Check the individual situations and pop if matching
			if (ch == ']')
			{
				if (topDynArr(balArray) == '[')
				{
					popDynArr(balArray);
					

				}
				else
					return 0;
				
			}
			else if (ch == '}') 
			{
				if (topDynArr(balArray) == '{')
				{
					popDynArr(balArray);
				}
				else
					return 0;
			}
			else if (ch == ')')
			{
				if (topDynArr(balArray) == '(')
				{
					popDynArr(balArray);
				}
				else
					return 0;
			}
			
				
		}
		//printf("%d", sizeDynArr(balArray));//  test statement
		//printf("Top of Stack: %c\n", topDynArr(balArray));// test statement
	}
	
	 	

		
	if (!isEmptyDynArr(balArray))
	{
		return 0;
	}
	else
	{
		deleteDynArr(balArray);
		return 1;
	}

	
}

int main(int argc, char* argv[]){


	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}




