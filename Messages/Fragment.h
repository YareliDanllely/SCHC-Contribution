#ifndef SCHC_CONTRIBUTION_FRAGMENT_H
#define SCHC_CONTRIBUTION_FRAGMENT_H
#include "FragmentHeader.h"
#include "schc.h"

class Fragment {
public:

    FragmentHeader HEADER;
    SigFoxProfile PROFILE;
    char * PAYLOAD;
    int WINDOW;
    int INDEX;
    int NUMBER;

    Fragment(FragmentHeader header, char * payload) : HEADER(header), PROFILE(header.PROFILE), PAYLOAD(payload) {

        WINDOW = HEADER.WINDOW_NUMBER;
        INDEX = getMapValue(PROFILE.FCN_DICT,HEADER.FCN, PROFILE.WINDOW_SIZE-1);
        NUMBER = WINDOW * (PROFILE.WINDOW_SIZE+INDEX);

    }

    /**
     * Returns the bin representation of the Fragment.
     * @return char *
     */
    char *to_bin(int basePayload) {
        vector <char*> binVectors= {HEADER.to_binary(), int_to_bin(stoi(PAYLOAD,0,basePayload)) };
        return joinBinaries(binVectors);
    }

    /**
     * Checks if the fragment is an All-1
     * @return bool
     */
    bool is_all_one(int basePayload) {
        char monoChar[] = "1";
        char payValue[] = "b ";
        if (not is_monochar(HEADER.FCN,monoChar)) {
            return false;
        }
        if (strcmp(PAYLOAD, payValue)==0) {
            return (strlen(to_bin(basePayload)) == PROFILE.RULE.ALL1_HEADER_LENGTH);
        }

        return true;
    }

    /**
     * Checks if the fragment is an All-0
     * @return bool
     */
    bool is_all_zero() {
        char monoChar[] = "0";
        return is_monochar(HEADER.FCN,monoChar);
    }

    /**
     * Checks if the fragment can request an ACK
     * @param basePayload
     * @return
     */
    bool expects_ack(int basePayload) {
        return is_all_zero() || is_all_one(basePayload);
    }

    /**
     * Checks if the fragment is a SCHC Sender-Abort
     * @return
     */
    bool is_sender_abort(int basePayload) {
        char monoChar[] = "1";
        char payValue[] = "b ";
        if (not is_monochar(HEADER.FCN,monoChar) ||  not is_monochar(HEADER.W,monoChar)) {
            return false;
        }
        if (strcmp(PAYLOAD, payValue) == 0 ) {
            return strlen(to_bin(basePayload)) < PROFILE.RULE.ALL1_HEADER_LENGTH;
        }
        return false;
    }

    /**
     * Parses a hex string into a Fragment, using the specified Profile
     * @param hex
     * @return
     */
    static Fragment from_hex(char * hexString) {

        char emptyChar[] = "\0";
        char monoCharOne[] = "1";
        char monoCharZero[] = "0";
        cout << 1 <<endl;

        if (hexString == NULL || strcmp(hexString,emptyChar)==0) { }

        cout << 2 <<endl;
        Rule rule = rule.from_hex(hexString);
        cout << 2.1 <<endl;
        char *as_bin = hex_to_bin(hexString);
        ::printf("%s\n",as_bin);
        char direct[] = "UPLINK";
        SigFoxProfile  profile = SigFoxProfile(direct, FR_MODE, rule);

        int dtag_idx = profile.RULE_ID_SIZE;
        int w_idx = profile.RULE_ID_SIZE + profile.T;
        int fcn_idx = profile.RULE_ID_SIZE + profile.T + profile.M;
        int rcs_idx = profile.RULE_ID_SIZE + profile.T + profile.M + profile.N;

        char * fcn = cutChar(as_bin, fcn_idx, fcn_idx+profile.N);

        char * rcs;
        int header_length;

        cout << 3 <<endl;
        if (is_monochar(fcn,monoCharOne)) {
            cout << 4 <<endl;
            header_length = profile.RULE.ALL1_HEADER_LENGTH;
            int header_padding_index = rcs_idx + profile.U;

            cout << "header padding : "<<header_padding_index <<endl;
            cout << "header length : "<<header_padding_index <<endl;

            rcs = cutChar(as_bin, rcs_idx, rcs_idx + profile.U);

            if (strcmp(rcs, emptyChar) == 0) {
                cout << 4.1 <<endl;
                rcs = NULL;
            }

            if (round_to_next_multiple(rcs_idx + profile.U, L2_WORD_SIZE) != header_length) {
                cout << 4.2 <<endl;
                throw LengthMismatchError("All-1 Header length mismatch:");
            }

            char *header_padding = cutChar(as_bin, header_padding_index, header_length);
            ::printf("%s\n",header_padding);

            if (not is_monochar(header_padding, monoCharZero) && strcmp(header_padding, emptyChar) != 0) {
                cout << 4.3 <<endl;
                throw BadProfileError("Padding was not all zeroes nor empty");
            }
        }


        else {
            cout << 6 <<endl;
            int header_length = profile.RULE.HEADER_LENGTH;
            rcs = NULL;

            if (round_to_next_multiple(rcs_idx, L2_WORD_SIZE) != header_length) {
                    throw LengthMismatchError("Header length mismatch:");
            }

        }

        cout << 7 <<endl;
        cout << "dtag" << dtag_idx <<endl;
        cout << "t" << profile.T << endl;
        char *dtag = cutChar(as_bin,dtag_idx, dtag_idx+ profile.T);
        ::printf("hi%s\n",dtag);
        char *w = cutChar(as_bin,w_idx, w_idx+ profile.M);

        cout << 8.0 <<endl;

        FragmentHeader header = FragmentHeader(profile,dtag, w, fcn,rcs);
        int header_nibs = header_length/4 ;
        cout << 8.1 <<endl;
        char * payload = cutChar(hexString,header_nibs, strlen(hexString));
        cout << 8.2 <<endl;
        cout << 9 <<endl;

        return Fragment(header,payload);
    }

    /**
     * Returns a tuple of the indices (window, fragment) of the fragment,
     * formatted to be used as filenames
     * @return
     */
    vector<char*> get_indices() {
        char * w_index = zfill(itos(HEADER.WINDOW_NUMBER), pow(2,PROFILE.M-1) / (10+1) );
        char * f_index = zfill(itos(INDEX), PROFILE.WINDOW_SIZE / (10+1));
        vector <char*> result = {w_index,f_index};
        return result;
    }


    /**
     * Loads a stored fragment and parses it into a Fragment
     * @param path
     * @return

    static Fragment from_file(char * path) {};
    */


};


#endif //SCHC_CONTRIBUTION_FRAGMENT_H
