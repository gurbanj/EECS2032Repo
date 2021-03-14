#include<stdlib.h>
#include <stdio.h>

int main() {

    FILE *data;
    char *checker;
    long dataSz;
    int k;
    int cntr = 0;

    data = fopen ( "dat.txt" , "rb" );

    unsigned int carrier = 0;
    unsigned short tgt;
    unsigned short arr[100];
    short complement=65535;
    unsigned short checksum;

    checker = calloc(0, dataSz);

    while( !feof(data) ) {
        fread(checker,sizeof(short),1,data) ;
        checksum = checksum + tgt;
        carrier = carrier + tgt; 
        tgt = 0;
    }

    checksum = (carrier >> 16) + checksum;
    checksum = 0;
    checksum = checksum^complement;

    for(k = 0; k < sizeof(arr); k++) {
        if(arr[k] != 0) {
            cntr++;
        }
        else {
            break;
        }
    }
    
    data = fopen("result.txt", "w");

    fwrite(arr,sizeof(short),cntr,data);
    fwrite(&checksum,sizeof(short),1,data);
   
    if(complement == checksum) {
        printf("Valid\n");
    }
    else {
        printf("Invalid\n");
    }
    
    fclose(data);
    
    return 0;
}


