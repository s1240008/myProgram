#include<stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX 30
#define N 100

FILE *fpin, *fpKind;
char kind[N][MAX];

char kakeiboFile[MAX]="KAKEIBO_",kindFile[MAX]="kind.txt";
int m,d,k,pay,f=0;
char date[MAX],str[MAX];


int strlen(char str[]){
  int i;
  for(i=0;str[i]!='\0';i++);
  return i;
}

void strcat(char *str1,char str2[]){
  int len1=strlen(str1),len2=strlen(str2),i;

  for(i=0;i<len2;i++){
    str1[i+len1]=str2[i];
  }str1[i+len1]='\0';
}

void strcpy(char *str1,char str2[]){
  int len=strlen(str2),i;

  for(i=0;i<len;i++){
    str1[i]=str2[i];
  }str1[i]='\0';
}

void makeDate(char *date, int m, int d){
  if(m<10){
    date[0]='0';
    date[1]='0'+m;
  }
  else{

    date[0]='1';
    date[1]='0'+m%10;
  }

  date[2]='/';
  
  if(d<10){
    date[3]='0';
    date[4]='0'+d;
  }
  else{
    date[3]='0'+d/10;
    date[4]='0'+d%10;
  }
  date[5]='\0';

}

void makeFile(char *file, int m){
  char txt[5]=".txt",month[3];
  int len=strlen(file);

  strcpy(file,"KAKEIBO_");
   
  if(m<10){
    month[0]='0';
    month[1]='0'+m;
  }
  else{

    month[0]='1';
    month[1]='0'+m%10;
  }

  month[2]='\0';
  
  strcat(file,month);
  strcat(file,txt);
}

int readFile(){
  int i;
  
  if((fpKind=fopen(kindFile,"r"))==NULL){
    fprintf(stderr, "Fail to open file.\n");
    return 1;
  }
  for(i=0;;i++){
    if(fscanf(fpKind,"%s",kind[i])==EOF)break;
  }
  fclose(fpKind);
  
  printf("input chack month\n");
  scanf("%d",&m);

  makeFile(kakeiboFile,m);
  
  if((fpin=fopen(kakeiboFile,"r"))==NULL){
    fprintf(stderr, "Fail to open file.\n");
    return 1;
  }
  while(fscanf(fpin,"%d %d %d %d",&m,&d,&k,&pay)!=EOF){
    makeDate(date,m,d);
    printf("Date:%s Place:%s Pay:%d\n",date,kind[k],pay);
  }
  
  fclose(fpin);
  
  return 0;
}

int writeFile(){
  int i;
    printf("input date\n");
    printf("ex) 8/1 => 8 1\n");

    scanf("%d %d",&m,&d);
    
    printf("select place\n");
    if((fpKind=fopen(kindFile,"r"))==NULL){
      fprintf(stderr, "Fail to open file.\n");
      f=1;
    }
    
    i=0;
    if(!f){
      for(;;i++){
	if(fscanf(fpKind,"%s",kind[i])==EOF)break;
	printf("%d:%s\n",i,kind[i]);
      }
    }
    printf("%d:その他\n",i);
    fclose(fpKind);
    
    scanf("%d",&k);
    if(k==i){
      if((fpKind=fopen(kindFile,"a"))==NULL){
	fprintf(stderr, "Fail to open file.\n");
	return 1;
      }
      printf("input place name\n");
      scanf("%s",str);
      fprintf(fpKind,"%s\n",str);
      
      fclose(fpKind);   
    }
    printf("input pay\n");
    scanf("%d",&pay);

    makeFile(kakeiboFile,m);
    
    if((fpin=fopen(kakeiboFile,"a"))==NULL){
      fprintf(stderr, "Fail to open file.\n");
      return 1;
    }
    fprintf(fpin,"%d %d %d %d\n",m,d,k,pay);
    fclose(fpin);
    
    return 0;
}

void sumOfPay(){
  int sum=0;
  printf("input chack month\n");
  scanf("%d",&m);

  makeFile(kakeiboFile,m);
  
  if((fpin=fopen(kakeiboFile,"r"))==NULL){
    fprintf(stderr, "Fail to open file.\n");
  }
  while(fscanf(fpin,"%d %d %d %d",&m,&d,&k,&pay)!=EOF){
    sum+=pay;
  }
  
  fclose(fpin);
  printf("sum:%d\n",sum);
}

int main(){
  int i,com;

  printf("input command\n");
  printf("0:read kakeibo file\n");
  printf("1:write kakeibo file\n");
  printf("2:read and write kakeibo file\n");
  printf("3:sum of kakeibo pay\n");
  scanf("%d",&com);

  switch(com){
    //read kakeibo file
  case 0:
    readFile();
    break;

    //write kakeibo file
  case 1:
    writeFile();
    break;

    //read and write kakeibo file
  case 2:
    if(readFile())break;
    strcpy(kakeiboFile,"KAKEIBO_");
    if(writeFile())break;
    sumOfPay();
    break;

  //sum of kakeibo pay
  case 3:
    sumOfPay();  
  }

  return 0;
}
