#define INFTY 1<<22

//contents[0]: the count of 1 Yen
//contents[8]: the count of 10,000 Yen
typedef struct{
  int contents[9];
}WALLET;

char *contentsName[9]={"1 Yen","5 Yen","10 Yen","50 Yen","100 Yen","500 Yen","1,000 Yen","5,000 Yen","10,000 Yen"};
int contentsValue[9]={1,5,10,50,100,500,1000,5000,10000};

void init(WALLET *);
void print(WALLET);
void input(WALLET *);
int valueInSum(WALLET);
WALLET calcChange(WALLET,int);
void setWALLET(WALLET *,int []);
void diffWALLET(WALLET *,WALLET);
