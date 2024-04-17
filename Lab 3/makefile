testing: iterativeFibonacci.o recursiveFibonacci.o iterativeFindMax.o recursiveFindMax.o lab3aMain.o
	gcc -Wall -std=c99 iterativeFibonacci.o recursiveFibonacci.o iterativeFindMax.o recursiveFindMax.o lab3aMain.o -o testing
iterativeFibonacci.o: iterativeFibonacci.c lab3.h
	gcc -Wall -std=c99 -c iterativeFibonacci.c
recursiveFibonacci.o: recursiveFibonacci.c lab3.h
	gcc -Wall -std=c99 -c recursiveFibonacci.c
iterativeFindMax.o: iterativeFindMax.c lab3.h
	gcc -Wall -std=c99 -c iterativeFindMax.c
recursiveFindMax.o: recursiveFindMax.c lab3.h
	gcc -Wall -std=c99 -c recursiveFindMax.c
lab3aMain.o: lab3aMain.c lab3.h 
	gcc -Wall -std=c99 -c lab3aMain.c
clean:
	rm *.o testing