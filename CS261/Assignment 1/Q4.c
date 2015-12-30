/* CS261- Assignment 1 - Q.4*/
/* Name: Luke Brewbaker
 * Date:10/1/2015
 * Solution description: sorting and allocating arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int i, j, tempscore, tempid;
	for (i = (n - 1); i > 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
            if (students[j - 1].score > students[j].score)
			{
				tempscore = students[j - 1].score;
				tempid = students[j - 1].id;
				students[j - 1].score = students[j].score;
				students[j - 1].id = students[j].id;
				students[j].score = tempscore;
				students[j].id = tempid;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n * (sizeof(struct student)));

    /*Generate random IDs and scores for the n students, using rand().*/
    rand();

    //assign ID's
    for (int i = 0; i < 10; i ++){
        students[i].id = ((rand()%10 + 1));
        //check for duplicates and replace
        for (int j = 0; j < i; j ++){
        if (students[i].id == students[j].id){
            i--;
        }
     }
   }

	//generate and assign scores
    for (int i = 0; i < 10; i ++){
        students[i].score = ((rand()%100 + 1));
        //check for duplicates and replace
        for (int j = 0; j < i; j ++){
        if (students[i].score == students[j].score){
            i--;
        }
     }
   }
    /*Print the contents of the array of n students.*/

	for (int i = 0; i < 10; i++)	{
		printf("Unsorted ID: %d Unsorted Score: %d \n", students[i].id, students[i].score);
	}

    /*Pass this array along with n to the sort() function*/
    sort(students, n);

    /*Print the contents of the array of n students.*/
	for (int i = 0; i < 10; i++){
		printf("Sorted ID: %d Score: %d \n", students[i].id, students[i].score);
	}
    return 0;
}
