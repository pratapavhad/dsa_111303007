
all:main

printline.o:printline.c
	gcc -c printline.c

corrwords.o:corrwords.c
	gcc -c corrwords.c

main.o:main.c
	gcc -c main.c

random.o:random.c
	gcc -c random.c

randomfile.o:randomfile.c
	gcc -c randomfile.c

strf.o:strf.c
	gcc -c strf.c

typetest.o:typetest.c
	gcc -c typetest.c

user.o:user.c
	gcc -c user.c

wordlist.o:wordlist.c
	gcc -c wordlist.c

main:main.o printline.o corrwords.o random.o randomfile.o strf.o typetest.o user.o wordlist.o


