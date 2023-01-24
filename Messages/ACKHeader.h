#ifndef SCHC_CONTRIBUTION_ACKHEADER_H
#define SCHC_CONTRIBUTION_ACKHEADER_H
#include "Header.h"

class ACKHeader : public Header{
public:
    SigFoxProfile PROFILE;
    char * DTAG;
    char * W;
    char * C;

    ACKHeader(SigFoxProfile profile, char *dtag, char *w, char *c) : Header(profile,dtag,w) ,PROFILE(profile) , C(c) {

        if (strlen(c) != 1) {
            throw LengthMismatchError("C bit mus be of length 1");
        }

        C=c;
    }

};


#endif //SCHC_CONTRIBUTION_ACKHEADER_H
