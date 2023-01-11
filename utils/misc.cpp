#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include "misc.h"

using namespace std;

void freeMemory(char * memory){
    free(memory);
}

char * zfill(char * str, int n) {
    int len = strlen(str);
    if (n>len) {
        int zeros = n-len;
        int fLen = zeros + len;
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


char * zpad(char* str, int n){
    int len = strlen(str);

    if (n>len) {
        int zeros = n-len;
        int fLen = zeros + len;
        char result[fLen +1];
        char *finalResult = (char*) ::malloc(fLen+1);
        char *pointer = result;
        for ( int i=0; i< fLen ; i++) {
            if (i<(len)){
                *pointer = *str;
                str++;
                pointer++;

            }
            else {
                *pointer = '0';
                pointer ++;
            }
        }
        *pointer = '\0';
        strcpy(finalResult,result);
        return finalResult;
    }
    else {
        return str;
    }

}

char * replaceChar(char* str, int position, char *newChar ){
    int len = strlen(str);
    char *pointer = str;

    if (position>len) {
        char *finalResult = (char*) ::malloc(len+2);
        char *pointer = finalResult;
        strcpy(finalResult,str);
        pointer +=len;
        *pointer = *newChar;
        pointer++;
        *pointer = '\0';
        return finalResult;
    }

    else{
        char *pointer = str;
        pointer += position;
        *pointer = *newChar;
        return str;
    }

}

vector<int> find(char* str, char *search){
    char * pointer = str;
    int len = strlen(str);
    vector<int> values;
    for (int i=0; i<len; i++) {
        if (*pointer == *search){
            cout << *pointer << endl;
            values.push_back(i);
        }
        pointer++;
    }
    return  values;
}

bool is_monochar(char*str, char * value){
    char * pointer = str;
    int len = strlen(str);
    int counter = 0;

    for (int i; i<len ; i++){
        if (*pointer != *value){
            counter = 1;
            break;
        }
        pointer++;
    }

    if(counter == 0) {
        return true;
    }
    else {
        return false;
    }
}

int round_to_next_multiple(int num, int factor){
    int result = -(num /(-factor)) * factor;
    return result;
}








