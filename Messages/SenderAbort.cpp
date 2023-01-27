#include "SenderAbort.h"


SenderAbort::SenderAbort(FragmentHeader header) :
PROFILE(header.PROFILE),
Fragment(FragmentHeader(header.PROFILE,header.DTAG,severalChar(header.PROFILE.M,(char *) "1"), \
severalChar(header.PROFILE.N,(char *) "1"),NULL), (char *) "\0") {}

