#include<stdio.h>
#include<math.h>

#define N 1001
#define BLACK 0
#define WHITE 50

void init(int (*a)[N]){
  int i,j,center=N/2+1;

 for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      a[i][j]=WHITE;
      if(i==center||j==center){
	a[i][j]=BLACK;
      }
    } 
  }
}


//y = x
void makeLine1(int (*a)[N]){
  int i,j,n;

  for(i=0;i<N;i++){
    n=i-N/2;
    if(n>N/2)continue;
    a[n+N/2][i]=BLACK;
  }
}

int nijo(int i){
  return i*i;
}

//y = x^2
void makeLine2(int (*a)[N]){
  int i,n;

  for(i=0;i<N;i++){
    n=nijo(i-N/2)/N;
    if(n>N/2)continue;
    a[n+N/2][i]=BLACK;
  }
}

//y = exp(x)
void makeLine3(int (*a)[N]){
  int i,x,n;
  
  for(i=0;i<N;i++){
    x=i-(N/2);
    n=exp((double)x);
    if(n>N/2)continue;
    a[n+N/2][i]=BLACK;
  }
}

int sanjo(int i){
  return i*i*i;
}

//y = x^3
void makeLine4(int (*a)[N]){
  int i,n;

  for(i=0;i<N;i++){
    n=sanjo(i-N/2)/N;
    if(n>N/2)continue;
    a[n+N/2][i]=BLACK;
  }
}


int main(){
  int dat[N][N];

  printf("P2\n");
  printf("%d %d\n",N,N);
  printf("%d\n",WHITE);

  init(dat);

  //makeLine1(dat);
  makeLine2(dat);
  //makeLine3(dat);
  //makeLine4(dat);
  
  int i,j;
  for(i=N-1;i>=0;i--){
    for(j=0;j<N-1;j++){
      printf("%d ",dat[i][j]);
    }printf("%d\n",dat[i][j]);
  }

  return 0;
}
