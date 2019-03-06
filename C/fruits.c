#include<stdio.h>
#include<math.h>

#define VAR 8
#define MAX 10

typedef struct{
  int weight;  
}Fruit;

Fruit fruits[MAX][VAR];
int sum[MAX],df[VAR];

int strlen(char c[]){
  int i;
  for(i=0;c[i]!='\0';i++);
  return i;
}

int main(){
  int n,i,j,max=0;
  char fruit[VAR][20]={"Apple","Banana","Grape","Lemon","Melon","Orange","Peach","Strawberry"};

  scanf("%d",&n);

  for(i=0;i<VAR;i++){
    df[i]=0;
    if(max<strlen(fruit[i])){
      max=strlen(fruit[i]);
    }
  }
  for(i=0;i<n;i++){
    sum[i]=0;
    for(j=0;j<VAR;j++){
      scanf("%d",&(fruits[i][j].weight));
      sum[i]+=fruits[i][j].weight;
      if(fruits[i][j].weight)df[j]++;
    }
  }

  for(i=0;i<VAR;i++){
    printf("%s",fruit[i]);
    for(j=strlen(fruit[i]);j<max;j++)printf(" ");
    printf(": ");
    for(j=0;j<n;j++){
      if(log10((double)n/df[i])*((double)fruits[j][i].weight/sum[j])*1000>0){
	printf("%.4f ",log10((double)n/df[i])*((double)fruits[j][i].weight/sum[j]));
      }
      else printf("       ");
    }
    printf("\n");
  }

  return 0;
}
