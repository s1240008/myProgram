#include<stdio.h>

int main(){
  int x;
  
  while(scanf("%d",&x)!=EOF){
    if(x<10){
      printf("%3d: %c\n",x,(char)x+'0');
    }
    else printf("%3d: %c\n",x,(char)(x-10+'A'));    
  }

  return 0;
}
