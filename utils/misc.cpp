#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include<math.h>
#include <map>
#include <stdexcept>
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
            values.push_back(i);
        }
        pointer++;
    }
    return values;
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

    (counter == 0 ?  true :  false);

}

int round_to_next_multiple(int num, int factor){
    float divNF = (float) num / -factor;
    int roundDiv = floor(divNF);
    int result = -(roundDiv) * factor;
    return result;
}

map<int,char> invert_dict(map<char,int> m){
    list<int> values;
    for (auto const & pair: m) {
        values.push_back(pair.second);
    }
    values.unique();
    if (m.size() == values.size()){
        map <int,char> finalMap;
        for (auto const & pair: m) {
            finalMap[pair.second] =  pair.first;
        }
        return finalMap;
    }
    else {
        throw invalid_argument("Dictionary cannot be inverted");
    }

}

vector<char*> section_char(char* str, vector<int> indices ){
    int numRange = indices.size();
    int lenStr = strlen(str);
    char * pointer = str;
    vector<char*> sectionString;

    for (int i=0; i<numRange; i++) {
        int largeSection;
        (i==numRange-1 ? largeSection = lenStr - indices[i]: largeSection= indices[i+1]-indices[i]);

        char section[largeSection+1];
        char *finalSection = (char*) ::malloc(largeSection+1);
        char *pointerSection= section;

        for (int j=0; j<largeSection; j++){
            *pointerSection= *pointer;
            pointerSection++;
            pointer++;
        }

        *pointerSection='\0';
        strcpy(finalSection,section);
        sectionString.push_back(finalSection);
    }
    return sectionString;

}


void generate_packet(char* str, char * path){
    ofstream myFile;
    myFile.open(path, ios::out);
    if (myFile.is_open()) {
        myFile << str << endl;
        myFile.close();
    }
    else {
        throw invalid_argument("Opening file failed");
    }

}









