/* CS261- Assignment 1 - Q.1*/
/* Name: Luke Brewbaker
 * Date:10/1/2015
 * Solution description:struct allocation
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int vektor[10];

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *x = malloc(10 * (sizeof(struct student)));

     /*return the pointer*/
     return x;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     rand();

     //assign ID's 1-10.  since I loop through them 1 at a time I know they are unique.
    for (int i = 0; i < 10; i ++){
        students[i].id = i + 1;
     }

     //assign scores
     for (int i = 0; i < 10; i++){
        students[i].score = ((rand()%100) + 1);
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < 10; i++){
        printf("ID %d:  Score: %d \n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i = 0;
    int sum = 0;
    int average = 0;
    int min = 100;
    int max = 0;

    //calculate minimum
    for (i = 0; i < 10; i++){
        if(students[i].score < min){
            min = students[i].score;
        }
    }

    //calculate maximum
    for (i = 0; i < 10; i++){
        if (students[i].score > max){
            max = students[i].score;
        }
    }

    //calculate average
    for (i = 0; i < 10; i++){
        sum += students[i].score;
    }
    average = (sum / 10);

    //print results
    printf("Minimum score: %d \n", min);
    printf("Maximum score: %d \n", max);
    printf("Average score: %d \n", average);


}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
