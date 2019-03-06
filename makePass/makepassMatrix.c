#include<stdio.h>
#include<time.h>
#include <stdlib.h>

#define MAX 30

struct tm *local;

int passMi[4][4];
char passStr[4][4][MAX];

char str[MAX];

FILE *fp1,*fp2;
char filename[100]="passfile_";

int strlen(char t[]){
  int i;
  for(i=0;t[i]!='\0';i++);
  return i;
}

char *lower(char str[]){
  int len = strlen(str),i;

  for(i=0;i<len;i++){
    if(str[i]>='A'&&str[i]<='Z'){
      str[i]='a'+str[i]-'A';
    }
    else{
      str[i]=str[i];
    }
  }

  return str;
}

char lastCode(int i, int j, int k, int l){
  int sum=passMi[i][0]+passMi[j][1]+passMi[k][2]+passMi[l][3];

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

void printPasses(){
  int i,j,k,l,cnt = 1;

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	for(l=0;l<4;l++){
	  printf("%3d:%s%s%s%s",cnt,passStr[i][0],lower(passStr[j][1]),passStr[k][2],lower(passStr[l][3]));
	  fprintf(fp1,"%3d:%s%s%s%s",cnt,passStr[i][0],lower(passStr[j][1]),passStr[k][2],lower(passStr[l][3]));
	  printf("%c\n",lastCode(i,j,k,l));
	  fprintf(fp1,"%c\n",lastCode(i,j,k,l));
	  cnt++;
	}
      }
    }
  }
}

void selectPass(){
  srand((unsigned)time(NULL));
  int random = rand()%256,key[4],r;

  r=random;
  key[3]=random%4;
  random/=4;
  key[2]=random%4;
  random/=4;
  key[1]=random%4;
  random/=4;
  key[0]=random%4;

  printf("%3d:%s%s%s%s",r+1,passStr[key[0]][0],lower(passStr[key[1]][1]),passStr[key[2]][2],lower(passStr[key[3]][3]));
  fprintf(fp1,"%3d:%s%s%s%s",r+1,passStr[key[0]][0],lower(passStr[key[1]][1]),passStr[key[2]][2],lower(passStr[key[3]][3]));
  fprintf(fp2,"%3d:%s%s%s%s",r+1,passStr[key[0]][0],lower(passStr[key[1]][1]),passStr[key[2]][2],lower(passStr[key[3]][3]));
  printf("%c\n",lastCode(key[0],key[1],key[2],key[3]));
  fprintf(fp1,"%c\n",lastCode(key[0],key[1],key[2],key[3]));
  fprintf(fp2,"%c\n",lastCode(key[0],key[1],key[2],key[3]));
  
}

void strcopy(char str1[], char str2[]){
  int len = strlen(str1),i;

  for(i=0;i<len;i++){
    str2[i]=str1[i];
  }str2[i]='\0';
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

void change10to36(int d){
  int i=0;
  while(d/36!=0){
    str[i]=changeIntToChar(d%36);
    d/=36;
    i++;
  }
  str[i]=changeIntToChar(d%36);
  backwordRead();
}

int changeCharToInt(char c){
  if('0'<=c&&c<='9')return (int)(c-'0');
  else if('A'<=c&&c<='Z')return (int)(c-'A'+10);
  else if('a'<=c&&c<='z')return (int)(c-'a'+10);
}

void strcat(char *str1,char str2[]){
  int len1=strlen(str1),len2=strlen(str2),i;

  for(i=0;i<len2;i++){
    str1[i+len1]=str2[i];
  }str1[i+len1]='\0';
}

void changeIntsToChar(char *strRe,int d){
  int i;
  char t[MAX];

  for(i=0;;i++){
    if(d/10==0)break;
    strRe[i]='0'+d%10;
    d/=10;
  }if(d>0)strRe[i]='0'+d;

  strRe[i+1]='\0';

  int len = strlen(strRe);
  
  for(i=0;i<len;i++){
    t[i]=strRe[len-i-1];
  }
  
  for(i=0;i<len;i++){
    strRe[i]=t[i];
  }

}

void strdate(char date[],int y,int m,int d){
  char num[MAX];
  int len,i;
  
  changeIntsToChar(num,y);
  len = strlen(num);
  for(i=0;i<len;i++){
    date[i]=num[i];
  }
  //printf("%s\n",date);
  //printf("%s\n",num);
  changeIntsToChar(num,m);
  if(m<10){
    num[1]=num[0];
    num[0]='0';
    num[2]='\0';
  }
  strcat(date,num);
  changeIntsToChar(num,d);
  if(d<10){
    num[1]=num[0];
    num[0]='0';
    num[2]='\0';
  }
  strcat(date,num);
}

void makeFilename1(char cm[],char date[]){
  int len;
  char text[5]=".txt",underbar[2]="_";
  strcat(filename,cm);
  len = strlen(filename);

  strcat(filename,underbar);
  strcat(filename,date);
  len = strlen(filename);

  strcat(filename,text);
  len = strlen(filename);
  filename[len]='\0';
}

void extraction(char str1[]){
  char str2[MAX] = "passfile_";
  int len=strlen(str1)+strlen(str2);

  filename[len]='\0';  
}

void makeFilename2(char cm[]){
  int len;
  char text[5]=".txt";
  extraction(cm);
  strcat(filename,text);
  len = strlen(filename);
  filename[len]='\0';
}

int main(){
  time_t timer;
  int i,j,y,m,d,dm[4],cim[4];
  char cm[MAX],date[MAX];

  scanf("%s",cm);
  for(i=0;i<4;i++){
    cim[i]=changeCharToInt(cm[i]);
    printf("%d ",cim[i]);
  }printf("\n");
  
  /* 現在時刻を取得 */
  timer = time(NULL);
  local = localtime(&timer); /* 地方時に変換 */

  y=local->tm_year + 1900;
  m=local->tm_mon + 1;
  d=local->tm_mday;

  strdate(date,y,m,d);
  //printf("%s\n",date);
  makeFilename1(cm,date);

  printf("filename is %s\n",filename);
  
  if ((fp1 = fopen(filename, "a")) == NULL) {
    fprintf(stderr, "Fail to open file.\n");
    return EXIT_FAILURE;
  }
  
  makeFilename2(cm);
  if ((fp2 = fopen(filename, "a")) == NULL) {
    fprintf(stderr, "Fail to open file.\n");
    return EXIT_FAILURE;
  }

  fprintf(fp1,"\n\n");
  fprintf(fp2,"\n\n");
  
  printf("%d.%d.%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);
  fprintf(fp1,"%d.%d.%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);
  fprintf(fp2,"%d.%d.%d\n", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);

  dm[0]=y/100;
  dm[1]=y%100;
  dm[2]=m;
  dm[3]=d;

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      passMi[i][j]=dm[i]*cim[j];
    }
  }

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      change10to36(passMi[i][j]);
      strcopy(str,passStr[i][j]);
      printf("%3s",str);
      fprintf(fp1,"%3s",str);
      
      if(j<3){
	printf(" ");
	fprintf(fp1," ");
      }
    }
    printf("\n");
    fprintf(fp1,"\n");
  }

  printPasses();
  fprintf(fp1,"\n");
  selectPass();
  fclose(fp1);
  fclose(fp2);
}
