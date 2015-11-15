
/* corrwords.c : COntains func. corrwords, which returns number of correct words */
#include <stdio.h>
#include <string.h>
#include "wordlist.h"

int corrwords(list origlist, list typelist) {
	int a, j = 0, correct = 0;
	node *origptr, *typeptr;
	origptr = origlist.head;
	typeptr = typelist.head;	
	for(a = 0; a < origlist.length; a++) {
        		if(strcmp(origptr->str, typeptr->str) == 0) {
        	               origptr = origptr->next;
        	               typeptr = typeptr->next;
			       correct++;
	       	        }
        	        else {
        	               if(combcheck(origptr, typeptr) == 1) {
        	      	       		insert(&typelist, a + 1, "xxx");
        	 	                origptr = origptr->next;
        	                        typeptr = typeptr->next;
        	               }
			       else if(combcheck(origptr, typeptr) == 2) {
        	                        insert(&typelist, a + 1, "xxx");
        	                        insert(&typelist, a + 2, "xxx");
        	                        origptr = origptr->next;
        	                        typeptr = typeptr->next;
        	               }
        	               else {
        	                        origptr = origptr->next;
        	                        typeptr = typeptr->next;
                	       }
                	}
	}
	return correct;
}
