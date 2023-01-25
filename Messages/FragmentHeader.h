#ifndef SCHC_CONTRIBUTION_FRAGMENTHEADER_H
#define SCHC_CONTRIBUTION_FRAGMENTHEADER_H
#include "Header.h"
#include "exceptions.h"
#include "misc.h"
using namespace std;

class FragmentHeader : public Header {

public:
    char * FCN;
    char * RCS;
    char * PADDING;

    /*
     *defining constructor and attributes
     */
    FragmentHeader(SigFoxProfile profile, char *dtag, char *w,char *fcn, char *rcs) ;


    /**
     * join binaries attributes
     * @return
     */
    char * to_binary() ;

};


#endif //SCHC_CONTRIBUTION_FRAGMENTHEADER_H
