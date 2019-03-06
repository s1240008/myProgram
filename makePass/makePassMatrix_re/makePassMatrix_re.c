#include<stdio.h>
#include<time.h>
#include<string.h>
#include <stdlib.h>

#define MAX 30

struct tm *local;
char charMatrix[4][4][MAX];

typedef struct{
  int year;
  int month;
  int day;
}DATE;

void change36to10(char *, int *);
void setNumbers(DATE, int *);
void calcMatrix(int [2][4], int [4][4]);
//void setChar(int [4][4], char [4][4][MAX]);
void setChar(int [4][4], char [4][4][MAX], DATE);
void change10to36(int, char *);
void change10toD(int, char *, int);
void backwordRead(char *);
void upper(char *);
void makeFileName(char *, char *, char *, DATE);
void setDate(char *, DATE);
void printPass(char [4][4][MAX], int [4][4], FILE *, FILE *, DATE);
void makePass(char *, char [4][4][MAX], int [4][4], int, int, int, int);
void randomPass(char *, char [4][4][MAX], int [4][4]);
void lastCode(char *, int *, int [4][4]);

void main(){
  time_t timer;
  DATE date;
  char word[MAX];
  int numbers[2][4];
  int intMatrix[4][4];
  char file1[MAX]="passtxt/",file2[MAX]="passtxt/";
  FILE *fp1, *fp2;
  
  int i,j;
  
  /* 現在時刻を取得 */
  timer = time(NULL);
  local = localtime(&timer); /* 地方時に変換 */

  date.year=local->tm_year + 1900;
  date.month=local->tm_mon + 1;
  date.day=local->tm_mday;
 
  scanf("%s",word);

  setNumbers(date,numbers[0]);
  change36to10(word,numbers[1]);

  calcMatrix(numbers,intMatrix);

  //setChar(intMatrix,charMatrix);
  setChar(intMatrix,charMatrix,date);

  makeFileName(file1, file2, word, date);

  if ((fp1 = fopen(file1, "w")) == NULL) {
    fprintf(stderr, "Fail to open file1.\n");
  }
  
  if ((fp2 = fopen(file2, "a")) == NULL) {
    fprintf(stderr, "Fail to open file2.\n");
  }

  printPass(charMatrix, intMatrix, fp1, fp2, date);
  
  fclose(fp1);
  fclose(fp2);
}

void change36to10(char str[], int num[]){
  int i;
  
  for(i=0;i<4;i++){
    if(str[i]>='0'&&str[i]<='9'){
      num[i]=str[i]-'0';
    }
    else if(str[i]>='a'&&str[i]<='z'){
      num[i]=str[i]-'a'+10;
    }
    else if(str[i]>='A'&&str[i]<='Z'){
      num[i]=str[i]-'A'+10;
    }
  }
}

void setNumbers(DATE date, int num[]){
  num[0]=date.year/100;
  num[1]=date.year%100;
  num[2]=date.month;
  num[3]=date.day;
}

void calcMatrix(int numbers[2][4], int matrix[4][4]){
  int i,j;

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      matrix[i][j]=numbers[0][i]*numbers[1][j];
    }
  }
}

void setChar(int intMatrix[4][4], char charMatrix[4][4][MAX], DATE date){
  int i,j;

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      //change10to36(intMatrix[i][j],charMatrix[i][j]);
      change10toD(intMatrix[i][j],charMatrix[i][j],30+(date.day+j+i*4)%7);      
      if(j%2==1)upper(charMatrix[i][j]);
    }
  }
}

void change10to36(int n, char c[]){
  int i;
  for(i=0;n/36!=0;i++){
    if(n%36<10){
      c[i]='0'+n%36;	  
    }
    else{
      c[i]='a'+n%36-10;
    }
    n/=36;
  }
  if(n<10){
    c[i]='0'+n%36;	  
  }
  else{
    c[i]='a'+n%36-10;
  }
  c[i+1]='\0';
  backwordRead(c);
}

void change10toD(int n, char c[], int d){
  int i;
  for(i=0;n/d!=0;i++){
    if(n%d<10){
      c[i]='0'+n%d;	  
    }
    else{
      c[i]='a'+n%d-10;
    }
    n/=d;
  }
  if(n<10){
    c[i]='0'+n%d;	  
  }
  else{
    c[i]='a'+n%d-10;
  }
  c[i+1]='\0';
  backwordRead(c);
}

void backwordRead(char str[]){
  int i,len=strlen(str);
  char t[MAX];
  
  for(i=0;i<len;i++){
    t[i]=str[len-i-1];
  }
  
  for(i=0;i<len;i++){
    str[i]=t[i];
  }str[i]='\0';
  
}

/*
int strlen(char str[]){
  int i;

  for(i=0;str[i]!='\0';i++);

  return i;
}
*/

void upper(char str[]){
  int i;

  for(i=0;str[i]!='\0';i++){
    if(str[i]>='a'&&str[i]<='z'){
      str[i]='A'+str[i]-'a';
    }
  }
}

void makeFileName(char file1[], char file2[], char word[], DATE date){
  char passfile[]="passfile_";
  char txt[]=".txt";
  char dateStr[MAX]="_";
  setDate(dateStr, date);
  
  strcat(file1,passfile);
  strcat(file2,passfile);

  strcat(file1,word);
  strcat(file2,word);

  strcat(file1,dateStr);

  strcat(file1,txt);
  strcat(file2,txt);
}

void setDate(char str[], DATE date){
  char year[MAX],month[MAX],day[MAX];

  sprintf(year, "%d", date.year);
  sprintf(month, "%02d", date.month);
  sprintf(day, "%02d", date.day);

  strcat(str, year);
  strcat(str, month);
  strcat(str, day);
}

void printPass(char charMatrix[4][4][MAX], int intMatrix[4][4], FILE *fp1, FILE *fp2, DATE date){
  int i,j,k,l;
  char today[MAX]="";
  char pass[MAX];
  setDate(today,date);

  fprintf(fp1,"\n");
  fprintf(fp2,"\n");
  
  fprintf(fp1,"%s\n",today);
  fprintf(fp2,"%s\n",today);
  
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	for(l=0;l<4;l++){
	  pass[0]='\0';
	  makePass(pass, charMatrix, intMatrix,i, j, k, l);
	  fprintf(fp1, "%s\n", pass);
	  printf("%s\n", pass);
	} 
      } 
    }
  }

  pass[0]='\0';
  randomPass(pass, charMatrix, intMatrix);
  fprintf(fp2,"%s\n",pass);
  printf("%s\n",pass);  
}

void makePass(char pass[], char charMatrix[4][4][MAX], int intMatrix[4][4], int i, int j, int k, int l){
  int num[4];
  char last[2];
  strcat(pass,charMatrix[0][i]);
  strcat(pass,charMatrix[1][j]);
  strcat(pass,charMatrix[2][k]);
  strcat(pass,charMatrix[3][l]);
  num[0]=i;
  num[1]=j;
  num[2]=k;
  num[3]=l;
  lastCode(last,num,intMatrix);
  strcat(pass,last);
}

void randomPass(char pass[], char charMatrix[4][4][MAX], int intMatrix[4][4]){
  int i,num[4];
  char last[2];
  for(i=0;i<4;i++){
    srand((unsigned)time(NULL));
    num[i]=rand()%4;
    strcat(pass,charMatrix[i][num[i]]);
  }
  lastCode(last,num,intMatrix);
  strcat(pass,last);
}

void lastCode(char last[],int num[],int intMatrix[4][4]){
  int i,sum=0;

  for(i=0;i<4;i++){
    sum+=intMatrix[i][num[i]];
  }

  switch(sum%5){
  case 0:
    last[0]='+';
    break;
  case 1:
    last[0]='-';
    break;
  case 2:
    last[0]='*';
    break;
  case 3:
    last[0]='!';
    break;
  case 4:
    last[0]='?';
    break;
  }

  last[1]='\0';
}
