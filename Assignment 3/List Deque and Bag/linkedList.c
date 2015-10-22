#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {

    /* allocate and make sure memory was allocated properly */
    lst->firstLink = (struct DLink*)malloc(sizeof(struct DLink));
    lst->lastLink = (struct DLink*)malloc(sizeof(struct DLink));
    assert(lst->firstLink != NULL);
    assert(lst->lastLink != NULL);

    /* set up the sentinels */
    lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;

    /* make size 0 initially*/
    lst->size = 0;

}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */
    assert(lst != NULL);
	assert(l != NULL);

    struct DLink *newlink = (struct DLink*)malloc(sizeof(struct DLink));
    assert(newlink != NULL);

    newlink->value = v;
    newlink->prev = l->prev;
    newlink->next = l;

    l->prev->next = newlink;
    l->prev = newlink;
    lst->size++;

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	/* FIXME: you must write this */
    assert(lst != NULL);
	_addLinkBefore(lst, lst->firstLink->next, e);

}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {

	/* FIXME: you must write this */
    assert(lst != NULL);
    _addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
    assert(lst != NULL);
	assert(!isEmptyList(lst));
	return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	assert(lst != NULL);
    assert(!isEmptyList(lst));
    return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
    assert(lst != NULL);
	assert(l != NULL);

    /* disconnecting the links */
    l->prev->next = l->next;
    l->next->prev = l->prev;

    /* remove member and decrement size */
    free(l);
    lst->size--;

}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));

    _removeLink(lst, lst->firstLink->next);

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
	/* FIXME: you must write this */
    assert(lst != NULL);
	assert(!isEmptyList(lst));

    _removeLink(lst, lst->lastLink->prev);

}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	assert(lst != NULL);
    return(lst->size ==0);
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */
    assert(lst != NULL);
	assert(!isEmptyList(lst));

	/* create an item to loop through the whole list. */
    struct DLink *current = lst->firstLink->next;
    assert(current != 0);

    /* loop and print value */
    while (current != lst->lastLink){
		printf("Value: %d\n", current->value);
		current = current->next;
	}


}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	/* FIXME: you must write this */
	assert(lst != NULL);

	/* add to the back of the list instead of front since it is a bag */
	addBackList(lst, v);

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
	assert(lst != NULL);
	assert(!isEmptyList(lst));

    /* again creating the item to loop through the list */
	struct DLink *current = lst->firstLink->next;
	assert(current != 0);

    /*loop through and check if the list contains the value E */
   for(int i = 0; i < lst->size; i++){
		if (current->value == e){
			return 1;
		}
		current = current->next;
		i++;
	}
	return 0;
}


/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
    assert(lst != NULL);
	assert(!isEmptyList(lst));

    struct DLink *current = lst->firstLink->next;

    for(int i = 0; i < lst->size; i++){
        if(current->value == e){
            _removeLink(lst, current);
            break;
        }
        else if(current->next == NULL){
            break;
        }
        else{
            current = current->next;
        }
    }
}
