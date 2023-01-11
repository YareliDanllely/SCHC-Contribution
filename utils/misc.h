//
// Created by Usuario on 10-01-2023.
//

#ifndef SCHC_CONTRIBUTION_MISC_H
#define SCHC_CONTRIBUTION_MISC_H

#include <iostream>
#include <string>
#include <any>
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
    the desired length.
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

vector<char> section_string(char* str, vector<int> );

/**
 * Rounds a number to the next greater multiple of a specified factor.
 * @param num
 * @param factor
 * @return
 */
int round_to_next_multiple(int num, int factor);

#endif //SCHC_CONTRIBUTION_MISC_H
