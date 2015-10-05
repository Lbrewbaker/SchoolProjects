/* CS261- Assignment 1 - Q.3*/
/* Name: Luke Brewbaker
 * Date:10/1/2015
 * Solution description:Sorting an array
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int i, j, temp;
	for (i = (n - 1); i > 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if (number[j - 1] > number[j])
			{
				temp = number[j - 1];
				number[j - 1] = number[j];
				number[j] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    rand();

    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i ++){
        array[i] = ((rand() % 100) + 1);

    }

    /*Print the contents of the array.*/
    printf("Unsorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }


    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);

    /*Print the contents of the array.*/
    printf("\nSorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
