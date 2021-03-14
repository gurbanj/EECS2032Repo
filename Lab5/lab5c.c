#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
char input[30];
int n;
int j = 0;
int cntr = 1;

scanf("%s", &input);
    
    while (input[j]) {
        input[j] = tolower(input[j]);
        j++;
    }
    
int lgth = strlen(input);
int k;
int bool = 0; 
int maximumCntr = 1;

    for (k = 0; k < lgth-1; k++) {
        if (input[k+1] == input[k]+1) {
            while ((k < lgth-1) && input[k+1] == input[k]+1) {
                cntr += 1;
                k++;
                }
            if(cntr > maximumCntr) {
                maximumCntr = cntr;
            }
            cntr = 1;
            k--;
        }
    }
    printf("%d\n", maximumCntr);
}