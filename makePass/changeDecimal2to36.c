#include<stdio.h>
#define N 100

int before, after;
char str[N];

int strlen(char t[]){
  int i;
  for(i=0;t[i]!='\0';i++);
  return i;
}

void printResult(){
  int i,len=strlen(str);
  char t[N];

  //printf("%s\n",str);
  for(i=0;i<len;i++){
    t[i]=str[len-i-1];
  }
  
  for(i=0;i<len;i++){
    str[i]=t[i];
  }str[i]='\0';
  
  printf("%s\n",str);
  
}

char changeIntToChar(int i){
  if(0<=i&&i<=9)return '0'+i;
  else return 'A'+i-10;
}

void changeToAfter(int d){
  int i=0;
  while(d/after!=0){
    str[i]=changeIntToChar(d%after);
    d/=after;
    i++;
  }
  str[i]=changeIntToChar(d%after);
  str[i+1]='\0';
}


int changeCharToInt(char c){
  if('0'<=c&&c<='9')return (int)(c-'0');
  else if('A'<=c&&c<='Z')return (int)(c-'A'+10);
  else if('a'<=c&&c<='z')return (int)(c-'a'+10);
}

int changeTo10(){
  int i,d,l=1,len=strlen(str);
  d=0;
  for(i=0;i<len;i++){
    d+=(l*changeCharToInt(str[len-i-1]));
    l*=before;
  }
  return d;
}

void changeDecimal(){
  int d;
  d = changeTo10();
  changeToAfter(d);
}

int main(){
  int result;
  
  while(1){
    result = scanf("%d %d",&before,&after);

    if(result==EOF)break;
    if(before<2||before>36){
      printf("It is invalid number\n");
      printf("before range is 2<=before<=36\n");
      continue;
    }
    if(after<2||after>36){
      printf("It is invalid number\n");
      printf("after range is 2<=after<=36\n");
      continue;
    }
    scanf("%s",str);
   
    changeDecimal();
   
    printResult();

  }
  
  return 0;
}
