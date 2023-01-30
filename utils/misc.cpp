#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include<math.h>
#include <map>

#include <sstream>
#include <stdexcept>
#include "misc.h"

using namespace std;


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

char * cutChar(char * str, int top ,int end){
    int size = strlen(str);
    char strCpy[size+1];
    strcpy(strCpy,str);
    int sizeResult = end-top;

    char emptyChar[] = "\0";

    if (top> size) {
        return returnChar(emptyChar);
    }
    else {

        char result[sizeResult + 1];
        char *pointer = strCpy + top;
        char *pResult = result;

        for (int i = 0; i < sizeResult; i++) {
            *pResult = *pointer;
            pResult++;
            pointer++;
        }
        *pResult = '\0';
        return returnChar(result);

    }

}


char * returnChar(char * str){
    char * result = (char *) ::malloc(strlen(str)+1);
    strcpy(result,str);
    return result;
}


bool is_monochar(char *str, char *value){

    int size = strlen(str);
    char strCpy[size+1];
    strcpy(strCpy,str);

    char * pointer = strCpy;
    char * pValue = value;
    int counter = 0;
    bool result;

    for (int i=0; i<size ; i++){
        if (*pointer != *pValue){
            counter = 1;
            break;
        }
        pointer++;
    }

    (counter == 0 ?  result = true :  result = false);
    return  result;

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

char * severalChar(int amount, char * character){
    char zeros[amount+1];
    char *pointer = zeros;
    for (int i=0; i<amount; i++) {
        *pointer= *character;
        pointer++;
    }
    *pointer = '\0';

    return returnChar(zeros);

}

int sumSeveralChar( vector<char*> strVector) {
    int sum = 0;
    char emptyChar[] = "";
    for (int i=0 ; i<strVector.size();i++) {

        if (strcmp(strVector[i],emptyChar) == 0){
            continue;
        }
        else {
            sum += strlen(strVector[i]);
        }
    }
    return  sum;
}


char * joinBinaries( vector<char*> binaries) {
    int len = sumSeveralChar(binaries);
    char emptyChar[] = "";
    char join[len+1];
    char *pointer = join;
    int sizeVec = binaries.size();

    for (int i=0 ; i<sizeVec ; i++) {

        if (strcmp(binaries[i],emptyChar)==0) {
            continue;
        }
        else {
            char *pBinary = binaries[i];
            for (int j = 0; j < strlen(binaries[i]); j++) {
                *pointer = *pBinary;
                pointer++;
                pBinary++;

            }
        }
    }
    *pointer ='\0';

    return returnChar(join);
}

int getMapValue(map <char *, int> map1, char *lookFor ,int value){
    auto it = map1.find(lookFor);

    if ( it == map1.end()) {
        return value;
    }

    else {
        return it->second;
    }


}

char * itos (int value) {
    stringstream  ss;
    ss << value;
    string s = ss.str();
    char * result = &s[0];
    return result;

}


