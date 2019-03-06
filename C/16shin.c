#include<stdio.h>
#include<string.h>

char *change16(int);
char *changeDecimal(int,int);
void rprint(char *);

int main(){
  int n,a;
  char *str;
  
  while(scanf("%d",&n)!=EOF){

    str = change16(n);
    //printf("%s\n",str);
  
    rprint(str);
    
  }

  return 0;
}

char *change16(int n){
  char *str;
  int sub,num='0',alf='A',i=0;
  
  while(n/16>0){
    sub = n%16;
    if(sub>=0&&sub<=9){
      str[i]=num+sub;
    }
    else{
      str[i]=alf+sub-1;
    }
    n/=16;
    i++;
  }

  sub = n%16;
  if(sub>=0&&sub<=9){
    str[i]=num+sub;
  }
  else{
    str[i]=alf+sub-10;
  }
  str[i+1]='\0';
      
  return str;
}

void rprint(char *str){
  int num=strlen(str)-1,i;

  for(i=num;i>=0;i--){
    printf("%c",str[i]);
  }printf("\n");
  
  return;
}
