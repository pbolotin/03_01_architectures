.PHONY : all clean

all : liblab_05.a libmyReadKey.a

libmyReadKey.a : liblab_05.a lab_05.h
		cp liblab_05.a libmyReadKey.a
		cp lab_05.h myReadKey.h

liblab_05.a : lab_05.o
		ar -rcDsv liblab_05.a lab_05.o

lab_05.o : lab_05.c lab_05.h
		gcc -c lab_05.c -o lab_05.o

clean :
		rm -f *.o *.a
