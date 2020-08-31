.phony : all clean

LIB_02_PATH := -L./lab_02
LIB_02 := -llab_02

LIB_03_PATH := -L./lab_03
LIB_03 := -llab_03
LIB_MYTERM_03 := -lmyTerm

all: sc_test_02 mt_test_03

sc_test_02 : sc_test_02.o ./lab_02/*.c ./lab_02/*.h
		make -C lab_02
		gcc $(LIB_02_PATH) sc_test_02.o -o sc_test_02 $(LIB_02)

sc_test_02.o : sc_test_02.c
		make -C lab_02
		gcc -c sc_test_02.c -o sc_test_02.o

mt_test_03: mt_test_03.o ./lab_03/*.c ./lab_03/*.h
		make -C lab_03
#		gcc $(LIB_03_PATH) mt_test_03.o -o mt_test_03 $(LIB_03)
		gcc $(LIB_03_PATH) mt_test_03.o -o mt_test_03 $(LIB_MYTERM_03)

mt_test_03.o : mt_test_03.c
		make -C lab_03
		gcc -c mt_test_03.c -o mt_test_03.o

clean:
		make clean -C lab_02
		make clean -C lab_03
		rm -f *.o sc_test_02 mt_test_03
