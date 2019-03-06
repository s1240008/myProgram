#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

char *randWord(void);

int main(){
    //give rand seed
    srand((unsigned)time(NULL));

    for(int i=0; i<5; i++){
      printf("%s\n",randWord());
    }

  return 0;
}

char *randWord(void){
  char *word;
  int i,n;

  n=rand()%N+1;

  word = malloc(n+1);
  
  for(i=0; i<n; i++){
    if(rand()%2==0){
      word[i]='a'+rand()%26;
    }
    else{
      word[i]='A'+rand()%26;
    }
  }word[i]='\0';

  return word;
}
