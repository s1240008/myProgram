#include<stdio.h>
#include<math.h>

int main(){
  double n[4]={100,200,300,500},w[4],s=100,t=16*pow(10,-6),c=pow(10,7),e;
  int i,j;

  for(i=0;i<4;i++){
    w[i] = pow(n[i]/(n[i]-1),n[i]-1) + 1;
  }

  printf("%f\n",c);
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      e = (s/c)/(w[j]*t+s/c);
      //printf("%d: %-6d: e = %f\n",(int)n[j],(int)s,e);
      printf("%f\n",e);
    }
    s*=10;
    printf("\n");
  }

  c*=10;
  s=100;
  
  printf("%f\n",c);
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      e = (s/c)/(w[j]*t+s/c);
      //printf("%d: %-6d: e = %f\n",(int)n[j],(int)s,e);
      printf("%f\n",e);
    }
    s*=10;
    printf("\n");
  }

  return 0;
}
