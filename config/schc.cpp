#include "schc.h"

char FR_MODE[] = "ACK ON ERROR";
int RETRANSMISSION_TIMEOUT = 100;
int SIGFOX_DL_TIMEOUT = 60; /* in seconds */
int INACTIVITY_TIMEOUT = 500;  /* in seconds */
int MAX_ACK_REQUESTS = 5;
int L2_WORD_SIZE= 8;
int DELAY_BETWEEN_FRAGMENTS = 10; /* in seconds */

/* Sender config */
bool ENABLE_MAX_ACK_REQUESTS  = true;

/* Receiver config */
bool RESET_DATA_AFTER_REASSEMBLY = false ;
bool CHECK_FOR_CALLBACK_RETRIES  = true;
bool DISABLE_INACTIVITY_TIMEOUT = false;

char RECEIVER_URL[] = "http://localhost:5000/receive";



