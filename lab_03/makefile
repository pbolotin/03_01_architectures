.phony : all clean

all : liblab_03.a libmyTerm.a

libmyTerm.a : liblab_03.a lab_03.h
		cp liblab_03.a libmyTerm.a
		cp lab_03.h myTerm.h

liblab_03.a : lab_03.o
		ar -rcDsv liblab_03.a lab_03.o

lab_03.o : lab_03.c lab_03.h
		gcc -c lab_03.c -o lab_03.o

clean :
		rm -f *.o *.a
