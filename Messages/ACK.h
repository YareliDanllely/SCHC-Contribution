#ifndef SCHC_CONTRIBUTION_ACK_H
#define SCHC_CONTRIBUTION_ACK_H
#include "SigFoxProfile.h"
#include "ACKHeader.h"

class ACK {
public:
    SigFoxProfile PROFILE;
    ACKHeader HEADER;
    char *DTAG;
    char *W;
    char *C;
    char *BITMAP;
    char *PADDING;

    /**
     * defining constructor and attributes
     * @param profile
     * @param dtag
     * @param w
     * @param c
     * @param bitmap
     * @param padding
     */
    ACK(SigFoxProfile profile, char * dtag, char * w, char * c, char * bitmap, char *padding = (char *) "\0");

    /**
     * Obtains the hex representation of the ACK
     * @return
     */
    char *to_hex();

    /**
     * Checks whether the ACK is a SCHC Receiver Abort
     * @return
     */
    bool is_receiver_abort();

    /**
     * Checks if the ACK can be parsed as a Compound ACK
     * @return
     */
    bool is_compound_ack();

    /**
     * Checks if the ACK reports the end of a SCHC session
     * @return
     */
    bool is_complete();

    /**
     * Creates an ACK from a hexadecimal string
     * @param hexString
     * @return
     */
    static ACK from_hex(char *hexString );

};


#endif //SCHC_CONTRIBUTION_ACK_H
