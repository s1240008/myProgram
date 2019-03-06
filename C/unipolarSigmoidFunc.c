#include<stdio.h>
#include<math.h>

int main(){
  double u;
  for(u=-6.0; 1000*u<=6000; u+=0.001){
    printf("%f %f\n",u,1/(1+exp(-u)));
  }
  return 0;
}
