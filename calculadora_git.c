#include<stdio.h>
#include<math.h>
#include "ojitos.h"
//#define n 4
//funciones arreglos
void leer_arreglo(int num[]);
int sumar_arreglo(int num[]);
//funciones
void eq_cuadr(double a, double b, double c, double *r1,double *r2);
void circulo_esfera(double r, double *peri, double*area, double *vol);
//main
int main (void){
//Variables
  int num1,num2;
  double radio;
  double *per,*are,*volumen;
  double perimetro=0, area=0, volum=0;
  double numm1, numm2;
  char c;
  double db;
  double pi;
  double v1,v2,v3,res1,res2;
  int numeros_caso_a[10];
  int res = 0;
  //
  OPERACION historial[10];
  int cuenta=0;
  int i,j;
//Procesos
  while(1){
        if(cuenta>=3){
            for(i=0;i<3;i++){
                printf("Operacion: %c %.2lf %.2lf %.2lf %d %d %d %d\n", historial[i].operacion, historial[i].resultado_double1, historial[i].resultado_double2, historial[i].resultado_double3, historial[i].resultado_int, historial[i].op1, historial[i].op2, historial[i].op3);
            }
            for(j=1;j<3;j++){
                historial[j-1]=historial[j];
            }
            cuenta--;
        }
        printf("\n\t\t***********-MENU-***********\n");
        printf("\t\t| + (SUMA )     -  (RESTA) |\n");
        printf("\t\t| * (MULTi)     /  (DIVIS) |\n");
        printf("\t\t| f (facto)     F  (FACTO) |\n");
        printf("\t\t| e (EULER)     c  (e.cud) |\n");
        printf("\t\t| i (fibonacci) p (leibiz) |\n");
        printf("\t\t| v (pe,ar,vol) a (suma 10)|\n");
        printf("\t\t| m (me,me,mod)            |\n");
        printf("\t\t****************************\n");
        printf("¿Que tipo de operación quieres hacer?\n ");
        scanf("%c", &c);
        getchar();
        switch(c){
            case '+':{
	            printf("\nSuma");
	            printf("\nIngresa dos numeros: [n1,n2]\n");
	            scanf("%d,%d",&num1,&num2);
	            res=suma(num1,num2);
	            printf("\nSuma: %d\n",res);
	            historial[cuenta].operacion=c;
	            historial[cuenta].op1=num1;
	            historial[cuenta].op2=num2;
	            historial[cuenta].resultado_int=res;
	            break;
            }
            case '-':{
	            printf("\nResta");
	            printf("\nIngresa dos numeros: [n1,n2]\n");
	            scanf("%d,%d",&num1,&num2);
	            res=resta(num1,num2);
	            printf("\nResta: %d\n",res);
	            historial[cuenta].operacion=c;
	            historial[cuenta].op1=num1;
	            historial[cuenta].op2=num2;
	            historial[cuenta].resultado_int=res;
	            break;
            }
            case '/':{
	            printf("\nDivisión");
	            printf("\nIngresa dos numeros(n1/n2): [n1,n2]\n");
	            scanf("%lf,%lf",&numm1,&numm2);
	            db=division(numm1,numm2);
	            printf("Tu respuesta para %c :   %f", c, db);
	            historial[cuenta].operacion=c;
	            historial[cuenta].op1=numm1;
	            historial[cuenta].op2=numm2;
	            historial[cuenta].resultado_double1=db;
	            break;
            }
            case '*':{
	            printf("\nMultpiplicación");
	            printf("\nIngresa dos numeros: [n1,n2]\n");
	            scanf("%d,%d",&num1,&num2);
	            res=multiplicacion(num1,num2);
	            printf("\nMultiplicacion: %d\n",res);
	            historial[cuenta].operacion=c;
	            historial[cuenta].op1=num1;
	            historial[cuenta].op2=num2;
	            historial[cuenta].resultado_int=res;
	            break;
            }
            case 'f':{//factorial
                printf("\nFactorial");
                printf("\nIngresa un numero:\n");
                scanf("%d",&num1);
                res=factorial(num1);
	            printf("Tu respuesta para %c :   %d", c, res);
	            historial[cuenta].operacion=c;
	            historial[cuenta].op1=num1;
	            historial[cuenta].resultado_int=res;
                break;
            }
            case 'F':{//factorial recursion
                printf("\nFactorial");
                printf("\nIngresa un numero:\n");
                scanf("%d",&num1);
                res=factorial_rec(num1);
	            printf("Tu respuesta para %c :   %d", c, res);
	            historial[cuenta].operacion=c;
	            historial[cuenta].op1=num1;
	            historial[cuenta].resultado_int=res;
                break;
            }
            case 'e':{//EULER
                printf("\nEuler");
                printf("\nIngresa un numero:\n");
                scanf("%d",&num1);
                db=euler(num1);
	            printf("Tu respuesta para %c :   %f", c, db);
	            historial[cuenta].operacion=c;
	            historial[cuenta].op1=num1;
	            historial[cuenta].resultado_double1=db;
                break;
            }
            case 'a': {
                leer_arreglo(numeros_caso_a);
                printf("\n");
                res = sumar_arreglo(numeros_caso_a);
                printf("Tu respuesta para %c:   %d", c, res);
                historial[cuenta].operacion=c;
	            historial[cuenta].resultado_int=res;
	            break;
            }
            case 'c':{
	            printf("\nEc. Cuadratica");
                printf("\nIngresa los valores: [a,b,c]\n");
                scanf("%lf,%lf,%lf",&v1,&v2,&v3);
	            eq_cuadr(v1,v2,v3,&res1,&res2);
	            if(res1>0 && res2>0){
	                printf("Tu respuestas para %c:   %lf, %lf", c, res1, res2);
	                historial[cuenta].operacion=c;
	                historial[cuenta].op1=v1;
	                historial[cuenta].op2=v2;
	                historial[cuenta].op3=v3;
	                historial[cuenta].resultado_double1=res1;
	                historial[cuenta].resultado_double2=res2;
	            }
	            else if(res1>0 && (res2 !=0 || res2<0)){
	                printf("\nPara %c\nSolo tienes una respuesta disponible: %lf", c, res1);
	            }
	            else if(res2>0 && (res1 !=0 || res1<0)){
	                printf("\nPara %c\nSolo tienes una respuesta disponible: %lf", c, res2);
	                historial[cuenta].operacion=c;
	                historial[cuenta].op1=num1;
	                
	                historial[cuenta].resultado_double3=db;
	            }
	            else if(res1 !=0 && res2 !=0){
	                printf("No hay respuestas disponibles");
	            }
	            break;
            }
            case 'i': {
	            do{
                printf("INGRESA UN NUMERO: ");
                scanf("%i",&num1);
                if(num1<0){printf("EL VALOR INGRESADO NO ES VALIDO.");}
                }while(num1<0);
	            triangulo_fib(num1);
	            break;
            }
            case 'p':{
                printf("Ingresa un numero: ");
                scanf("%i",&num1);
                pi=serieLebniz(num1);
                printf("\n%lf\n",pi);
	            break;
            }
            case'v':{
                printf("Ingresa el radio: ");
	            scanf("%lf",&radio);
	            per=&perimetro;
	            are=&area;
	            volumen=&volum;
	            circulo_esfera(radio,per,are,volumen);
	            printf("\nRadio     = %lf",radio);
	            printf("\nPerimetro = %lf",*per);
	            printf("\nArea      = %lf",*are);
	            printf("\nVolumen   = %lf",*volumen);
	            break;
            }
            case 'm':{
                //media, mediana y moda
                
            }
        }
        getchar();
        cuenta++;
    }
//FIN DEL PROGRAMA
  
  printf("\n\n\tPrograma Finalizado con ÉXTO\n\n");
  return 0;
}

//funciones

void eq_cuadr(double a, double b, double c, double *r1,double *r2){
  *r1=(-b+sqrt(b*b-4*a*c))/(2*a);
  *r2=(-b-sqrt(b*b-4*a*c))/(2*a);
}

void circulo_esfera(double r, double *peri, double*area, double *vol){
  double pi;
  printf("Ingresa un valor: ");
  scanf("%lf",&pi);
  pi=serieLebniz(pi);
  *peri=2*pi*r;
  *area=pi*(r*r);
  *vol=(4/3)*(pi)*(r*r*r);
}
//******************
//******************
//funciones arreglos
//'a' suma 10 numeros
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
