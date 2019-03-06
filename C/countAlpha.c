#include<stdio.h>

#define MAX 100

char str[MAX],dic[30];

void printResult(){
  int i;
  
  for(i=0;i<30;i++){
    if(dic[i]==0)continue;
    if(i!=0)printf(" , ");
    printf("%c:%d",i+'A',dic[i]);
  }printf("\n");
}

void countAlpha(){
  int i=0;

  while(str[i]!='\0'){
    dic[str[i]-'A']++;
    i++;
  }
}

void initDic(){
  int i;

  for(i=0;i<30;i++)dic[i]=0;
}

int main(){

  scanf("%s",str);

  initDic();

  countAlpha();

  printResult();
  
  return 0;
}
