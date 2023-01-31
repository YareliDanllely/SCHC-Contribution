
#ifndef SCHC_CONTRIBUTION_CASTING_H
#define SCHC_CONTRIBUTION_CASTING_H

#include <iostream>
#include <string>
using namespace std;

/**
 * Transforms a binary string into its integer representation
 * @param bin
 * @return int
 */
int bin_to_int(char * bin);

/**
 * Transforms a binary string into its hexadecimal representation
 * @param bin
 * @return hexadecimal string
 */
char* bin_to_hex(char *bin);

/**
 * Transforms a hexadecimal string into its binary representation.
 * @param hex
 * @param length
 * @return binary char
 */
char* hex_to_bin(char* hex,int length=0 );


/**
 * Transforms an integer into its binary representation.
 * @param num
 * @param length
 * @return binary representation
 */

//DOESNT WORK FOR LONG LONG VALUES
char* int_to_bin(int num, int length = 0);

/**
 * Transforms an integer into its hexadecimal representation.
 * @param num
 * @return hexadecimal representation
 */
char* int_to_hex(int num);






#endif //SCHC_CONTRIBUTION_CASTING_H
