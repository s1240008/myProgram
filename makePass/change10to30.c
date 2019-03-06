#include<stdio.h>
#define MAX 30

char str[MAX];

int strlen(char t[]){
  int i;
  for(i=0;t[i]!='\0';i++);
  return i;
}

void backwordRead(){
  int i,len=strlen(str);
  char t[MAX];

  for(i=0;i<len;i++){
    t[i]=str[len-i-1];
  }
  
  for(i=0;i<len;i++){
    str[i]=t[i];
  }
  
}

char changeIntToChar(int i){
  if(0<=i&&i<=9)return '0'+i;
  else return 'A'+i-10;
}

void change10to30(int d){
  int i=0;
  while(d/30!=0){
    str[i]=changeIntToChar(d%30);
    d/=30;
    i++;
  }
  str[i]=changeIntToChar(d%30);
  backwordRead();
}


int main(){
  int d;
  while(scanf("%d",&d)!=EOF){
    change10to30(d);
    printf("%d = %s\n",d,str);
  }
}
