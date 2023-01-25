#include "ACKHeader.h"


ACKHeader::ACKHeader(SigFoxProfile profile, char *dtag, char *w, char *c) : Header(profile,dtag,w) ,PROFILE(profile) , C(c) {

    if (strlen(c) != 1) {
        throw LengthMismatchError("C bit mus be of length 1");
    }

    C=c;
}