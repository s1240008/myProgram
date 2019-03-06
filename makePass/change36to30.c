#include<stdio.h>

#define MAX 30

int d;
char str[MAX];

int strlen(char t[]){
  int i;
  for(i=0;t[i]!='\0';i++);
  return i;
}

void changeStrLow(){
  int i,len=strlen(str);
  
  for(i=0;i<len;i++){
    if('0'<=str[i]&&str[i]<='9')str[i]=str[i];
    else str[i]='a'+str[i]-'A';
  }
  
}

int changeCharToInt(char c){
  if('0'<=c&&c<='9')return (int)(c-'0');
  else if('A'<=c&&c<='Z')return (int)(c-'A'+10);
  else if('a'<=c&&c<='z')return (int)(c-'a'+10);
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
  str[i]='\0';
}

char changeIntToChar(int i){
  if(0<=i&&i<=9)return '0'+i;
  else return 'A'+i-10;
}

void change10to30(int d){
  int i=0;
  while(d/30!=0){
    str[i]=changeIntToChar(d%30);
    d/=30;
    i++;
  }
  str[i]=changeIntToChar(d%30);
  str[i+1]='\0';
  backwordRead();
}


void change36to10(char t[]){
  int i,l=1,len=strlen(t);
  d=0;
  for(i=0;i<len;i++){
    d+=(l*changeCharToInt(t[len-i-1]));
    l*=36;
  }
}

void change36to30(char t[]){
  change36to10(t);
  change10to30(d);
}

int main(){
  int i,f=0;
  char str2[MAX];

  while(scanf("%s",str)!=EOF){

    for(i=0;i<strlen(str);i++){
      str2[i]=str[i];
    }str2[i]='\0';
    
    change36to30(str);
    if(f%2!=0)changeStrLow();
    printf("%10s = %10s\n",str2,str);
    f++;
  }
  
  return 0;
}
