.phony : all clean

LIB_02_PATH := -L./lab_02
LIB_02 := -llab_02

LIB_03_PATH := -L./lab_03
LIB_03 := -llab_03
LIB_MYTERM_03 := -lmyTerm

LIB_04_PATH := -L./lab_04
LIB_04 := -llab_04
LIB_MYBIGCHARS_04 := -lmyBigChars

LIB_05_PATH := -L./lab_05
LIB_05 := -llab_05
LIB_MYREADKEY_05 := -lmyReadKey

all: sc_interface_05 rk_test_05 sc_interface_04 bc_test_04 sc_interface_03 mt_test_03 sc_test_02 

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

bc_test_04: bc_test_04.o ./lab_04/*.c ./lab_04/*.h ./lab_03/*.c ./lab_03/*.h
		make -C lab_03
		make -C lab_04
#		gcc $(LIB_04_PATH) bc_test_04.o -o bc_test_04 $(LIB_04)
		gcc $(LIB_04_PATH) $(LIB_03_PATH) bc_test_04.o -o bc_test_04 $(LIB_MYBIGCHARS_04) $(LIB_MYTERM_03)

bc_test_04.o : bc_test_04.c
		make -C lab_03
		make -C lab_04
		gcc -c bc_test_04.c -o bc_test_04.o

rk_test_05: rk_test_05.o ./lab_05/*.c ./lab_05/*.h
		make -C lab_05
		gcc $(LIB_05_PATH) rk_test_05.o -o rk_test_05 $(LIB_MYREADKEY_05)

rk_test_05.o : rk_test_05.c
		make -C lab_05
		gcc -c rk_test_05.c -o rk_test_05.o

sc_interface_03: sc_interface_03.o ./lab_03/*.c ./lab_03/*.h ./lab_02/*.c ./lab_02/*.h
		make -C lab_02
		make -C lab_03
		gcc sc_interface_03.o $(LIB_02_PATH) $(LIB_02) $(LIB_03_PATH) $(LIB_MYTERM_03) -o sc_interface_03

sc_interface_03.o: sc_interface_03.c
		make -C lab_02
		make -C lab_03
		gcc -c sc_interface_03.c -o sc_interface_03.o

sc_interface_04: sc_interface_04.o  ./lab_04/*.c ./lab_04/*.h ./lab_03/*.c ./lab_03/*.h ./lab_02/*.c ./lab_02/*.h
		make -C lab_02
		make -C lab_03
		make -C lab_04
		gcc sc_interface_04.o $(LIB_02_PATH) $(LIB_02) $(LIB_03_PATH) $(LIB_MYTERM_03) $(LIB_04_PATH) $(LIB_MYBIGCHARS_04) -o sc_interface_04

sc_interface_04.o: sc_interface_04.c
		make -C lab_02
		make -C lab_03
		make -C lab_04
		gcc -c sc_interface_04.c -o sc_interface_04.o

sc_interface_05: sc_interface_05.o  ./lab_05/*.c ./lab_05/*.h ./lab_04/*.c ./lab_04/*.h ./lab_03/*.c ./lab_03/*.h ./lab_02/*.c ./lab_02/*.h
		make -C lab_02
		make -C lab_03
		make -C lab_04
		make -C lab_05
		gcc sc_interface_05.o $(LIB_02_PATH) $(LIB_02) $(LIB_03_PATH) $(LIB_MYTERM_03) $(LIB_04_PATH) $(LIB_MYBIGCHARS_04) $(LIB_05_PATH) $(LIB_MYREADKEY_05) -o sc_interface_05

sc_interface_05.o: sc_interface_05.c
		make -C lab_02
		make -C lab_03
		make -C lab_04
		make -C lab_05
		gcc -c sc_interface_05.c -o sc_interface_05.o

clean:
		make clean -C lab_02
		make clean -C lab_03
		make clean -C lab_04
		make clean -C lab_05
		rm -f *.o sc_test_02 mt_test_03 sc_interface_03 sc_interface_04 bc_test_04 big_digits.bin test_sc_memorySave.bin rk_test_05 sc_interface_05
