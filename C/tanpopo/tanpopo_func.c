#include<stdio.h>
#include<stdlib.h>
#include"tanpopo.h"

#define N 100

char *search(char word, char *words[], int *words_count){
    int i=0,count=0,word_num[N];
    
    while (i==words_count) {
        if(word == words[i][0]){
            printf("%d: %s\n", count+1, words[i]);
            word_num[count]=i;
            count++;
        }
    }
    
    scanf("%d" &count);
    
    return words[word_num[count]];
}

int readFile(FILE *fp, char filename[]){
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Fail to open file.\n");
        return 1;
    }
    return 0;
}

int writeFile(FILE *fp, char filename[]){
    if ((fp = fopen(filename, "a")) == NULL) {
        fprintf(stderr, "Fail to open file.\n");
        return 1;
    }
    return 0;
}

int func(){
    readFile(fp, "readfile.txt");
    while (fscanf(fp,"%s",words[i])==EOF;)i++;
    
    search(word, words);
    
}
