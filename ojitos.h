//ESTRUCTURA
typedef struct{
    char operacion;
    double resultado_double1;
    double resultado_double2;
    double resultado_double3;
    int resultado_int;
    int op1;
    int op2;
    int op3;
}OPERACION;
//ARITMETICA.C
int suma(int a, int b);
int multiplicacion(int a, int b);
int resta(int a, int b);
double division(double a, double b);
//SERIES.C
int factorial(int a);
int factorial_rec(int a);
int serie_fib(int val_final);
void triangulo_fib(int tam);
//CONSTANTES.C
double euler(int a);
double serieLebniz(int n);

