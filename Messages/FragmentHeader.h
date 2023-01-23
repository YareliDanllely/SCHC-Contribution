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

    FragmentHeader(SigFoxProfile profile, char *dtag, char *w,char *fcn, char *rcs) : Header(profile,dtag,w), FCN(fcn), RCS(rcs) {

        char emptyChar[] = "\0";
        char monochar[] = "1";

           if (strlen(fcn) != profile.N) {
               cout << "1" <<endl;
               throw LengthMismatchError("FCN must be of length N");
           }
           FCN = fcn;

           if (rcs == NULL) {
               RCS = emptyChar;
           }

           else {
               if(profile.U != 0 && strlen(rcs) != profile.U) {
                   cout << "2" <<endl;
                   throw LengthMismatchError("RCS must be of length U");
               }
               if (not is_monochar(FCN, monochar)) {
                   cout << "3" <<endl;
                throw BadProfileError("RCS was not None in a regular fragment (not All-1)");
               }
               RCS = rcs;
           }

           PADDING = emptyChar;

           vector<char*> headerFeatures = {RULE_ID,DTAG,W,FCN, RCS};
           int header_length = sumSeveralChar(headerFeatures) % L2_WORD_SIZE;

           if (header_length % L2_WORD_SIZE != 0) {
               PADDING = zerosStr(L2_WORD_SIZE - (header_length % L2_WORD_SIZE));
           }

    }



    char * to_binary() {
           vector <char*> binVectors= {RULE_ID, DTAG, W, FCN, RCS,PADDING};
           return joinBinaries(binVectors);
    }

};


#endif //SCHC_CONTRIBUTION_FRAGMENTHEADER_H
