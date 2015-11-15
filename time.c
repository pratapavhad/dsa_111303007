/*Program just measures the time taken by a user to input a string*/
/*This is the source of the executable 'tim'.
  This shouldn't be compiled with other files during cc *.c,
  so it is renamed as time.source */
int main() {
	char ch;
	while((ch = getchar()) != -1)
		putchar(ch);
	/*Every character is printed, which is in turn
	  put to the file datatyped, by the system call in 
	  the program calltime.c
	*/	
	return 0;
}
