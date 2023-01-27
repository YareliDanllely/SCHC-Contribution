#ifndef SCHC_CONTRIBUTION_SENDERABORT_H
#define SCHC_CONTRIBUTION_SENDERABORT_H
#include "Fragment.h"
#include "SigFoxProfile.h"

class SenderAbort : public Fragment {
public :
    SigFoxProfile PROFILE;

    SenderAbort(FragmentHeader header);

};


#endif //SCHC_CONTRIBUTION_SENDERABORT_H
