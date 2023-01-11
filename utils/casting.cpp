#include <string.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "casting.h"
#include "misc.h"

using namespace std;


int bin_to_int(char * bin){
    return stoi(bin,0,2);
}


char* bin_to_hex(char *bin) {
    int i = stol(bin,NULL,2);
    char * result= int_to_hex(i);
    return zfill(result, strlen(bin)/4);
}


char* hex_to_bin(char* hex, int length ){

    if (length == 0) {
        length = strlen(hex)*4;
    }

    int i = stol(hex,NULL,16);
    char *result = int_to_bin(i,length);
    return result;
}


char* int_to_bin(int num, int length) {
    string result;
    while (num != 0) {
        result += (num %2 == 0 ? "0" : "1");
        num/=2;
    }
    string binResult(result.rbegin(),result.rend());
    char * finalResult = zfill(&binResult[0],length);
    return finalResult;
}


char* int_to_hex(int num) {
    ostringstream ss;
    ss << hex << num;
    string hexString = ss.str();
    char * result = &hexString[0];
    return result;
}
