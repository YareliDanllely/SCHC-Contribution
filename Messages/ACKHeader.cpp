#include "ACKHeader.h"




ACKHeader::ACKHeader(SigFoxProfile profile, char *dtag, char *w, char *c) : Header(profile,dtag,w) ,PROFILE(profile)  {

    if (strlen(c) != 1) {
        throw LengthMismatchError("C bit mus be of length 1");
    }

    C=c;
}

char *ACKHeader::to_binary() {
    vector<char *> fields_in_order = {RULE_ID,DTAG,W,C};
    return joinBinaries(fields_in_order);

}
