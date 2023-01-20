#ifndef SCHC_CONTRIBUTION_SIGFOXPROFILE_H
#define SCHC_CONTRIBUTION_SIGFOXPROFILE_H
#include "Rule.h"
#include "schc.h"
#include <math.h>
#include <map>


class SigFoxProfile {
public:

    char * DIRECTION;
    char * MODE;

    Rule RULE;
    map<char*,int> FCN_DICT;

    int UPLINK_MTU = 96;
    int DOWNLINK_MTU = 64;
    int MAX_ACK_REQUESTS;
    int RETRANSMISSION_TIMEOUT;
    int INACTIVITY_TIMEOUT;
    int SIGFOX_DL_TIMEOUT;
    int RULE_ID_SIZE;
    int WINDOW_SIZE;
    int MAX_WINDOW_NUMBER;
    int MAX_FRAGMENT_NUMBER;

    int T;
    int M;
    int N;
    int U;




    SigFoxProfile(char *direction, char *mode, Rule rule) : RULE(rule) {
        DIRECTION = direction;
        MODE = mode;

        SigFoxProfile::MAX_ACK_REQUESTS = ::MAX_ACK_REQUESTS;
        SigFoxProfile::RETRANSMISSION_TIMEOUT = ::RETRANSMISSION_TIMEOUT;
        SigFoxProfile::INACTIVITY_TIMEOUT = ::INACTIVITY_TIMEOUT;
        SigFoxProfile::SIGFOX_DL_TIMEOUT = ::SIGFOX_DL_TIMEOUT;

        char direct[]= "UPLINK";
        char mod[] = "ACK ON ERROR";

        if (strcmp(DIRECTION, direct)==0) {
            if (strcmp(MODE,mod)==0) {
                RULE_ID_SIZE = rule.RULE_ID_SIZE;
                T = rule.T;
                N = rule.N;
                M = rule.M;
                U = rule.U;
                WINDOW_SIZE = rule.WINDOW_SIZE;
                MAX_WINDOW_NUMBER = ::pow(2,M);
                MAX_FRAGMENT_NUMBER = MAX_WINDOW_NUMBER * WINDOW_SIZE;


                int bin = WINDOW_SIZE-1;
                for (int i =0 ; i<WINDOW_SIZE ; i++) {
                    FCN_DICT.insert(pair<char*,int>(int_to_bin(bin,3),i));
                    bin--;
                }

            }
        }

    }

};


#endif //SCHC_CONTRIBUTION_SIGFOXPROFILE_H
