
/* typetest.c : Contains the function typetest() which conducts a type test */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <ctype.h>
#include "wordlist.h"
#include "typetest.h"
#define PTAB printf("\t\t\t\t\t");

typedata typetest(int fp) {
	typedata data;
	list origlist, typelist;
	float percenttyped, correct_per, time;
	int fp2, fp3, n, w, i = 0, words = 0, typed_words = 0, x = 0, y = 0, correct = 0, j = 0, a = 0;
	char buff[8192], temp[8192], typed[8192], tim[8], *token1, *token2;
	init(&origlist);
	init(&typelist);
	n = read(fp, buff, 4096);
        buff[n] = '\0';
        w = rando(15);
	system("clear");
	PTAB;
	printf("TYPE THE FOLLOWING PARA OF TEXT, AS FAST U CAN ...\n");
	sleep(3);
	PTAB;
	printf("PRESS 'Ctrl + D' ON A NEWLINE TO END TYPING  ...\n");
	sleep(3);
	PTAB;
	system("setterm -bold on");
	printf("GET READY W-TYPIST...............................................\n");
	sleep(6);
	PTAB;
	printf("Your time starts.");
	printf("NOW \n\n");
	printlines(buff, w, temp);
	printf("---------------------------------------------------------------------\n"); 
	token1 = strtok(temp, " ,.");
	while(token1) {

		words++;
	  	append(&origlist, token1);
	  	token1 = strtok(NULL, " ,.");
	}
				/*(x - 1) is the number of original words. */
	system("/usr/bin/time -o timedata -f \t%e ./tim > datatyped");
				/* Assert :The data typed by user is saved into file 'datatyped'*/
	fp2 = open("timedata", O_RDONLY);
	n = read(fp2, tim, 4);
	tim[n] = '\0';		/*Assert : The time is now saved in a file*/
	fp3 = open("datatyped", O_RDONLY);
	n = read(fp3, typed, 4096);
	typed[n] = '\0';	/* Assert : Typed data is in typed */
				/* We count the words typed */

	inscommas(typed);
	printf("Words in input : %d\n", words);
	token2 = strtok(typed, " ,.");
	while(token2) {

		typed_words++;
		append(&typelist, token2);
		token2 = strtok(NULL, " ,.");
	}			/* We compare words and typed words now */
				/*(y - 1) is the number of typed words. */

	printf("Typed words : %d\n", typed_words);
	printf("Origlist length = %d\n", origlist.length);
	correct = corrwords(origlist, typelist);
	printf("correct = %d\ntyped = %d\n", correct, typed_words);
	correct_per = ((float)correct / (float)typed_words) * 100;

	if(correct_per > 100)		/* Sometimes this was going above 100 for unknown reasons*/
		correct_per = 100;	/*Let us rectify it*/
	time = strtof(tim, NULL) / 60;
	data.speed = (float)typed_words / time;
	data.acc = correct_per;
	printf("Correct percent = %f\n", correct_per);
					/* printf("%f\n", time); printf("%s\n", tim); printf("%f\n", atof(tim)); */
	percenttyped = ((float)typed_words / (float)words) * 100;
        printf("%f percent typed\n", percenttyped);

	if(correct_per >= 80) {
		if(percenttyped < 50) 
			printf("You have typed too less.\nType more for speed analysis.\n");
		else {
			if(typed_words < words) {
	    			printf("Words typed : %d\n", typed_words);
	    			printf("SPEED = %1.f WPM \n", (float)typed_words / (float)time);
	  		}		
	  		else {
				printf("Words : %d\n", words);
	    			printf("SPEED = %1.f WPM \n", (float)words / (float)time); 
	  		}
	 	}
	}
	else if(correct_per <=50)
	 	printf("What you have typed is completely . Please type the data as shown on the screen\n");
	else 
	 	printf("You have committed too many errors. Please type atleast with 80 percent accuracy to get typing results.\n");	
	return data;
}
