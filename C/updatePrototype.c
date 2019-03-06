#include<stdio.h>

void update(double x[],double *r, double a){
  int i;
  for(i=0;i<2;i++){
    if(r[2]==x[2])r[i]=r[i]+a*(x[i]-r[i]);
    else r[i]=r[i]-a*(x[i]-r[i]);
  }
}

void updatePrototype(void){
  double x[3],r[3],a=0.50;
  int i,t=0;

  while(1){
    for(i=0;i<3;i++){
      if(scanf("%lf",&x[i])==EOF){
	t=1;
	break;
      }
    }
    if(t)break;
    for(i=0;i<3;i++)scanf("%lf",&r[i]);
    update(x,r,a);
    printf("r = %f %f %d;\n",r[0],r[1],(int)r[2]);
  }
  
}

int main(){
  updatePrototype();
  return 0;
}
