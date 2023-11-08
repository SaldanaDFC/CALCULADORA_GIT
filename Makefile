calculadora_git.out: aritmetica.o constantes.o series.o calculadora_git.o
	gcc -o calculadora_git.out constantes.o series.o aritmetica.o calculadora_git.o -lm
aritmetica.o: aritmetica.c
	gcc -c aritmetica.c
constantes.o: constantes.c
	gcc -c constantes.c
series.o: series.c
	gcc -c series.c
calculadora_git.o: calculadora_git.c
	gcc -c calculadora_git.c
