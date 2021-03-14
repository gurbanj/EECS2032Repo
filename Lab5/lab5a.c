#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
char input[30];
int n;

scanf("%s", &input);
scanf("%d", &n); 

   int cntr = 0;
   int n2 = n - 1;
   int bool = 0;   
   int lgth = strlen(input);
   int i;

for (i = 0; i < lgth-1; i++) {
        if (input[i+1] == input[i]+1) { //while incrementing, count the next element if it is alphabetically greater
            while ((i < lgth-1) && input[i+1] == input[i]+1)
            {
                cntr += 1;
                i++;
                if(cntr == n2) { 
                    break;
                }
            }
            if (cntr == n2) { 
                bool = 1;
                break;
                }
                cntr = 0;
                i--;
        }
    }
if (bool == 1) {
    printf("YES\n");
    }
else {
    printf("NO\n");
    }
}
