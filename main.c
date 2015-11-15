/*
 * W-Type Type analyzer  - type analyzer program for linux systems
 * 
 * Copyright (C) 2014  Pratap Avhad <pratapavhad15@gmail.com>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <time.h>
//#include <term.h>
#include "wordlist.h"
#include "user.h"
#include "typetest.h"
#define PTAB printf("\t\t\t\t\t");	
#define Hashes for(k=0;k<150;k++)putchar('#');

	/* Each line of the saved user list is stored in a buffer */
typedef struct line {
	char l[256];
} line;

int main(int argc, char *argv[]) {
        char tim[8], *token1, *token2, temp[4096], typed[4096], instruc[4096], tips[4096], ulist[8192], usrnm[8], passwd[16], choice, opt1, opt2, lboard[4096], *tokens[4096], tempf[8], *token4, ch, ch5, tok4[32], tok5[32];
	line ulines[4096];
	typedata td;
	float earsp, last5[5], pts = 0, tempfl, avgs, avga;
        int fp, fp2, fp3, fp5, fp6, fp9, tempfp, ajax = 1;
	FILE *fp7, *fp8;
        int n , i = 1, s = 5, x = 0, y = 1, j = 0, a = 0, c = 0, k = 1, usnum = 0, e = 0, ins = 0, f = 0, m = 0, d = 0, b = 0, loopvar = 1, h, l = 1, o = 1, isa, whin = 1;
	long int w;
	userlist usrlist;
	user *up, *usr, def, cp;
	uinit(&usrlist);
	up = usrlist.head;
	system("clear");
		
			/*So first of all we open userlist.txt, create the userlist 
			 *from it.
				 */
	if(argc == 1) { 
		fp7 = fopen("userlist.txt", "a+"); 
		if(fp7 == NULL) {
			perror("Some files are missing");
			exit(0);
		}
			//fp8 = fopen("leaderboard.txt", "a+");
		n = fread(ulist, 1, 8192, fp7);
		ulist[n] = '\0';
			//fread(lboard, 1, 4096, fp8);
		while(ulist[f] != '\0') { 
			/* This loop converts the buffer ulist into seperate strings, 
				with one line of the file in each string */
			b = 0;
			while(ulist[f] != '\n') {
				ulines[d].l[b] = ulist[f];
				f++;
				b++;
			}
			ulines[d].l[b] = '\0';
				//printf("%s\n", ulines[d].l);
			f++;
			d++;
		}
		while(e < d) {
			/* Now each line buffer is seperated
		  	 as tokens, and each token is associated 
		 	  to the appropriate type of "user".
		 	  Note that in one traversal of loop, one
		 	  user node is created in list
			*/
			tokens[e] = strtok(ulines[e].l, " ,");
			ins = 0;
			while(tokens[e]) {
				ins++;
				if(ins == 1) 
					strcpy(cp.usrnm, tokens[e]);
				
				else if(ins == 2) 
					strcpy(cp.passwd, tokens[e]);
				else if(ins == 3) {
					strcpy(tempf, tokens[e]);
					cp.avgspeed = strtof(tempf, NULL);
				}
				else if(ins == 4) {
					strcpy(tempf, tokens[e]);
					cp.avgacc = strtof(tempf, NULL);
				}
				else if(ins == 5) {
					strcpy(tempf, tokens[e]);
					cp.pts = strtof(tempf, NULL);
				}
				else if(ins == 6) {
					strcpy(tempf, tokens[e]);
					cp.races = atoi(tempf);
				}
				tokens[e] = strtok(NULL, " ,");
			}
			e++;
			uappend(&usrlist, cp);
				//printlist(&usrlist);
			if(strcmp(ulines[e].l, ulines[e-1].l) == 0)
				e++;
		
		}
		removdupl(&usrlist);
			/*The main screen */
		Hashes;
		printf("\n");
			//printlist(&usrlist);
		system("setterm -bold on");
		PTAB;
		printf(" WELCOME TO W-TYPE TYPING TUTOR...\n");
		system("setterm -bold off");
		Hashes;
		printf("\n\n\n\n\n\n\n\n\n");
		PTAB;
		printf("Please read instructions first...\n");
		sleep(1);
		PTAB;
		printf("Press any key to continue....\n");
		PTAB
		while(1) {
			printf("1) Guest   2) Log in   3) Read instructions.  4) Sign up 5) Exit\n");
			PTAB;
			printf("Enter your choice ...\n");
			PTAB;
			scanf("%c", &choice);
			if(choice == '1') {
				/*Take typing test as a guest*/
				while(k) {
					typetest(randomfile());
					printf("\n");
					while(o) {
                                        	printf("Try again ? Press y or n\n");
                                                scanf("%c", &opt1);
                                                if(opt1 == EOF) 
						/*This option exists because the EOF
						  of ./tim coincides here*/
                                                	continue;
                                                if(opt1 == 'n') {
                                                	k = 0;
      	                                        	o = 0;
                                        	}
						if(opt1 == 'y') 
							o = 0;
					}
				}
			}
			else if(choice == '2') { 
					/*Log into previously created a/c*/
				PTAB;
				k = 0;
				printf("ENTER USERNAME : ");
				scanf("%s", usrnm);
				printf("\n");
				PTAB;
				printf("ENTER PASSWORD : ");
				PTAB;
				system("stty -echo");
				scanf("%s", passwd);
				system("stty echo");
				if((usr = chkpass(&usrlist, usrnm, passwd)) !=  NULL) {
					system("clear");
					Hashes;
					printf("\n\n\n");
					PTAB;
					system("setterm -bold on");
					printf("WELCOME  %s\n", usrnm);	
					printf("\n\n\n");
					Hashes;
					printf("\n\n\n\n");
					while(ajax) {
						printf("1) Take test\n"
							"2) View Profile\n"
							"3) Leaderboard\n" 
							"4) How to touch type : TIPS\n"
							"5) Take practise lessons with gtypist\n"
							"6) Exit.\n");	
						scanf("%c", &opt2);
						if(opt2 == '1') {
							k = 1;
							while(k) {
							/* Take typing test.
							 * All data is analysed here.
							 * Speed and accuracy is 
							 * recived from typetest() fn.
							*/
								earsp = usr->avgspeed;
								usr->races++;
                                        			td = typetest(randomfile());
                                        			printf("\n");
								if(usr->avgspeed == 0)
									avgs = td.speed;
								else
									avgs = (usr->avgspeed + td.speed) / 2;
								usr->avgspeed = avgs;
								if(usr->avgacc == 0)
									avga = td.acc;
								else
									avga = (usr->avgacc + td.acc) / 2;
								usr->avgacc = avga;
								pts += 0.8 * avgs + 0.2 * avga;	//pts = 80%speed and 20%accuracy
								usr->pts = pts;
								printf("Your average speed = %f\t", avgs);
								if(earsp < avgs)
									printf("AVERAGE SPEED INCREMENT. GOOD JOB (Y)!\n");
								else
									printf("HMM...AVERAGE DECREMENTS. TRY BETTER NEXT TIME...\n"); 		
								printf("Total points = %f\n", pts);
								if(avga < 90)
									printf("Do work on accuracy...Accuracy > 90 = O.K.\n");
								while(l) {
                                        				printf("Try again ? Press y or n\n");
                                        				scanf("%c", &opt1);
									if(opt1 == EOF)
										continue;
                                        				if(opt1 == 'n') {
                                                				k = 0;
										l = 0;
									}
									if(opt1 == 'y' || opt1 == 'Y')
										l = 0;
								}
                                			}			
						}
						else if(opt2 == '2') {
						/*Display profile of user*/
							Hashes;
							putchar('\n');
							Hashes;
							printf("\n\n");
							PTAB;
							printf("USERNAME : %s\n", usr->usrnm);		
							PTAB;
							printf("AVERAGE SPEED : %.1f WPM\n", usr->avgspeed);
							PTAB;
							printf("ACCURACY : %.2f\n", usr->avgacc);
							PTAB;
							printf("RACES COMPLETED : %d\n", usr->races);
							PTAB;
							printf("RANK : NOOB\n");
						}
						else if(opt2 == '3') {
					//		lboard(usrlist);
						}
						else if(opt2 == '4') {
						/*Display important tips for touch typing
						  and on how to increase typing speed */
							fp5 = open("tips.txt", O_RDONLY);
							if(fp5 == -1)
								perror("File Error ");
							n = read(fp5, tips, 4096);
							tips[n] = '\0';
							puts(tips);
						}
						else if(opt2 == '5') {
						/*Practise typing lessons from the very basic using gtypist*/
							printf("Practise basic lessons nicely with GNU typist\n");
							sleep(3);
							system("gtypist");
						}
						else if(opt2 == '6') {
							printf("GOOD DAY. SEE YOU NEXT TIME...\nHappy Linuxing..... :D");
							sleep(2);
					                up = usrlist.head;
							usnum = usrlist.length;
							/*The user list is now saved in the file userlist.txt
							 Also on line 318 and 331*/
        					        for(i = 0; i < usnum; i++) {
                        					fprintf(fp7, "%s %s %f %f %f %d\n", up->usrnm, up->passwd, up->avgspeed, up->avgacc, up->pts, up->races);
                        					//printf("%s %s %f %f %f %d\n", up->usrnm, up->passwd, up->avgspeed, up->avgacc, up->pts, up->races);
                        					if(strcmp(up->usrnm, up->next->usrnm) == 0)
									up = up->next->next;	
								else
									up = up->next;
				                	}
							exit(0);
						}
						else 
							printf("Enter appropriate option...\n");
					}//inner while brace	
				}
				else 
					printf("Incorrect username or password. Try Again\n");
					
			}//else if bracket
			else if(choice == '3') {
				fp6 = open("instructions.txt", O_RDONLY);
				n = read(fp6, instruc, 4096);
				instruc[n] = '\0';
				puts(instruc);
				printf("\n");
			}
			else if(choice == '4') {
				/*Create an a/c*/
				PTAB;
				loopvar = 1;
				while(loopvar) {
					printf("Enter an username [Upto 8 characters long with no spaces]\n");
					PTAB;
					scanf("%s", usrnm);
					isa = isavailable(&usrlist, usrnm);
					if(isa) {
						printf("\n");
						PTAB
						printf("Enter a strong password [Upto 16 characters long with no spaces]\n");
						PTAB
						system("stty -echo");
						scanf("%s", passwd);
						system("stty echo");
						usnum++;
						loopvar = 0;
						strcpy(def.usrnm, usrnm);
						strcpy(def.passwd, passwd);
						def.avgspeed = 0;
						def.avgacc = 0;
						def.pts = 0;
						def.races = 0;
						uappend(&usrlist, def);	
					}
					else 
						printf("Username already taken...\n");
				}
			}
			else if(choice == '5') {
  	      	                up = usrlist.head;
                		do {
                        		fprintf(fp7, "%s %s %f %f %f %d\n", up->usrnm, up->passwd, up->avgspeed, up->avgacc, up->pts, up->races);
 					if(strcmp(up->usrnm, up->next->usrnm) == 0)
                                        	up = up->next->next;
					else
                                                up = up->next;
                		}while(up != usrlist.head);
			//	printlist(&usrlist);
				exit(0);	
			}
		}//while bracket
		up = usrlist.head;
		do {
                	fprintf(fp7, "%s %s %f %f %f %d\n", up->usrnm, up->passwd, up->avgspeed, up->avgacc, up->pts, up->races);
                        if(strcmp(up->usrnm, up->next->usrnm) == 0)
                        	up = up->next->next;
                        else
                                up = up->next;
                }while(up != usrlist.head);
	}
        else if(argc == 2){
		if(strcmp(argv[1], "-g") == 0)
			fp = open("randomtext", O_RDONLY);
		else
			fp = open(argv[1], O_RDONLY);
		if(fp == -1) {
			perror("File Error ");
			return 0;
		}
		typetest(fp);
	}
	return 0;
}
