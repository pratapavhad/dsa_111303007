/*wordlist.c : This file contains the code for list data type */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordlist.h"
void init(list *l) {
        l->head = l->tail = NULL;
}
/*Append a word to the provided list*/
void append(list *l, char *str) {
        /* Create a node using tmp pointer
         * Store the data
         * change  tmp->next, tmp->prev, head->prev, tail->next, tail 
         */
        node *tmp = (node *)malloc(sizeof(node));
        tmp->str = malloc(strlen(str)+1);
        strcpy(tmp->str, str);
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
/*Insert word in the provided list, at given position*/
void insert(list *l, int pos, char *str){
        node *tmp, *p, *temp;
        int i = 0;
        tmp = (node *)malloc(sizeof(node));
        tmp->str = malloc(sizeof(strlen(str) + 1));
        strcpy(tmp->str, str);
        p = l->head;
        if(pos > (l->length))/*When pos is beyond length, do nothing*/
                tmp = NULL;
        else if(p == NULL) { /*When list is empty, allow insert only at head*/
                if(pos == 0) {
                        l->head = l->tail = tmp;
                        tmp->next = tmp->prev = l->head = l->tail;
                       l->length++;
                }
                else
                        tmp = NULL;
        }
        else {
                while(i++ < pos)
                        p = p->next;
                if(pos != (l->length)) {
                        temp = p->prev;
                        tmp->next = p;
                        p->prev = tmp;
                        tmp->prev = temp;
                        temp->next = tmp;
                        if(pos == 0)
                                l->head = tmp;
                        l->length++;
                }
                else { /*If insert is at last pos., it is = append*/
                        append(l, str); /*Append does l->len++ so no need to do
                                                                                               it here*/
                        tmp = NULL;
                }
        }
}


