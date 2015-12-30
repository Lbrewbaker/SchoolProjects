/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"
#include "dynamicArray.c"

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
	post:
*/

/*

I was very stuck on this portion of the assignment.  I tried using If statements and loops but I kept hitting segmentation faults.  I turned to stack overflow and found this article, written in Java but it helped me finally figure this out:
http://stackoverflow.com/questions/26516789/using-stack-to-check-balance-for-multiple-lines-of-code

Giving credit where credit is due.

*/


int isBalanced(char* s)
{
 struct DynArr *array = newDynArr(10);
    char c;
    while((c = nextChar(s)) != '0'){
        switch(c){
            case '{' :
            case '[' :
            case '(' :
                pushDynArr(array, c);
                break;

            case '}' :
                if(topDynArr(array) == '{'){
                    popDynArr(array);
                    break;
                }
                return 0;

            case ']' :
                if(topDynArr(array) == '['){
                    popDynArr(array);
                    break;
                }
                return 0;

            case ')' :
                if(topDynArr(array) == '('){
                    popDynArr(array);
                    break;
                }
                return 0;

        }
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

