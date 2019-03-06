#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int strlen(char *);
void strcat(char *,char *);
void strcpy(char *,char *);

/* main */
int main(void) {
    char com[200] = "gs -q -dNOPAUSE -dBATCH -sDEVICE=pdfwrite -sOutputFile=";
    char pdf1[] = ".pdf";
    char pdf2[] = "*.pdf";
    char name[50];
    
    printf("what name is collected file?\n");
    scanf("%s",name);
    strcat(name,pdf1);
    strcpy(pdf1,name);

    printf("%s\n",pdf1);
    
    strcpy(name,"");
    
    printf("what name is collect files?\n");
    scanf("%s",name);
    strcat(name,pdf2);
    strcpy(pdf2,name);

    printf("%s\n",pdf2);
    
    printf("a\n");
    
    strcat(com,pdf1);
    strcat(com," ");
    printf("b\n");
    strcat(com,pdf2);

    printf("c\n");
    
    system(com);

    return EXIT_SUCCESS;
}

int strlen(char str1[]){
  int i;
  for(i=0;str1[i]!='\0';i++);
  return i;
}

void strcat(char str1[],char str2[]){
  int i,len1=strlen(str1),len2=strlen(str2);
  printf("len1=%d\n",len1);
  printf("len2=%d\n",len2);
  
  for(i=len1;i<len1+len2;i++){
    str1[i]=str2[i-len1];
  }str1[i]='\0';
}

void strcpy(char str1[],char str2[]){
  int i,len2;

  for(i=0;i<len2;i++){
    str1[i]=str2[i];
  }str1[i]='\0';
}
