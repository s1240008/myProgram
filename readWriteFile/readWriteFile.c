#include<stdio.h>
#include <stdlib.h>

FILE *fp;
char str[50];


int writeFile(){
    if ((fp = fopen("textFile.txt", "a")) == NULL) {
      fprintf(stderr, "Fail to open file.\n");
      return 1;
    }
    scanf("%s",str);
    fprintf(fp,"%s",str);
    fclose(fp);
    return 0;
}

int readFile(){
    if ((fp = fopen("textFile.txt", "r")) == NULL) {
      fprintf(stderr, "Fail to open file.\n");
      return 1;
    }
    while(1){
      if(fscanf(fp,"%s",str)==EOF)break;
      printf("%s\n",str);
    }
    fclose(fp);
    return 0;
}

void readAndWriteFile(){
  if(readFile()==1)return;
  if(writeFile()==1)return;
}

void main(){
  int com;

  scanf("%d",&com);

  switch(com){
  case 0:
    readFile();
    break;
    
  case 1:
    writeFile();
    break;
    
  case 2:
    readAndWriteFile();
    break;
  }
  printf("finished program\n"); 
}
