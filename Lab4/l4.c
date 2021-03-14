#include <stdio.h>

int main() {
    int inp1,inp2,inp3;
    scanf("%d%d%d", &inp1, &inp2, &inp3);

    if((inp1 >= 0) && (inp2 >= 0) && (inp3 >= 0)) {
        printf("All Positive\n");
    }
    else if((inp1 <= 0) && (inp2 <= 0) && (inp3 <= 0)) {
        printf("All Negative\n");
    }
    else {
        int res;
        res = inp1 + inp2 + inp3;

        if(res >= 0) {
            printf("Positive Wins\n");
        }
        else {
            printf("Negative Wins\n");
        }
    }
} 