							W-TYPE TYPE SPEED ANALYZER
						     Pratap Avhad  MIS :111303007
Source code files :
1)typetest.c : This is the heart of this application. It conducts a typetest and returns speed and accuracy in the form of typedata, from the typetest() function.
	For measurement of time, 2) time.c, plays a vital role. This function has only getchar() and putchar(). So the executable of time.c is called as a system call isside typetest, with the type command, and the output is saved in a file called timedata.

2)corrwords.c : This is the error checking function. It marks a word as correct if two corresponding tokens in the typed and original lists are same. It also uses the checkcomb() function in strf.c, which is discussed below.

3)random.c : Contains a random function which generates a random integer of max value specified.

4)randomfile.c : Contains randomfile function, to return file pointer to any random file amongst the 21 data files in the folder. Uses random.c

5)strf.c : Contains the string functions of the program : combcheck and inscommas.
The earlier checks combinations of 2 or 3 words in the user typed data. The latter one inserts spaces or commas at the end of each line of user input, which helps in tokenizing the data.

6)user.c, user.h : Contains the user data type declarations, and functions.

7)wordlist.c, wordlist.h : Contains the list data type declarations and functions.

8)printline.c : This function uses random.c, to print random number of lines from the buffer the random file.

9)main.c : The main function of the program. Manages the activities during program run. 

Data files :
1) 1data.txt - 21data.txt : Data to be printed during each test. Random data is chosen from these files.

2) timedata : Has the time taken by user in the the latest type test. This is stored in a buffer, which is converted into a float.

3) instructions.txt : Contains the instructions regarding the use of program.

4) tips.txt : Contains tips regarding how to touch type, and increase typing speed.
