#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int ovrlpSt(int x,int y,char strg[],char strg1[]) {
    
    int top=0;
    int ctr=0;
    int k=0;

    for(int j=x-1;j>=0;j--) {
        
        if(strg[j] == strg1[k]) {
            ctr=ctr+1;
        }
        
        else {
           
            if(ctr>top) {
                top = ctr;
                ctr = 0;
            }
        }
        k++;
    }
    return top;
}

int lgthOfStrg(char strg2[]) {
    
    int ctr1=0;
    while(strg2[ctr1]!=NULL) {
        ctr1=ctr1+1;
    } 

    return ctr1;
}

int main() {

    int overlap1;
    int overlap2;
    int top;
    char strg[100];
    char strg1[100];

    printf("S1=");
    scanf("%s", &strg);

    printf("S2=");
    scanf("%s", &strg1);

    int x=lgthOfStrg(strg);
    int y=lgthOfStrg(strg1);

    overlap1=ovrlpSt(x, y, strg, strg1);
    overlap2=ovrlpSt(y, x, strg1, strg);

    top=(overlap1>overlap2)?overlap1:overlap2;

    printf("The maximum overlap is %i \n", top);

    return 1;
}