#include<stdio.h>
#include<time.h>

int rand(void);

int main(){

  printf("rand: %d\n",rand());
  
  return 0;
}

int rand(void){
  time_t timer=time(NULL);
  struct tm *local=localtime(&timer);

  static int x = 123897478;
  static int y = 156734555;
  static int z = 693751985;
  static int r = 25252;

  int t = x ^ x << (local->tm_sec)%20+1;
  x = y;
  y = z;
  z = r;
  r ^= r >> 19 ^ t ^ t >> 8;

  return r;
}
