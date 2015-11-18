#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
    char cmd = ' ';
    DynArr* mainList = createDynArr(10);

    TaskP newTask;
    TaskP firstTask;
    char desc[TASK_DESC_SIZE], filename[50], *nlptr;
    FILE *filePointer;
    int priority;





  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */

      switch(cmd){

        /* add new task */
        case 'a':
            printf("Please enter a description: ");
            /* gets description from user*/
            if(fgets(desc, sizeof(desc), stdin) != NULL){
                nlptr = strchr(desc, '/n');
                if(nlptr){
                    *nlptr = '\0';
                }
            }
            /* gets priority of task */
            do{
                printf("What is the priority? (0-999): ");
                scanf("%d", &priority);
            }while(!(priority >= 0 && priority <= 999));

            while(getchar() != '\n');

            /* create new task and add to heap */
            newTask = createTask(priority, desc);
            addHeap(mainList, newTask);
            printf("The task '%s' has been added to your list. \n\n", desc);
            break;

        /*get first task */
        case 'g':
            if(sizeDynArr(mainList) > 0){
                firstTask = (TaskP)getMinHeap(mainList);
                printf("Your first task is: %s \n\n", firstTask->description);
            }

            else
                printf("Your list is empty \n\n ");

            break;

        /* remove first task */
        case 'r':
            if(sizeDynArr(mainList) > 0){
                firstTask = (TaskP)getMinHeap(mainList);
                removeMinHeap(mainList);
                printf("Your first task '%s' has been removed. \n\n", firstTask->description);
                free(firstTask);
            }

            else
                printf("Your list is empty \n\n ");

            break;

        /* print the list */
        case 'p':
            if(sizeDynArr(mainList) > 0){
                printList(mainList);
            }

            else
                printf("Your list is empty \n\n ");

            break;

        /* save list to a file */
        case 's':
            if(sizeDynArr(mainList) > 0){
                    /* gets file name from user */
                printf("Please enter the filename: ");
                if(fgets(filename, sizeof(filename), stdin) != NULL){
                    nlptr = strchr(filename, '\n');
                    if(nlptr){
                        *nlptr = '\0';
                    }
                }

                /* opens file */
 				filePointer = fopen(filename, "w");
				if (filePointer == NULL) {
			  		fprintf(stderr, "Cannot open %s\n", filename);
					break;
                }

                /* saves list to the file */
                saveList(mainList, filePointer);

                /* close file */
                fclose(filePointer);
                printf("List saves successfully. \n\n");

            }
            else
                printf("Your list is empty \n\n ");

            break;

        /* load list from file */
        case 'l':
            printf("Please enter the filename: \n\n");
            /* get name from user */
            if(fgets(filename, sizeof(filename), stdin) != NULL){
                nlptr = strchr(filename, '\n');
                if(nlptr){
                    *nlptr = '\0';
                }
            }

            /* opens file */
            filePointer = fopen(filename, "r");
            if(filePointer == NULL){
                fprintf(stderr, "Cannot open %s\n", filename);
            }

            /* loads list */
            loadList(mainList, filePointer);

            /* close file */

            fclose(filePointer);
            printf("list loaded successfully. \n\n ");
            break;

        /* exit program */
        case 'e':
            printf("Good-bye! \n\n");
            break;

        default:
            printf("Please entere a command. \n\n");
            break;

    }

/* ends do-while loop */
}while(cmd != 'e');

  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
