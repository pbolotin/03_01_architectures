.phony : all clean

all : lab_02.a

lab_02.a : lab_02.o
		ar -rcDsv lab_02.a lab_02.o

lab_02.o : lab_02.c lab_02.h
		gcc -c lab_02.c -o lab_02.o

clean :
		rm -f *.o lab_02.a
