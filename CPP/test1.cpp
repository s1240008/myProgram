#include <iostream>
 
using namespace std;
 
void ref(int&);
void print(int);
 
int main(){
  int i;

  for(i=0;i<10;i++){
    ref(i);
    print(i);
  }
  return 0;
}
 
void ref(int& n){
  n++;
}

void print(int i){
  cout << "i=" << i << endl;
}
