#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX],n;

int ch2int(char c){
  if('0'<=c&&'9'>=c){
    return c-'0';
  }
  else if('a'<=c&&'z'>=c){
    return c-'a'+10;
  }
  return -1;
}

void calcMatrix(){
  int i,j,k;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  
}

int main(){
  char ch='0';
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%c",&ch);
      if(ch=='\n'||ch==' ')scanf("%c",&ch);
      a[i][j]=ch2int(ch);
      //a[i][j]=ch;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%c",&ch);
      if(ch=='\n'||ch==' ')scanf("%c",&ch);
      b[i][j]=ch2int(ch);
      //b[i][j]=ch;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      c[i][j]=0;
    }
  }

  calcMatrix();

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%3d",a[i][j]);
    }printf("\n");
  }printf("\n");

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%3d",b[i][j]);
    }printf("\n");
  }printf("\n");

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%4d",c[i][j]);
    }printf("\n");
  }

  return 0;
}
