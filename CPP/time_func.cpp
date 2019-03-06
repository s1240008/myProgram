//
//  time_func.cpp
//  
//
//  Created by s1240008 on 2018/10/25.
//

#include <iostream>
#include<time.h>
#include <unistd.h>

#include "time_func.hpp"

using namespace std;

struct tm *local;

void select(){
  int com,i,m,n,s,t;
  time_t timer;

    for(i=0;i<10;i++){
        /* 現在時刻を取得 */
        timer = time(NULL);
        local = localtime(&timer); /* 地方時に変換 */
        printT();
    }

    cout << "count down until finish this class: 1" << endl;
    cout << "count down until set time: 2" << endl;
    cout << "count down until set count: 3" << endl;
    
    cin >> com;
    
    switch (com) {
        case 1:
            timer = time(NULL);
            local = localtime(&timer);
            
            if(nowHour()==-1)break;
            
            t = printFinish(nowHour(),-1);
            
            m = (t/100 - local->tm_hour)*60 + (t%100 - local->tm_min) - 1;
            s = 60 - local->tm_sec;
            countDown(m,s);
            
            break;

        case 2:
            cout << "input finish time. " << endl;
            cout << "ex) 15:00 => 1500" << endl;
            cin >> t;
            
            timer = time(NULL);
            local = localtime(&timer);
            
            m = (t/100 - local->tm_hour)*60 + (t%100 - local->tm_min) - 1;
            s = 60 - local->tm_sec;
            if(m<0)cout << "this time is over." << endl;
            countDown(m,s);
            
            break;

        case 3:
            cout << "input count" << endl;
            cout << "ex) count down 15 min 30 sec. => 1530" << endl;
            cin >> t;
            
            countDown(t/100,t%100);
            
            break;

        default:
            break;
    }
    
}

//今の時限を数字で返す。
//今が休憩時間なら -1 を返す。
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

//今の時限の終了時間を表示する。
int printFinish(int h, int t){
    int fTime[10]={950,1040,1140,1230,1410,1500,1600,1650,1750,1840};
    if(t>0){
        cout.width(2);
        cout.fill('0');
        cout << fTime[h-1]/100 << ":" << fTime[h-1]%100;
        cout.width(0);
    }
    return fTime[h-1];
}

//現在時刻とその授業の終了時間を表示。
void printT(void){
  int h,f,i,t[6]={local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec};
    /* 地方時 変換後表示 */
    for(i=0;i<6;i++){
      cout.width(2);
      cout.fill('0');
      cout << t[i];
      if(i==0||i==1)cout << ".";
      else if(i==3||i==4)cout << ":";
      else cout << " ";
    }
    
    cout.width(0);
    if(local->tm_wday>0&&local->tm_wday<6){
        cout << "It is ";
        
        h=nowHour();
        if(h==-1){
            cout << "rest time now";
        }
        
        else if(h){
            switch(h){
                case 1:
                    cout << "1st ";
                    break;
                case 2:
                    cout << "2nd ";
                    break;
                case 3:
                    cout << "3rd ";
                    break;
                default:
                    cout << h << "th ";
                    break;
            }
            cout << "hour class";
            cout << "this class finish ";
            f=printFinish(h,1);
        }
    }
    else{
        cout << "Today is hollyday";
    }
    fflush(stdout);
    cout << "\r                                                                   \r";
    sleep(1);
    
}

//入力した時間までの時間を表示する。
void printLeft(int h){
    
    int m=h%100;
    h=h/100;
    
    cout.width(2);
    cout << local->tm_hour << ":";
    cout << local->tm_min << " to ";
    cout << h << ":" << m;
    cout.width(0);
    
    m=(h-(local->tm_hour))*60+(m-(local->tm_min));
    
    if(m/60>0){
        h=m/60;
        cout << h << " hours ";
        m%=60;
    }
    
    if(m>0){
        cout << m << " minutes ";
    }
    
    cout << "left" << endl;
    
}

//設定した時間をカウントダウンする。
void countDown(int m, int s){
  int i,n;
  n=m*60+s;
    
    for(i=0;i<n;i++){
        m=(n-i)/60;
        s=(n-i)%60;
        if(m>0)cout << m << " ";
        
        cout.width(2);
        cout << s;
        cout.width(0);

	cout <<  " | " << (int)((m*60+s)*100/n) << "%";
	
        fflush(stdout);
        
        sleep(1);
        
        cout << "\r                    \r";
    }
}
