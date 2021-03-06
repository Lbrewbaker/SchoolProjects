#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dynamicArray.h"
#include "toDoList.h"



int main(int argc, const char * argv[])
{
  	TYPE task1;
	TYPE task2;
	TYPE task3;
	TYPE task4;
	TYPE task5;
	TYPE task6;
	TYPE task7;
	TYPE task8;
	TYPE task9;
	TYPE task10;

	DynArr *mainList;
	mainList = createDynArr(10);

	/* create tasks */
	task1 = createTask(9, "task 1");
	task2 = createTask(3, "task 2");
	task3 = createTask(2, "task 3");
	task4 = createTask(4, "task 4");
	task5 = createTask(5, "task 5");
	task6 = createTask(7, "task 6");
	task7 = createTask(8, "task 7");
	task8 = createTask(6, "task 8");
	task9 = createTask(1, "task 9");
	task10 = createTask(0, "task 10");

	/* add tasks to the dynamic array */
	addHeap(mainList, task1);
	addHeap(mainList, task2);
	addHeap(mainList, task3);
	addHeap(mainList, task4);
	addHeap(mainList, task5);
	addHeap(mainList, task6);
	addHeap(mainList, task7);
	addHeap(mainList, task8);
	addHeap(mainList, task9);
	addHeap(mainList, task10);


	printf("Before Sort Called \n");
         printDynArr(mainList, print_type);

	/* sort tasks */
	sortHeap(mainList);

	printf("After Sort Called \n");

	/* print sorted tasks from the dynamic array */
          printDynArr(mainList, print_type);

	return 0;
}
