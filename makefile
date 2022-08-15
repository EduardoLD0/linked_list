all: programa
programa: test.c
	gcc test.c -o test.out
	./test.out
