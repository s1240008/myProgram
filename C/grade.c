#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

typedef struct{
  char cname[5];
  int credit;
  int lecture; // 0: false, 1: lectured
  int success; // 0: false, 1: successed
}course;

course courses[N];

void isLecture(char *);
int isSuccess(char *);
int findCourse(char *);

int main(){
  
  int i=0;
  char cname[5];
  FILE *fp;

  fp = fopen("grade.txt","r");

  while(fscanf(fp,"%s %d",courses[i].cname,&(courses[i].credit))!=EOF){
    courses[i].lecture=0;
    courses[i].success=0;
    i++;
  }
  
  while(scanf("%s",cname)!=EOF){
    isLecture(cname);
  }
  
  while(scanf("%s",cname)!=EOF){
    isSuccess(cname);
  }

  i=0;
  
  while(courses[i].credit!=0){

    printf("%s: %d:",courses[i].cname,courses[i].credit);

    if(courses[i].lecture)printf(" 1:");
    else printf(" 0:");

    if(courses[i].success)printf(" 1\n");
    else printf(" 0\n");

    i++;
  }
}

void isLecture(char *cname){
  int i;

  if((i = findCourse(cname))!=-1){
    courses[i].lecture=1;
  }
  
}

int isSuccess(char *cname){
  int i;

  if((i = findCourse(cname))!=-1){
    courses[i].success=1;
  }
  
}

int findCourse(char *cname){
  int i=0;
  while(strcmp(cname,courses[i].cname)!=0)i++;

  return i;
}
