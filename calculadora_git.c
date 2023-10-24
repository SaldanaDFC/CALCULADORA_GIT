#include<stdio.h>
#include<math.h>
//funciones arreglos
void leer_arreglo(int num[]);
int sumar_arreglo(int num[]);
//funciones
int suma(int a, int b);
int multiplicacion(int a, int b);
int resta(int a, int b);
double division(int a, int b);
int factorial(int a);
int factorial_rec(int a);
double euler(int a);
void eq_cuadr(double a, double b, double c, double *r1,double *r2);
int serie_fib(int val_final);
void triangulo_fib(int tam);
//main
int main (void)
{
//Variables
  int num1,num2;
  char c;
  double db;
  double v1,v2,v3,res1,res2;
  int numeros_caso_a[10];
  int res = 0;
//Procesos
  printf("\n\t\t***********-MENU-***********\n");
  printf("\t\t| + (SUMA )     -  (RESTA) |\n");
  printf("\t\t| * (MULTi)     /  (DIVIS) |\n");
  printf("\t\t| f (facto)     F  (FACTO) |\n");
  printf("\t\t| e (EULER)     c  (e.cud) |\n");
  printf("\t\t| i (fibonacci) p (leibiz) |\n");
  printf("\t\t****************************\n");
  printf("¿Que tipo de operación quieres hacer?\n ");
  scanf("%c", &c);
  switch(c){
      case '+':
      {
	    printf("\nSuma");
	    printf("\nIngresa dos numeros: [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    res=suma(num1,num2);
	    break;
      }
      
      case '-':
      {
	    printf("\nResta");
	    printf("\nIngresa dos numeros: [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    res=resta(num1,num2);
	    break;
      }
      
      case '/':
      {
	    printf("\nDivisión");
	    printf("\nIngresa dos numeros(n1/n2): [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    db=division(num1,num2);
	    printf("Tu respuesta para %c :   %f", c, db);
	    break;
      }
      
      case '*':
      {
	    printf("\nMultpiplicación");
	    printf("\nIngresa dos numeros: [n1,n2]\n");
	    scanf("%d,%d",&num1,&num2);
	    res=multiplicacion(num1,num2);
	    break;
      }

      case 'f':{//factorial
            printf("\nFactorial");
            printf("\nIngresa un numero:\n");
            scanf("%d",&num1);
            res=factorial(num1);
	    printf("Tu respuesta para %c :   %d", c, res);
            break;
      }
	
      case 'F':{//factorial recursion
            printf("\nFactorial");
            printf("\nIngresa un numero:\n");
            scanf("%d",&num1);
            res=factorial_rec(num1);
	    printf("Tu respuesta para %c :   %d", c, res);
            break;
      }
      case 'e':{//factorial recursion
            printf("\nEuler");
            printf("\nIngresa un numero:\n");
            scanf("%d",&num1);
            db=euler(num1);
	    printf("Tu respuesta para %c :   %f", c, db);
            break;
      }
	
      case 'a': {
            leer_arreglo(numeros_caso_a);
            printf("\n");
            res = sumar_arreglo(numeros_caso_a);
            printf("Tu respuesta para %c:   %d", c, res);
      }

      case 'c':{
	    printf("\nEc. Cuadratica");
            printf("\nIngresa los valores: [a,b,c]\n");
            scanf("%lf,%lf,%lf",&v1,&v2,&v3);
	    eq_cuadr(v1,v2,v3,&res1,&res2);
	    if(res1>0 && res2>0){
	      printf("Tu respuestas para %c:   %lf, %lf", c, res1, res2);
	    }
	    else if(res1>0 && (res2 !=0 || res2<0)){
	      printf("\nPara %c\nSolo tienes una respuesta disponible: %lf", c, res1);
	    }
	    else if(res2>0 && (res1 !=0 || res1<0)){
	      printf("\nPara %c\nSolo tienes una respuesta disponible: %lf", c, res2);
	    }
	    else if(res1 !=0 && res2 !=0){
	      printf("No hay respuestas disponibles");
	    }
      }
      case 'i': {
	   do{
           printf("INGRESA UN NUMERO: ");
           scanf("%i",&num1);
           if(num1<0){printf("EL VALOR INGRESADO NO ES VALIDO.");}
           }while(num1<0);
	   triangulo_fib(num1);
      }
    
    }

//FIN DEL PROGRAMA
  
  printf("\n\n\tPrograma Finalizado con ÉXTO\n\n");
  return 0;
}
//******************
//******************
//funciones
//******************
//******************
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
int factorial(int a){
  int i, f;
  f=1;
  for(i=1;i<=a;i++){
     f=f*i;
  }
  return f;
}

int factorial_rec(int a){
  int fr;
  if(a == 0){
    return 1;
  }
  else{
    fr=factorial_rec(a-1);
    return a*fr;
  }
}

double euler(int a){
  int n,i,f,de;
  double eu, db;
  n=a;
  eu=1;
  for(i=1;i<a;i++){
    f=factorial(i);
    db=(double)f;
    eu=eu+(1/db);
  }
  return eu;
}

void eq_cuadr(double a, double b, double c, double *r1,double *r2){
  *r1=(-b+sqrt(b*b-4*a*c))/(2*a);
  *r2=(-b-sqrt(b*b-4*a*c))/(2*a);
}

void triangulo_fib(int tam){
 int i, j;
 int fib;
 printf("Triangulo serie de fibonacci\n");
 fib=serie_fib(tam);
 for(i=-1;i<tam;i++){
     printf("\n");
     for(j=0; j<=i+1;j++){
	printf("%i",serie_fib(j));
     }
 }
printf("\nEl numero en f(%i) es %i\n",tam, fib);
}
int serie_fib(int val_final){
    int i, j;
    int f=0;
    int f2=0;
    int f1=0;
    for(i=0;i<val_final;i++){
      if(i==1){
	f=1;
      }
      f1=f;
      f=f1+f2;			       
      f2=f1;
     }
    if(i==1) return i;
    else return f;
}
//******************
//******************
//funciones arreglos
//******************
//******************
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
