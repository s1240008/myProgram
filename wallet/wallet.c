#include<stdio.h>

#include"wallet.h"

//wallet: the contents of the wallet
//payment: 
//change: the money that you get back when you pay more for something than it costs
int main(){
  WALLET wallet,payment,change;
  
  init(&wallet);
  init(&payment);
  init(&change);

  input(&wallet);

  printf("The value of in Wallet: %d Yen\n",valueInSum(wallet));

  /*
    printf("wallet\n");
    print(wallet);
    printf("payment\n");
    print(payment);
    printf("change\n");
    print(change);
  */

  return 0;  
}

void init(WALLET *w){
  int i;
  for(i=0;i<9;i++)w->contents[i]=0;
}

void print(WALLET w){
  int i;
  for(i=0;i<9;i++)printf("%d: %d\n",i,w.contents[i]);
}

void input(WALLET *w){
  int i;
  printf("Prease input value in wallet\n");
  for(i=0;i<9;i++){
    printf("%10s: ",contentsName[i]);
    scanf("%d",&(w->contents[i]));
  }
}

int valueInSum(WALLET w){
  int i,sum=0;
  for(i=0;i<9;i++)sum+=w.contents[i]*contentsValue[i];
  return sum;
}

WALLET calcChange(WALLET w,int p){
  WALLET buf,c;
  int i[9],sumChange=INFTY,sumContents=INFTY,f=0;

  setWALLET(&c,w.contents);
  if(p>valueInSum(c)){
    init(&c);
    c.contents[0]=-1;
    return c;
  } 
  
  for(i[0]=w.contents[0]; i[0]>=0; i[0]--){
    for(i[1]=w.contents[1]; i[1]>=0; i[1]--){
      for(i[2]=w.contents[2]; i[2]>=0; i[2]--){
	for(i[3]=w.contents[3]; i[3]>=0; i[3]--){
	  for(i[4]=w.contents[4]; i[4]>=0; i[4]--){
	    for(i[5]=w.contents[5]; i[5]>=0; i[5]--){
	      for(i[6]=w.contents[6]; i[6]>=0; i[6]--){
		for(i[7]=w.contents[7]; i[7]>=0; i[7]--){
		  for(i[8]=w.contents[8]; i[8]>=0; i[8]--){
		    setWALLET(&buf,i);
		    
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
}

void setWALLET(WALLET *w,int state[]){
  int i;
  for(i=0;i<9;i++){
    w->contents[i]=state[i];
  }
}
