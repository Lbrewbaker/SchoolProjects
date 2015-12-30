#include "cirListDeque.h"
#include "cirListDeque.c"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque();
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("\nRemoving front of Deque: %g", frontCirListDeque(q));
	printf("\nRemoving back of Deque: %g", backCirListDeque(q));
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);

	printf("\nRemoved back and front at this point\n");
	printf("New front:%g", frontCirListDeque(q));
	printf("\n");
    printf("New back:%g", backCirListDeque(q));
    printf("\n");
    printf("\n");


	printCirListDeque(q);
	reverseCirListDeque(q);
	printCirListDeque(q);
	return 0;
}
