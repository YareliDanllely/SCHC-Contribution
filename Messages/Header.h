#ifndef SCHC_CONTRIBUTION_HEADER_H
#define SCHC_CONTRIBUTION_HEADER_H
#include "SigFoxProfile.h"
#include <string>
#include "misc.h"
#include "exceptions.h"


class Header {
public:
    SigFoxProfile PROFILE;
    char * DTAG;
    char * W;
    char * RULE_ID;
    int WINDOW_NUMBER;

    /**
     * defining constructor and attributes
     * @param profile
     * @param dtag
     * @param w
     */

    Header(SigFoxProfile profile, char *dtag, char *w ) ;


};


#endif //SCHC_CONTRIBUTION_HEADER_H
