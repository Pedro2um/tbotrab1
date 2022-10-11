execute:
	./prog

compile:
	gcc -Wall -c main.c ./library/*.c
	mv *.o ./dotObjects
	gcc -Wall -o prog ./dotObjects/*.o -lm

cexecute:
	make compile
	./prog
	
clearObjects:
	rm ./dotObjects/*.o
valgrind:
	valgrind ./prog
