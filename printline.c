/*printline.c : contains functions printlines(), which prints random number of lines*/
#include <stdio.h>
void printlines(char *str, int x, char *temp) {
	int i = 0, j = 0;
	//char temp[4096];
	while(i != x) {
		putchar(*str);
		temp[j] = *str;
		if(*str == '\n')
			i++;
		*str++;
		j++;
	}
	//return temp;
}	
	
