#ifndef SCHC_CONTRIBUTION_SENDERABORT_H
#define SCHC_CONTRIBUTION_SENDERABORT_H
#include "Fragment.h"
#include "FragmentHeader.h"

class SenderAbort : public  Fragment{
public:
    SigFoxProfile profile;
    char *dtag;
    char *w;
    char * fcn;
    char * rcs;
    char * payload;
    FragmentHeader header1;

    /**
     * defining constructor and attributes
     * @param header
     */
    SenderAbort(FragmentHeader header1);




};


#endif //SCHC_CONTRIBUTION_SENDERABORT_H
