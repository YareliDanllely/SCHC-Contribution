#include "Header.h"


Header:: Header(SigFoxProfile profile, char *dtag, char *w ) : PROFILE(profile) {

    if (strlen(profile.RULE.STR) != profile.RULE_ID_SIZE) {
        throw LengthMismatchError("Rule must be of length RULE_ID_SIZE");
    }

    RULE_ID = profile.RULE.STR;

    if (profile.T == 0) {
        char emptyChar[] = "";
        DTAG = emptyChar;
    }
    else if (strlen(dtag) != profile.T) {
        throw LengthMismatchError("DTAG must be of length T");
    }

    else {
        DTAG = dtag;
    }

    if (strlen(w) != profile.M) {
        throw LengthMismatchError("W must be length M");
    }
    W = w;
    WINDOW_NUMBER = bin_to_int(w);
}
