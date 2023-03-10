#include "Rule.h"
#include "schc.h"


Rule::Rule(char *ruleId) : STR(ruleId){

    ID = bin_to_int(STR);

    if (strcmp(cutChar(STR,0,3), "111") != 0) {
        RULE_ID_SIZE = 3;
        T = 0;
        M = 2;
        N = 3;
        WINDOW_SIZE = 7;
        U = 3;
    }

    else if (strcmp(cutChar(STR,0,6),"111111") != 0){
        RULE_ID_SIZE = 6;
        T=0;
        M=2;
        N=4;
        WINDOW_SIZE=12;
        U=4;
    }

    else {
        RULE_ID_SIZE = 8;
        T=0;
        M=3;
        N=5;
        WINDOW_SIZE=31;
        U=5;
    }

    if (strlen(ruleId)> RULE_ID_SIZE) {
        invalid_argument("Rule ID is larger than RULE_ID_SIZE");
    }

    HEADER_LENGTH = round_to_next_multiple(RULE_ID_SIZE + T + M + N , L2_WORD_SIZE);
    ALL1_HEADER_LENGTH = round_to_next_multiple(RULE_ID_SIZE + T + M + N + U , L2_WORD_SIZE);
    ACK_HEADER_LENGTH = RULE_ID_SIZE + M + 1;

}


Rule Rule::from_hex(char *str) {
    char * as_bin = hex_to_bin(str);
    char * firstByte = cutChar(as_bin,0,8);
    char * rule_id = cutChar(firstByte,0,3);
    char value[] = "1";
    if (is_monochar(rule_id,value)) {
        rule_id = cutChar(firstByte,0,6);

        if (is_monochar(rule_id,value)) {
            rule_id = cutChar(firstByte,0,8);
        }
    }
    return  Rule(rule_id);
}



