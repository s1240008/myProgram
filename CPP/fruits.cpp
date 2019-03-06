#include<iostream>
#include<math.h>

using namespace std;

struct Fruit{
  int weight;  
};

Fruit fruits[5][8];
int sum[5],df[8];

int main(){
  int n,i,j;
  char fruit[8][20]={"Apple","Banana","Grape","Lemon","Melon","Orange","Peach","Strawberry"};

  cin >> n;

  for(i=0;i<8;i++)df[i]=0;
  
  for(i=0;i<n;i++){
    sum[i]=0;
    for(j=0;j<8;j++){
      cin >> fruits[i][j].weight;
      sum[i]+=fruits[i][j].weight;
      if(fruits[i][j].weight)df[j]++;
    }
  }

  cout << fruits[0][0].weight << " " << df[0] <<endl;

  cout << log10(10.0) << endl;
  
  for(i=0;i<8;i++){
    cout << fruit[i] << " ";
    printf("%-s :",)
    for(j=0;j<n;j++){
      cout << log10((double)n/df[i])*((double)fruits[j][i].weight/sum[j]) << " ";
    }
    cout << endl;
  }

  return 0;
}
