//
// Created by Usuario on 10-01-2023.
//

#ifndef SCHC_CONTRIBUTION_MISC_H
#define SCHC_CONTRIBUTION_MISC_H
#include <string.h>
#include <iostream>
#include <string>
#include "vector"
#include <list>
#include <fstream>
#include <map>
using namespace std;

/**
 * freeing memory from a pointer created with malloc
 * @param memory
 */
void freeMemory(char * memory);

/**
 * Adds zeroes at the beginning of a string until it completes
 * the desired length
 * @param str
 * @param length
 * @return char with zeros in the beginning
 */

char * zfill(char * str, int n);

/**
 * Adds zeroes at the end of a string until it completes
 * the desired length.
 * @param str
 * @param n
 * @return char with zeros in the end
 */
char * zpad(char* str, int n);

/**
 * Replaces a single character in the specified position of a string
 * @param str
 * @param position
 * @param newChar
 * @return char with a new character
 */
char * replaceChar(char* str, int position, char *newChar );


/**
 * Lists all the occurrences of a character in a string
 * @param str
 * @param search
 * @return array with positions of value to search
 */
vector<int> find(char* str, char *search);

/**
 * return a char cut in a size given by  acutter
 * @param str
 * @return cut char
 */
char * cutChar(char * str, int cutter);

/**
 * return a char using malloc
 * @param str
 * @return
 */
char * returnChar(char * str);

/**
 * Checks if a string contains only repetitions of one character.
 * @param str
 * @return true or false
 */
bool is_monochar(char*str, char * value);

/**
 * Sections a string in the specified indices and
 *  returns a list of its sections
 * @param str
 * @param search
 * @return
 */

vector<char*> section_char(char* str, vector<int> indices );

/**
 * Rounds a number to the next greater multiple of a specified factor.
 * @param num
 * @param factor
 * @return
 */
int round_to_next_multiple(int num, int factor);

/**
 * Inverts {key: value} pairs of a dictionary into {value: kay} pairs,
 * only if no values are repeated
 * @return
 */
map<int,char> invert_dict(map<char,int> m);

/**
 * save a char * into a file
 * @param str
 * @param path
 */
void generate_packet(char* str, char * path);


/**
 * return a char with a number amount of zeros
 * @param zeros
 * @return
 */
char * zerosStr( int amount);


/**
 * return the sum of several char stored in a vector
 * @return
 */
int sumSeveralChar( vector<char*>);


/**
 * join binary numbers stored in a vector
 * @param binaries
 * @return
 */
char * joinBinaries( vector<char*> binaries);


#endif //SCHC_CONTRIBUTION_MISC_H
