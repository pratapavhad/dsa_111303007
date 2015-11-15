/* strf.c : This file contains the string functions 
required by the main file typetest.c */
#include <stdio.h>
#include <string.h>
#include "wordlist.h"
int combcheck(node *a, node *b) {
	/* Input : Two nodes of the lists origlist and
	 * typelist. Checks whether the word in b [i.e.
	 * typed word] is a combination of next 1 or 2 word(s).
	 * Output : Returns 1 if word of a and next word is 
	 * combined, 2 if next 2 words are combined.
	 * Returns 0 if no combinations is found
	*/
        char temp[32], temp2[32], temp3[32];
        strcpy(temp, a->str);
        strcpy(temp2, a->next->str);
        strcpy(temp3, a->next->next->str);
        strcat(temp, temp2);
        if(strcmp(temp, b->str) == 0)
                return 1;
        strcat(temp, temp3);
        if(strcmp(temp, b->str) == 0)
                return 2;
        return 0;
}
void inscommas(char *str) {
	/* Input : string.
	  Inserts spaces or commas at the end end of 
	  each line of str*/
	int i = 0;
	while(str[i + 1] != '\0') {
		if(str[i + 1] == '\n') {
			if(str[i] == ',' || str[i] == '.' || str[i] == ' ') {
				i++;
				continue;
			}
			else {
				str[i + 1] = ',';
				i++;
			}
		}
		else 
			i++;
	}
}
