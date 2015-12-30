/* CS261- Assignment 1 - Q.2*/
/* Name: Luke Brewbaker
 * Date:10/1/2015
 * Solution description: pointer arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = (*a) * 2;

    /*Set b to half its original value*/
    *b = (*b) / 2;

    /*Assign a+b to c*/
    c = (*a) + (*b);

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("X: %d \n", x);
	printf("Y: %d \n", y);
	printf("Z: %d \n\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("\nValue of foo: %d \n", foo(&x, &y, z));

    /*Print the values of x, y and z again*/
    printf("\nX: %d \n", x);
	printf("Y: %d \n", y);
	printf("Z: %d \n\n", z);

    /*Is the return value different than the value of z?  Why?*/

    /*
        The return value of the function is different than the value of Z because C is not a pointer to Z.
        Therefore, Z will remain unchanged.
    */
    return 0;
}


