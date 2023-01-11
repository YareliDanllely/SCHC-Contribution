#include <string.h>
#include <algorithm>
#include "misc.h"

using namespace std;

char * zfill(char * str, int n) {
    int len = strlen(str);
    if (n>len) {
        int zeros = n-len;
        int fLen = zeros + n;
        char result[fLen +1];
        char *finalResult = (char*) ::malloc(fLen+1);
        char *pointer = result;
        for ( int i=0; i< fLen +1 ; i++) {
            if (i<(zeros)){
                *pointer = '0';
                pointer ++;
            }
            else {
                *pointer = *str;
                str++;
                pointer++;
            }

        }
        strcpy(finalResult,result);
        return finalResult;
    }
    else {
        return str;
    }
}


void freeMemory(char * memory){
    free(memory);
}



