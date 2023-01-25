#ifndef SCHC_CONTRIBUTION_RULE_H
#define SCHC_CONTRIBUTION_RULE_H
#include "casting.h"
#include "misc.h"
#include <string>
#include "schc.h"


class Rule {
public:
    char* STR;
    int ID ;
    int RULE_ID_SIZE;
    int T;
    int M;
    int N;
    int U;
    int WINDOW_SIZE;
    int HEADER_LENGTH;
    int ALL1_HEADER_LENGTH;
    int ACK_HEADER_LENGTH;


    /**
     * defining constructor and attributes
     * @param ruleId
     */


   Rule( char *ruleId) ;


    /**
     * Parses the Rule ID of the given hex string,
     * assuming that it is located in the leftmost bits
     * @param str
     * @return
     */
    static Rule from_hex(char * str) ;

};



#endif //SCHC_CONTRIBUTION_RULE_H
