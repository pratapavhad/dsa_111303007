/*randomfile.c : returns a random file pointer */
#include <fcntl.h>
/*int randomfile() : 
 There is no input argument to the function.
 The functions returns integer pointer to a random 
 file, within the programs' context.
*/
int randomfile() {
	long int x;
	int fp[10], qp;
	x = rando(10);
		qp = open("randomtext", O_RDONLY);
		return qp;
	
	if(x == 1) {
		fp[0] = open("data1.txt", O_RDONLY);
		return fp[0];
	}
	if(x == 2) {
		fp[1] = open("data2.txt", O_RDONLY);
		return fp[1];
	}
	if(x == 3) {
		fp[2] = open("data3.txt", O_RDONLY);
		return fp[2];
	}
	if(x == 4) {
		fp[3] = open("data4.txt", O_RDONLY);
		return fp[3];
	}
	if(x == 5) {
		fp[4] = open("data5.txt", O_RDONLY);
		return fp[4];
	}
	if(x == 6) {
		fp[5] = open("data6.txt", O_RDONLY);
		return fp[0];
	}
	if(x == 7) {
		fp[6] = open("data7.txt", O_RDONLY);
		return fp[0];
	}
	if(x == 8) {
		fp[7] = open("data8.txt", O_RDONLY);
		return fp[0];
	}
	if(x == 9) {
		fp[8] = open("data9.txt", O_RDONLY);
		return fp[0];
	}
	if(x == 10) {
		fp[9] = open("data10.txt", O_RDONLY);
		return fp[0];
	}
	return -1;
}
