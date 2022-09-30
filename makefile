execute:
	./prog

compile:
	gcc -c main.c ./library/*.c
	mv *.o ./dotObjects
	gcc -o prog ./dotObjects/*.o
	clear

cexecute:
	gcc -c main.c ./library/*.c
	mv *.o ./dotObjects
	gcc -o prog ./dotObjects/*.o
	clear
	./prog
	
clearObjects:
	rm ./dotObjects/*.o
