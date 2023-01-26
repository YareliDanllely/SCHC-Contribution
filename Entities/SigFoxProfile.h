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

    int UPLINK_MTU_ = 96;
    int DOWNLINK_MTU_ = 64;
    int MAX_ACK_REQUESTS_;
    int RETRANSMISSION_TIMEOUT_;
    int INACTIVITY_TIMEOUT_;
    int SIGFOX_DL_TIMEOUT_;

    int RULE_ID_SIZE;
    int WINDOW_SIZE;
    int MAX_WINDOW_NUMBER;
    int MAX_FRAGMENT_NUMBER;

    int T;
    int M;
    int N;
    int U;

    /**
     * defining constructor and attributes
     * @param direction
     * @param mode
     * @param rule
     */
    SigFoxProfile(char *direction, char *mode, Rule rule) : RULE(rule) {

        DIRECTION = direction;
        MODE = mode;

        SigFoxProfile::MAX_ACK_REQUESTS_ = MAX_ACK_REQUESTS;
        SigFoxProfile::RETRANSMISSION_TIMEOUT_ = RETRANSMISSION_TIMEOUT;
        SigFoxProfile::INACTIVITY_TIMEOUT_ = INACTIVITY_TIMEOUT;
        SigFoxProfile::SIGFOX_DL_TIMEOUT_ = SIGFOX_DL_TIMEOUT;

        char direct[] = "UPLINK";
        char mod[] = "ACK ON ERROR";

        if (strcmp(DIRECTION, direct) == 0) {
            if (strcmp(MODE, mod) == 0) {
                RULE_ID_SIZE = rule.RULE_ID_SIZE;
                T = rule.T;
                N = rule.N;
                M = rule.M;
                U = rule.U;
                WINDOW_SIZE = rule.WINDOW_SIZE;
                MAX_WINDOW_NUMBER = ::pow(2, M);
                MAX_FRAGMENT_NUMBER = MAX_WINDOW_NUMBER * WINDOW_SIZE;


                int bin = WINDOW_SIZE - 1;
                for (int i = 0; i < WINDOW_SIZE; i++) {
                    FCN_DICT.insert(pair<char *, int>(int_to_bin(bin, 3), i));
                    bin--;
                }

            }
        }

    }

    };


#endif //SCHC_CONTRIBUTION_SIGFOXPROFILE_H
