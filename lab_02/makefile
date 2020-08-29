.phony : all clean

all : liblab_02.a

liblab_02.a : lab_02.o
		ar -rcDsv liblab_02.a lab_02.o

lab_02.o : lab_02.c lab_02.h
		gcc -c lab_02.c -o lab_02.o

clean :
		rm -f *.o *.a
