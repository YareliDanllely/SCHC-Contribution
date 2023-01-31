#include <string.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "casting.h"
#include "misc.h"

using namespace std;


int bin_to_int(char * bin) {

    try {
        return stoi(bin, 0, 2);

    }

    catch (const invalid_argument& ia) {
        return -1;
    }

    catch (const out_of_range& oor) {
        return -2;
    }

    catch (const exception& e)
    {
        return -3;
    }
}

char* bin_to_hex(char *bin) {
    vector <char*> sectionBytes = section_char(bin, sectionbytes(bin));
    vector <char*> resultsHex;
    int counter = 0;

    for (int i =0; i<sectionBytes.size(); i++) {

        int value = bin_to_int(sectionBytes[i]);
        if ( value != 0) {
            counter = 1;
        }

        if (counter ==1) {
            char *valHex = int_to_hex(value);
            resultsHex.push_back(valHex);
        }
    }

    char *result= joinBinaries(resultsHex);
    return zfill(result, strlen(bin)/4);
}

char* hex_to_bin(char* hex, int length){

    if (length == 0) {
        length = strlen(hex)*4;
    }

    long long i = stoll(hex,NULL,16);
    cout << i << endl;
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
    char * finalResult = &binResult[0];
    return returnChar(zfill(finalResult,length));
}

char * int_to_hex(int num) {
    char buffer[100];
    ::sprintf(buffer,"%x", num);
    return returnChar(buffer);
}


