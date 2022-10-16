all:
	gcc -o trab1 ./client/main.c ./source/*.c -lm
	clear

clean: all
	rm -f trab1
	clear