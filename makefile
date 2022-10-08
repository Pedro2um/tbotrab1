execute:
	./prog

compile:
	gcc -c main.c ./library/*.c 
	clear
	mv *.o ./dotObjects
	clear
	gcc -o prog ./dotObjects/*.o -lm
	clear

cexecute:
	make compile
	./prog
	
clearObjects:
	rm ./dotObjects/*.o
valgrind:
	valgrind ./prog
