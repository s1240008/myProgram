#include<stdio.h>

#define MAX 30

int strlen(char t[]){
  int i;
  for(i=0;t[i]!='\0';i++);
  return i;
}

void changeIntsToChar(char *str,int d){
  int i;
  char t[MAX];

  for(i=0;;i++){
    if(d/10==0)break;
    str[i]='0'+d%10;
    d/=10;
  }str[i]='0'+d;

  str[i+1]='\0';

  //printf("%s\n",str);
  
  int len = strlen(str);
  
  for(i=0;i<len;i++){
    t[i]=str[len-i-1];
  }
  
  for(i=0;i<len;i++){
    str[i]=t[i];
  }

  //printf("%s\n",str);
}

void main(){
  int d;
  char str[MAX];
  
  scanf("%d",&d);
  changeIntsToChar(str,d);
  printf("%s\n",str);
}
