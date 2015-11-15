/*random.c : Generate a random integer*/
#include <stdlib.h>
#include <time.h>
/* Input : int max. Returns a random long integer
 whose maximum value can be max.
*/
long int rando(int max) {
//	int n, max;
	time_t tt;
	long int i;
//	scanf("%d%d", &n, &max);
	srandom(time(&tt));
	i = random() % max;
	return i;
}
