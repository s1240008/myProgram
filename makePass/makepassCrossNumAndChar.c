#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 30

int rand(void);
int strlen(char []);
char *crossNumAndChar(char []);
char mark(void);
void shuffle(int *,int);
void inseartChar(char *,char);
char upper(char);
char lower(char);

int main(){
  char str[N];

  scanf("%s",str);

  printf("input: %s, pass:%s\n",str,crossNumAndChar(str));

  return 0;
}

int rand(void){
  time_t timer=time(NULL);
  struct tm *local=localtime(&timer);

  static int x = 123897478;
  static int y = 156734555;
  static int z = 693751985;
  static int r = 25252;

  int t = x ^ x << (local->tm_sec)%20+1;
  x = y;
  y = z;
  z = r;
  r ^= r >> 19 ^ t ^ t >> 8;

  return r;
}

int strlen(char str[]){
  int i;
  for(i=0; str[i]!='\0'; i++);
  return i;
}

char *crossNumAndChar(char str[]){
  int i,len=strlen(str),num[len];
  char *word;
  char c;

  word = malloc(len*2+len/5+2);
  
  for(i=0;i<len;i++)num[i]=i;
  shuffle(num,len);

  printf("num:");
  for(i=0;i<len;i++)printf("%d ",num[i]);
  printf("\n");
  
  for(i=0;i<len;i++){
    word[i*2]='0'+num[i]%10;
    if(i%2==0){
      word[i*2+1]=upper(str[num[i]]);
    }
    else{
      word[i*2+1]=lower(str[num[i]]);
    }
  }
  word[i*2]='\0';

  for(i=0;i<len/5+1;i++){
    c=mark();
    inseartChar(word,c);
  }

  /*
  for(i=0;i<strlen(word);i++){
    printf("%c ",word[i]);
  }printf("\n");
  */
  
  return word;
}

char mark(void){
  int n=rand()%3;

  switch(n){
  case 0:
    return '+';
  case 1:
    return '-';
  case 2:
    return '*';
    /*
      case 3:
      return '/';
      case 4:
      return '%';
    */
  }
}

void shuffle(int *num,int len){
  int i,buf,r;

  for(i=1;i<len;i++){
    r=rand()%i;
    buf=num[i];
    num[i]=num[r];
    num[r]=buf;
  }
}

void inseartChar(char *str,char c){
  int i,len=strlen(str),r=rand()%len;
  char buf[N];

  printf("char inseart: %d\n",r);
  
  for(i=r; i<len; i++){
    buf[i-r]=str[i];
  }buf[i-r]='\0';

  str[r]=c;

  for(i=0;i<strlen(buf);i++){
    str[r+1+i]=buf[i];
  }str[r+1+i]='\0';
  
}

char upper(char c){
  int diff='a'-'A';
  if(c>='a'&&c<='z'){
    c-=diff;
  }
  return c;
}

char lower(char c){
  int diff='a'-'A';
  if(c>='A'&&c<='Z'){
    c+=diff;
  }
  return c;
}
