#include<stdio.h>
#include <stdlib.h>

#define MAX 30

FILE *fp;

int strlen(char str[]){
  int i;
  for(i=0;str[i]!='\0';i++);
  return i;
}

void strcat(char *str1, char *str2){
  int len1=strlen(str1),len2=strlen(str2),i;

  for(i=0;i<len2;i++){
    str1[i+len1]=str2[i];
  }str1[i+len1]='\0';
}

int main(){
  char filename[MAX]="file_";
  char txt[MAX]=".txt";
  char str[MAX];

  scanf("%s",str);

  strcat(filename,str);
  strcat(filename,txt);

  int len = strlen(filename);
  filename[len]='\0';

  if ((fp = fopen(filename, "a")) == NULL) {
    fprintf(stderr, "Fail to open file.\n");
    return EXIT_FAILURE;
  }

  fprintf(fp,"%s",str);

  fclose(fp);
  return 0;
}
