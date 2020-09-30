.PHONY : all clean

all : liblab_04.a libmyBigChars.a

libmyBigChars.a : liblab_04.a lab_04.h
		cp liblab_04.a libmyBigChars.a
		cp lab_04.h myBigChars.h

liblab_04.a : lab_04.o
		ar -rcDsv liblab_04.a lab_04.o

lab_04.o : lab_04.c lab_04.h
		gcc -c lab_04.c -o lab_04.o

clean :
		rm -f *.o *.a myBigChars.h
