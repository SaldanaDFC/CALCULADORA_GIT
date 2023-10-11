#include<stdio.h>
//funciones arreglos
void leer_arreglo(int num[]);
int sumar_arreglo(int num[]);
//funciones
int suma(int a, int b);
int multiplicacion(int a, int b);
int resta(int a, int b);
double division(int a, int b);
//main
int main (void)
{
//Variables
  int num1,num2;
  char c;
  int numeros_caso_a[10];
  int res = 0;
//Procesos
  printf("\n\n¿Que tipo de operación quieres hacer? [+,-,*,/]\n ");
  scanf("%c", &c);
  switch(c){
      case '+':
      {
	    printf("\n\nSuma");
	    printf("\nIngresa dos numeros: [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    res=suma(num1,num2);
	    break;
      }
      
      case '-':
      {
	    printf("\n\nResta");
	    printf("\nIngresa dos numeros: [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    res=resta(num1,num2);
	    break;
      }
      
      case '/':
      {
	    printf("\n\nDivisión");
	    printf("\nIngresa dos numeros(n1/n2): [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    res=division(num1,num2);
	    break;
      }
      
      case '*':
      {
	    printf("\n\nMultpiplicación");
	    printf("\nIngresa dos numeros: [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    res=multiplicacion(num1,num2);
	    break;
      }

      case 'a':
      {
        leer_arreglo(numeros_caso_a);
        printf("\n\n");
        res = sumar_arreglo(numeros_caso_a);

        printf("Tu respuesta para %c:   %d", c, res);
      }

    }

//FIN DEL PROGRAMA
  printf("Tu respuesta para %c :   %d", c, res);
  printf("\n\n\tPrograma Finalizado con ÉXTO\n\n");
  return 0;
}
//funciones
int suma(int a, int b){
  int s;
  s=a+b;
  return s;
}
int multiplicacion(int a, int b){
  int m;
  m=a*b;
  return m;
}
int resta(int a, int b){
  int r;
  r=a*b;
  return r;
}
double division(int a, int b){
  int d, dv;
  d=a/b;
  dv=(double)a;
  return dv;
}
//funciones arreglos
void leer_arreglo(int num[])
{
    int i;

    for (i = 0; i < 10 ; i++)
    {
        scanf("%i", &num[i]);
    }
}

int sumar_arreglo(int num[])
{
    int i;
    int res = 0;

    for(i = 0; i < 10; i++)
    {
        printf("%d   ", num[i]);
        res = res + num[i];
    }

    return res;
}
