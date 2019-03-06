#include<stdio.h>
#include<math.h>

double inner(double x[], double y[]){
  Double sum=0.0;
  int i;
  for(i=0;i<2;i++){
    sum+=x[i]*y[i];
  }
  return sum;
}

void innerProduct(void){
  double x[2],y[2];
  int t=0,i;
  
  while(1){
    for(i=0;i<2;i++){
      if(scanf("%lf",&x[i])==EOF){
	t=1;
	break;
      }
    }
    if(t)break;
    for(i=0;i<2;i++){
      scanf("%lf",&y[i]);
    }
    printf("( %f , %f ) , ",x[0],x[1]);
    printf("( %f , %f ) : ",y[0],y[1]);
    printf("%f\n",inner(x,y)/(sqrt(inner(x,x))*sqrt(inner(y,y))));
  }
}

int main(){
  innerProduct();
  return 0;
}
