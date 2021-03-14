#include<stdlib.h>
#include<stdio.h>

int main() {

    int fg;
    int temp;
    char strg[100];
    char strg1[100];
    int ctr=0;
    int ctr1=0;

    printf("S1=");
    scanf("%s", &strg);

    printf("S2=");
    scanf("%s", &strg1);

    while(strg[ctr]!=NULL) {
        ctr=ctr+1;
    }

    while(strg1[ctr1]!=NULL) {
        ctr1=ctr1+1;
    }
    temp=ctr1-ctr;

    for(int j=0; j<=temp; j++) {
        
        if(strg[0] == strg1[j]) {
            fg=1;
            
            for(int k=0; k<ctr; k++) {
                
                if(strg[k] != strg1[j+k]) {
                    fg=0;
                }
            }
        }
    }

    if(fg==1) {
        puts("YES");
    }
    else {
        puts("NO");
    }

    return 1;
}