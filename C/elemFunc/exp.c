#include<stdio.h>

//#define INF 10000

double myExp(int);
double myFactorial(int);
double myPow(int,int);

int inf=1;

int main(){
  int n,i;

  scanf("%d",&n);

  for(i=0;i<5;i++){
    printf("%5d: %d:%f\n",inf,n,myExp(n));
    inf*=10;
  }
  
  return 0;
}

//return exp^n
double myExp(int n){
  double exp=0;
  int i;
  for(i=0;i<inf;i++){
    exp+=(1/myFactorial(i))*myPow(n,i);
  }
  return exp;
}

//return i!
double myFactorial(int i){
  if(i==0)return 1;
  else return i*myFactorial(i-1);
}

//return n^i
double myPow(int n,int i){
  int j;
  double pow=1;
  for(j=0;j<i;j++)pow*=n;
  return pow;
}
