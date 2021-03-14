#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[50];
    int n;

    scanf("%s", &input);
    scanf("%d", &n);

int j = 0;
int n2 = n - 1; 
int cntr = 0;

    while (input[j]) 
    {
        input[j] = tolower(input[j]);
        j++;
    }
    int bool = 0; 
    int lgth = strlen(input);
    int k;

    for (k = 0; k < lgth - 1; k++) {
        if (input[k+1] == input[k]+1) {
            while ((k < lgth-1) && input[k+1] == input[k] + 1) {
                cntr += 1;
                k++;
                 if(cntr == n2) { 
                    break;
                }
            }
            if (cntr == n2) { 
                bool = 1;
                break;
            }
            cntr = 0;
            k--;
        }
    }
    if (bool == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}