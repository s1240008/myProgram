#include<iostream>

using namespace std;

int cfizz(int);
int cbuzz(int);

int main(){
  int top,last,i;

  cin >> top >> last;

  for(i=top;i<=last;i++){
    if(cfizz(i)||cbuzz(i)){
      if(i<10)cout << "  ";
      else if(i<100)cout << " ";
      cout << i << " : ";
      if(cfizz(i))cout << "fizz";
      if(cbuzz(i))cout << "buzz";
      cout << endl;
    }
  }

  return 0;
}

int cfizz(int i){
  if(i%3==0)return 1;
  return 0;
}

int cbuzz(int i){
  if(i%5==0)return 1;
  return 0;
}
