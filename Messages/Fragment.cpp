#include "Fragment.h"


Fragment::Fragment(FragmentHeader header, char * payload) : HEADER(header), PROFILE(header.PROFILE), PAYLOAD(payload) {

    WINDOW = HEADER.WINDOW_NUMBER;
    INDEX = getMapValue(PROFILE.FCN_DICT,HEADER.FCN, PROFILE.WINDOW_SIZE-1);
    NUMBER = WINDOW * (PROFILE.WINDOW_SIZE+INDEX);

}

char *Fragment::to_bin() {
    vector <char*> binVectors= {HEADER.to_binary(), int_to_bin(stoi(PAYLOAD,0,16)) };
    return joinBinaries(binVectors);
}

bool Fragment::is_all_one(){
    char monoChar[] = "1";
    char payValue[] = "";
    if (not is_monochar(HEADER.FCN,monoChar)) {
        return false;
    }
    if (strcmp(PAYLOAD, payValue)==0) {
        return (strlen(HEADER.to_binary()) == PROFILE.RULE.ALL1_HEADER_LENGTH);
    }

    return true;
}


bool Fragment::is_all_zero() {
    char monoChar[] = "0";
    return is_monochar(HEADER.FCN,monoChar);
}


bool Fragment::expects_ack()  {
    return is_all_zero() || is_all_one();
}


bool Fragment::is_sender_abort()  {
    char monoChar[] = "1";
    char payValue[] = "";
    if (not is_monochar(HEADER.FCN,monoChar) ||  not is_monochar(HEADER.W,monoChar)) {
        return false;
    }
    if (strcmp(PAYLOAD, payValue) == 0 ) {
        return strlen(HEADER.to_binary()) < PROFILE.RULE.ALL1_HEADER_LENGTH;
    }
    return false;
}


Fragment Fragment::from_hex(char *hexString) {

    char emptyChar[] = "";
    char monoCharOne[] = "1";
    char monoCharZero[] = "0";


    if (hexString == NULL || strcmp(hexString,emptyChar)==0) { }


    Rule rule = rule.from_hex(hexString);
    char *as_bin = hex_to_bin(hexString);
    char direct[] = "UPLINK";
    SigFoxProfile  profile = SigFoxProfile(direct, FR_MODE, rule);

    int dtag_idx = profile.RULE_ID_SIZE;
    int w_idx = profile.RULE_ID_SIZE + profile.T;
    int fcn_idx = profile.RULE_ID_SIZE + profile.T + profile.M;
    int rcs_idx = profile.RULE_ID_SIZE + profile.T + profile.M + profile.N;

    char * fcn = cutChar(as_bin, fcn_idx, fcn_idx+profile.N);
    char * rcs;
    int header_length;


    if (is_monochar(fcn,monoCharOne)) {
        header_length = profile.RULE.ALL1_HEADER_LENGTH;
        int header_padding_index = rcs_idx + profile.U;

        rcs = cutChar(as_bin, rcs_idx, rcs_idx + profile.U);

        if (strcmp(rcs, emptyChar) == 0) {
            rcs = NULL;
        }

        if (round_to_next_multiple(rcs_idx + profile.U, L2_WORD_SIZE) != header_length) {
            throw LengthMismatchError("All-1 Header length mismatch:");
        }

        char *header_padding = cutChar(as_bin, header_padding_index, header_length);

        ;            if (not is_monochar(header_padding, monoCharZero) && strcmp(header_padding, emptyChar) != 0) {
            throw BadProfileError("Padding was not all zeroes nor empty");
        }
    }

    else {

        header_length = profile.RULE.HEADER_LENGTH;
        rcs = NULL;

        if (round_to_next_multiple(rcs_idx, L2_WORD_SIZE) != header_length) {
            throw LengthMismatchError("Header length mismatch:");
        }

    }

    char *dtag = cutChar(as_bin,dtag_idx, dtag_idx+ profile.T);
    char *w = cutChar(as_bin,w_idx, w_idx+ profile.M);


    FragmentHeader header = FragmentHeader(profile,dtag, w, fcn,rcs);
    int header_nibs = header_length/4 ;

    char * payload = cutChar(hexString,header_nibs, strlen(hexString));

    return Fragment(header,payload);
}


vector<char *> Fragment::get_indices()  {
    char * w_index = zfill(itos(HEADER.WINDOW_NUMBER), pow(2,PROFILE.M-1) / (10+1) );
    char * f_index = zfill(itos(INDEX), PROFILE.WINDOW_SIZE / (10+1));
    vector <char*> result = {w_index,f_index};
    return result;
}





