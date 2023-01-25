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

    /**
     * defining constructor and attributes
     * @param header
     * @param payload
     */
    Fragment(FragmentHeader header, char * payload);

    /**
     * Returns the bin representation of the Fragment.
     * @return char *
     */
    char *to_bin() ;

    /**
     * Checks if the fragment is an All-1
     * @return bool
     */
    bool is_all_one() ;

    /**
     * Checks if the fragment is an All-0
     * @return bool
     */
    bool is_all_zero() ;

    /**
     * Checks if the fragment can request an ACK
     * @param basePayload
     * @return
     */
    bool expects_ack();

    /**
     * Checks if the fragment is a SCHC Sender-Abort
     * @return
     */
    bool is_sender_abort();

    /**
     * Parses a hex string into a Fragment, using the specified Profile
     * @param hex
     * @return
     */
    static Fragment from_hex(char * hexString);

    /**
     * Returns a tuple of the indices (window, fragment) of the fragment,
     * formatted to be used as filenames
     * @return
     */
    vector<char*> get_indices();


    /**
     * Loads a stored fragment and parses it into a Fragment
     * @param path
     * @return
    **/
    static Fragment from_file(char * path) ;


};


#endif //SCHC_CONTRIBUTION_FRAGMENT_H
