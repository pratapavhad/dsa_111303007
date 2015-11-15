/*user.c : This file contains the code for 'user' data type functions.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
void uinit(userlist *l) {
        l->head = l->tail = NULL;
}
/*Append a user to the provided list */
void uappend(userlist *l, user def) {
        /* Create a node using tmp pointer
         * Store the data
         * change  tmp->next, tmp->prev, head->prev, tail->next, tail 
         */
        user *tmp = (user *)malloc(sizeof(user));
        strcpy(tmp->usrnm, def.usrnm);
	strcpy(tmp->passwd, def.passwd);
	tmp->avgspeed = def.avgspeed;
	tmp->avgacc = def.avgacc;
	tmp->pts = def.pts;
	tmp->races = def.races;	
        if(l->head) {
                tmp->next = l->head;
                tmp->prev = l->tail;
                l->head->prev = tmp;
                l->tail->next = tmp;
        } else {
                tmp->next = tmp->prev = l->head
                      = tmp;
        }
        l->tail = tmp;
	l->length++;
}
void remov(userlist *l, int pos) {
	user *p;
	int i;
	/* Locate the node at position = pos
	 * Rechain 
	 * Free the node
	 */
	/* Locate the node */
	if(pos < 0 || pos >= l->length)
		return ;
	/* pos is correct */
	p = l->head;
	for(i = 0; i < pos; i++)
		p = p->next;
	/* rechain */
	p->prev->next = p->next;
	p->next->prev = p->prev;
	/* free node */
	if(pos == 0)
		l->head = l->head->next;
	if(pos == l->length - 1)
		l->tail = l->tail->prev;
	if(l->length == 1) {
		l->head = l->tail = NULL;
	}
	free(p);
	l->length--;
}
/* Input : userlist, character pointers usrnm and passwd
 * Return value : pointer to the requied user.
 * Checks the password of given username.
 * returns NULL if failed
 */
user *chkpass(userlist *l, char *usrnm, char *passwd) {
	user *tmp;
	tmp = l->head;
	if(l->head == NULL)
		return NULL;
	do {
		if(strcmp(tmp->usrnm, usrnm) == 0) {
			if(strcmp(tmp->passwd, passwd) == 0) 
				return tmp;	 
			else 
				tmp = tmp->next;
		}
		tmp = tmp->next; 
	}while(tmp != l->head);
	return NULL;
}
/*Checks if usrnm is already there in userlist l
  Returns 1 if usrnm is available, 0 otherwise */
int isavailable(userlist *l, char *usrnm) {
	user *tmp;
	tmp = l->head;
	if(l->head == NULL)
		return 1;
	do {
		if(strcmp(tmp->usrnm, usrnm) == 0) 
			return 0;
		else
			tmp = tmp->next;
	} while(tmp != l->head);
	return 1;
}
void removdupl(userlist *l){
  	user *davik, *uzvik;
        int pos = (l->length) - 1;
        davik = l->head;
        uzvik = l->tail;
        while(davik != l->tail->prev) {
                while(uzvik != davik) {
                        if(strcmp(davik->usrnm, uzvik->usrnm) == 0) {
                                /*Duplicate found here*/
                                uzvik = uzvik->prev;
                                remov(l, pos);
                                pos--;
                        }
                        else {
                                uzvik = uzvik->prev;
                                pos--;
                        }
                }
                uzvik = l->tail;
                davik = davik->next;
                pos = (l->length) - 1;
        }

}
