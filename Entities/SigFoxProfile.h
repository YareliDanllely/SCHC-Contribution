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

    static int const UPLINK_MTU_ = 96;
    static int const DOWNLINK_MTU_= 64;

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
    SigFoxProfile(char *direction, char *mode, Rule rule);


};


#endif //SCHC_CONTRIBUTION_SIGFOXPROFILE_H
