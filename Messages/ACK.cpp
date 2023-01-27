#include "ACK.h"


ACK::ACK(SigFoxProfile profile, char *dtag, char *w, char *c, char *bitmap, char *padding): PROFILE(profile), HEADER(ACKHeader(profile,dtag,w,c)) {

    BITMAP = bitmap;

    vector<char *> createPaddingZeros = {HEADER.to_binary(),BITMAP,padding};
    char * joinCreatePaddingZeros = joinBinaries(createPaddingZeros);
    int amountZeros = profile.DOWNLINK_MTU_ - strlen(joinCreatePaddingZeros) ;
    vector<char *> createPadding = {padding, severalChar(amountZeros, (char *) "0")};
    PADDING = joinBinaries(createPadding);
}

char *ACK::to_hex() {
    vector <char *> joinValues = {HEADER.to_binary(),BITMAP,PADDING};
    return bin_to_hex(joinBinaries(joinValues));
}

