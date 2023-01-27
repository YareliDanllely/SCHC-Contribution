#ifndef SCHC_CONTRIBUTION_ACKHEADER_H
#define SCHC_CONTRIBUTION_ACKHEADER_H
#include "Header.h"

class ACKHeader : public Header{
public:
    SigFoxProfile PROFILE;
    char * DTAG;
    char * W;
    char * C;

    /**
     * defining constructor and attributes
     * @param profile
     * @param dtag
     * @param w
     * @param c
     */

    ACKHeader(SigFoxProfile profile, char *dtag, char *w, char *c) ;

    /**
     * join rule_id, dtag,w and c
     * @return
     */
    char * to_binary();

};


#endif //SCHC_CONTRIBUTION_ACKHEADER_H
