#include<stdio.h>

#define MAX 100

int strlen(char t[]){
  int i;
  for(i=0;t[i]!='\0';i++);
  return i;
}

void strcat(char *str1,char str2[]){
  int len1=strlen(str1),len2=strlen(str2),i;

  for(i=0;i<len2;i++){
    str1[i+len1]=str2[i];
  }str1[i+len1]='\0';
}

void main(){
  char str1[MAX],str2[MAX];

  scanf("%s",str1);
  scanf("%s",str2);

  
  printf("str1: %s\n",str1);
  printf("str2: %s\n",str2);

  strcat(str1,str2);

  printf("str1 + str2: %s\n",str1);
}
