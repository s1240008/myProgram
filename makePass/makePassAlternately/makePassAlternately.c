#include<stdio.h>

#define MAX 30

void makePassAlt(char *, char *);
int inputNum(int, int, char *);
char lastCode(char *);
int sumStr(char *);

int main(){
  char baseStr[MAX];
  char passStr[MAX*2];

  scanf("%s",baseStr);

  makePassAlt(baseStr,passStr);

  printf("%s\n",passStr);
}

void makePassAlt(char str1[], char str2[]){
  int i,j=0;

  for(i=0;str1[i]!='\0';i++){
    str2[j++]='0'+(i%9)+1;
    str2[j++]=str1[i];
  }
  str2[i*2]=lastCode(str1);
  str2[i*2+1]='\0';
}

char lastCode(char str[]){
  int sum=sumStr(str);

  switch(sum%5){
  case 0:
    return '+';
  case 1:
    return '-';
  case 2:
    return '*';
  case 3:
    return '!';
  case 4:
    return '?';
  }

  return '\0';
}

int sumStr(char str[]){
  int sum=0,i;

  for(i=0;str[i]!='\0';i++){
    sum += str[i];
  }

  return sum;
}
