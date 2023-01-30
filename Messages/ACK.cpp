#include "ACK.h"
#include "schc.h"


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

bool ACK::is_receiver_abort() {

    char *as_bin= hex_to_bin(to_hex());
    int header_len = sumSeveralChar({HEADER.RULE_ID,HEADER.DTAG,HEADER.W,HEADER.C});
    char *header = cutChar(as_bin,0,header_len);
    vector<int> occurrences = find(as_bin, (char *)"1");
    char *padding = cutChar(as_bin,header_len,occurrences.back()+1);
    int lenPadding = strlen(padding);
    int lenHeader = strlen(header);
    char *padding_star = cutChar(padding,0, lenPadding-L2_WORD_SIZE);
    char *padding_end = cutChar(padding, lenPadding-L2_WORD_SIZE,lenPadding);


    if (is_monochar(HEADER.W, (char *) "1") && strcmp(HEADER.C, (char *) "1") ==0){
        if (strcmp(padding_end, severalChar(L2_WORD_SIZE,(char *) "1")),0) {
             if (strcmp(padding_star,(char *) "") !=0 && (lenHeader % L2_WORD_SIZE )!=0) {
                 return is_monochar(padding_star, (char *) "1") && (lenHeader + strlen(padding_star)) %L2_WORD_SIZE ==0;
             }
            return lenHeader %L2_WORD_SIZE == 0;
        }

    }
    return false;
}

bool ACK::is_compound_ack() {
    return !is_receiver_abort() && !is_monochar(PADDING, (char *) "0");
}

bool ACK::is_complete() {
    return strcmp(HEADER.C, (char *) "1") ==0 && !is_receiver_abort();
}

ACK ACK::from_hex(char *hex_string) {

    char *as_bin = hex_to_bin(hex_string);

    if (strlen(as_bin) != SigFoxProfile::DOWNLINK_MTU_ ) {
        throw LengthMismatchError("ACK was not of length DOWNLINK_MTU");
    }

    Rule rule = rule.from_hex(hex_string);
    SigFoxProfile profile = SigFoxProfile( (char *) "UPLINK", FR_MODE, rule);

    int dtag_idx = profile.RULE_ID_SIZE;
    int w_idx = profile.RULE_ID_SIZE + profile.T;
    int c_idx = profile.RULE_ID_SIZE + profile.T + profile.M;

    char *header = cutChar(as_bin,0,rule.ACK_HEADER_LENGTH);

    char *dtag = cutChar(header,dtag_idx, dtag_idx +profile.T);
    char *w = cutChar(header,w_idx,profile.M);
    char *c = cutChar(header, c_idx, c_idx+1);

    char *payload = cutChar(as_bin,rule.ACK_HEADER_LENGTH, strlen(as_bin));
    char *bitmap = cutChar(payload,0,profile.WINDOW_SIZE);
    char *padding = cutChar(payload,profile.WINDOW_SIZE, strlen(payload));

    return ACK(profile,dtag,w,c,bitmap,padding);

}

