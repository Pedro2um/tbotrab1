ex:
	./prog

c:
	gcc -c main.c ./library/*.c 
	mv *.o ./dotObjects
	gcc -o prog ./dotObjects/*.o -lm
	clear
cex:
	make c
	./prog
	
clearObjects:
	rm ./dotObjects/*.o
exv:
	valgrind ./prog
