#include<stdio.h>
#include <unistd.h> //using function sleep()

int main(){

  int i,n,m,s;

  scanf("%d %d",&m,&s);

  n=m*60+s;
  
  for(i=0;i<n;i++){
    m=(n-i)/60;
    s=(n-i)%60;
    if(m>0)printf("%d:",m);
    printf("%02d",s);
    fflush(stdout);
    
    sleep(1);
  
    printf("\r     \r");
  }
  return 0;
}
