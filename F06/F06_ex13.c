#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void add(int *);
void print(int *);

int n;

int main(){
  int a[20],b[12],sum=0,z1,z2,i;

  printf("How many do add num?\n");
  scanf("%d",&n);

  add(a);
  
  print(a);

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  
  for(i=0;i<n-1;i++){
    printf("%d\n",abs(a[b[i]]-a[b[i+1]]));
    sum+=abs(a[b[i]]-a[b[i+1]]);
  }

  printf("sum = %d\n",sum);
  return 0;
}

void add(int *a){
  int i;

  a[0] = 0;

  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  
  a[i] = 4999;

  return;
}

void print(int *a){
  int i=0;
  
  while(i<n+2){
    printf("%d: %d\n",i,a[i]);
    i++;
  }

}
