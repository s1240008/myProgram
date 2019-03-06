#include<stdio.h>
#include<math.h>

#define PI M_PI

int main(){
  double a,b;
  int i;

  for(i=-1000; i<=1000; i+=1){
    a=i*0.001;
    //b=PI*(a+1);
    //b=PI*a*a;
    b=PI*a*a*a;
    
    printf("%f %f\n",exp(a)*cos(b),exp(a)*sin(b));
  }
  
  return 0;
}
