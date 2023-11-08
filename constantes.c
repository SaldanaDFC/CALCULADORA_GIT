#include<stdio.h>
#include "ojitos.h"
//EULER
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
//PI|
double serieLebniz(int n){
  int i;
  double res, nump;
  nump=1;
  res=0;
  int change=1;
  for(i=1;i<=n;i++){
    if(change==1){
      res=res+(1/nump);
      change=2;
    }
    else if(change==2){
      res=res-(1/nump);
      change=1;
    }
    nump+=2;
    
  }
  return res*4;
}
