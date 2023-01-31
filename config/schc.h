#ifndef SCHC_CONTRIBUTION_SCHC_H
#define SCHC_CONTRIBUTION_SCHC_H

/**
 * Global variables
 */

extern char FR_MODE[];
extern int RETRANSMISSION_TIMEOUT ;  /* in seconds */
extern int SIGFOX_DL_TIMEOUT; /* in seconds */
extern int INACTIVITY_TIMEOUT;  /* in seconds */
extern int MAX_ACK_REQUESTS;
extern int L2_WORD_SIZE;
extern int DELAY_BETWEEN_FRAGMENTS; /* in seconds */

/* Sender config */
extern bool ENABLE_MAX_ACK_REQUESTS ;

/* Receiver config */
extern bool RESET_DATA_AFTER_REASSEMBLY ;
extern bool CHECK_FOR_CALLBACK_RETRIES ;
extern bool DISABLE_INACTIVITY_TIMEOUT;

extern char RECEIVER_URL[];

#endif //SCHC_CONTRIBUTION_SCHC_H
