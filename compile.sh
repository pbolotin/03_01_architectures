gcc -c -g lab_02/lab_02.c -o lab_02/lab_02.o
gcc -c -g sc_test.c -o sc_test.o
gcc -g lab_02/lab_02.o sc_test.o -o sc_test.out