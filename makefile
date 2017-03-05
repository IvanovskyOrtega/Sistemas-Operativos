a.out: main.o funciones.o  
	gcc main.o funciones.o 
main.o: main.c
	gcc -c main.c -Wall
funciones.o: funciones.c
	gcc -c funciones.c -Wall
clean:
	rm main.o funciones.o 
run: a.out
	./a.out

