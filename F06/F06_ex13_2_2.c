#include<stdio.h>

void sort(int *);

int main(){
  int queue[9]={86,1470,913,1774,948,1509,1022,1750,130};
  int head=143, i, n;
	
  sort(queue);

  for(i=0;i<9;i++){
    if(queue[i+1]>head)break;
  }
  n = i;

  printf("%d\n",head);

  for(i=n+1;i<9;i++){
    printf("%d\n",queue[i]);
  }
  
  printf("4999\n");
  printf("0\n");

  for(i=0;i<=n;i++){
    printf("%d\n",queue[i]);
  }

  return 0;
}

void sort(int *queue){
  int i, j, tmp;

  for(i=0;i<8;i++){
    for(j=i+1;j<9;j++){
      if(queue[i]>queue[j]){
	tmp = queue[i];
	queue[i] = queue[j];
	queue[j] = tmp;
      }
    }
  }
  
}
