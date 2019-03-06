
#include<stdio.h>
#include<time.h>
#include <unistd.h>

struct tm *local;

int nowHour(void){
  int m=(local->tm_hour)*100+local->tm_min;

  if(900<=m&&m<950)return 1;
  else if(950<=m&&m<1040)return 2;
  else if(1040<=m&&m<1050)return -1;

  else if(1050<=m&&m<1140)return 3;
  else if(1140<=m&&m<1230)return 4;
  else if(1230<=m&&m<1320)return -1;

  else if(1320<=m&&m<1410)return 5;
  else if(1410<=m&&m<1500)return 6;
  else if(1500<=m&&m<1510)return -1;
  
  else if(1510<=m&&m<1600)return 7;
  else if(1600<=m&&m<1650)return 8;
  else if(1650<=m&&m<1700)return -1;

  else if(1700<=m&&m<1750)return 9;
  else if(1750<=m&&m<1840)return 10;
  else if(1840<=m&&m<1930)return -1;
  
  return -1;
}

void printFinish(int h){
  char fTime[][10]={"9:50","10:40","11:40","12:30",
		    "14:10","15:00","16:00","16:50","17:50","18:40"};
  printf("%s",fTime[h-1]);
}

void printT(void){
  int h;
  /* 地方時 変換後表示 */
  printf("%d.%d.%d ", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);
  printf("%02d:%02d:%02d ", local->tm_hour, local->tm_min, local->tm_sec);

  if(local->tm_wday>0&&local->tm_wday<6){
    printf("It is ");

    h=nowHour();
    if(h==-1){
      printf("rest time now");
    }

    else if(h){  
      switch(h){
      case 1:
	printf("1st ");
	break;
      case 2:
	printf("2nd ");
	break;
      case 3:
	printf("3rd ");
	break;
      default:
	printf("%dth ",h);
	break;
      }
      printf("hour class");  
      printf("this class finish ");
      printFinish(h);
    }
  }
  else{
    printf("Today is hollyday");
  }
  fflush(stdout);
  printf("\r                                                                   \r");
  sleep(1);
    
}

void printLeft(int h){
  
  int m=h%100;
  h=h/100;
  
  printf("%02d:%02d to %02d:%02d, ",local->tm_hour,local->tm_min,h,m);
  
  m=(h-(local->tm_hour))*60+(m-(local->tm_min));
  
  if(m/60>0){
    h=m/60;
    printf("%d hours ",h);
    m%=60;
  }

  if(m>0){
    printf("%d minutes ",m);
  }
  
  printf("left\n");
  
}

int main(){
    
  time_t timer;
  int i,h;
  
  for(i=0;i<10;i++){
  
    /* 現在時刻を取得 */
    timer = time(NULL);

    local = localtime(&timer); /* 地方時に変換 */
    
    printT();

  }

  scanf("%d",&h);

  printLeft(h);
  
  return 0;
}
