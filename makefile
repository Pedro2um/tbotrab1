execute:
	./prog

compile:
	gcc -c main.c ./library/*.c 
	mv *.o ./dotObjects
	gcc -o prog ./dotObjects/*.o -lm

cexecute:
	make compile
	./prog
	
clearObjects:
	rm ./dotObjects/*.o
valgrind:
	valgrind ./prog
