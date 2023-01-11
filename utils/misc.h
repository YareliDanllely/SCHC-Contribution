//
// Created by Usuario on 10-01-2023.
//

#ifndef SCHC_CONTRIBUTION_MISC_H
#define SCHC_CONTRIBUTION_MISC_H

#include <iostream>
#include <string>
using namespace std;


/**
 * Adds zeroes at the beginning of a string until it completes
 * the desired length
 * @param str
 * @param length
 * @return
 */

char * zfill(char * str, int n);

/**
 * freeing memory from a pointer created with malloc
 * @param memory
 */
void freeMemory(char * memory);




#endif //SCHC_CONTRIBUTION_MISC_H
