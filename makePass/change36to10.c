#include<stdio.h>

#define MAX 30

int d;

int strlen(char t[]){
  int i;
  for(i=0;t[i]!='\0';i++);
  return i;
}

int changeCharToInt(char c){
  if('0'<=c&&c<='9')return (int)(c-'0');
  else if('A'<=c&&c<='Z')return (int)(c-'A'+10);
  else if('a'<=c&&c<='z')return (int)(c-'a'+10);
}

void change36to10(char str[]){
  int i,l=1,len=strlen(str);
  d=0;
  for(i=0;i<len;i++){
    d+=(l*changeCharToInt(str[len-i-1]));
    l*=36;
  }
}

int main(){
  char str[MAX];

  while(scanf("%s",str)!=EOF){
    change36to10(str);
    printf("%s = %d\n",str,d);
  }
  
  return 0;
}
