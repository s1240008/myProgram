//gcc -lm CorrelationCoefficient.c
//相関係数を計算する

#include<stdio.h>
#include<math.h>

#define MAX 100

int n;

double nijo(double x){
  return x*x;
}

double sum(double A[]){
  int i;
  double sum=0.0;
  
  for(i=0;i<n;i++){
    sum+=A[i];
  }
  return sum;
}

int main(){
  double A[2][MAX],c=0.0,sum1,sum2;
  int i,j;
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    for(j=0;j<2;j++){
      scanf("%lf",&A[j][i]);
    }

  sum1=sum(A[0]);
  sum2=sum(A[1]);
  
  for(i=0;i<n;i++){
    c+=(A[0][i]-sum1/n)*(A[1][i]-sum2/n);
    A[0][i]-=sum1/n;
    A[0][i]=nijo(A[0][i]);
    A[1][i]-=sum2/n;      
    A[1][i]=nijo(A[1][i]);
  }
  sum1=sum(A[0]);
  sum2=sum(A[1]);

  printf("r = %f\n",c/(sqrt(sum1)*sqrt(sum2)));  

  return 0;
}
