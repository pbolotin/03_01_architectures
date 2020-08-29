.phony : all clean

LIB_02_PATH := -L./lab_02
LIB_02 := -llab_02

all: sc_test_02

sc_test_02 : sc_test_02.o
		make -C lab_02
		gcc $(LIB_02_PATH) sc_test_02.o -o sc_test_02 $(LIB_02)

sc_test_02.o : sc_test_02.c
		make -C lab_02
		gcc -c sc_test_02.c -o sc_test_02.o

clean:
		make clean -C lab_02
		rm -f *.o sc_test_02
