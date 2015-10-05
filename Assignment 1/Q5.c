/* CS261- Assignment 1 - Q.5*/
/* Name: Luke Brewbaker
 * Date:10/1/2015
 * Solution description:"sticky caps" demonstration
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
     	int i;
	for(i = 0; word[i] != '\0'; i++)
	{
		if(word[i] >= 'a' && word[i] <= 'z')
		{
			word[i] = toUpperCase(word[i]);
		}
	}

	for(i = 1; word[i] != '\0'; i = i +2)
	{
		word[i] = toLowerCase(word[i]);
	}

}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[50];
    printf("Enter a word.  Please only use a-z, and no more than 50 characters: ");
    scanf("%s", word);

    /*Call sticky*/
    sticky(word);

    /*Print the new word*/
    printf("%s \n", word);

    return 0;
}
