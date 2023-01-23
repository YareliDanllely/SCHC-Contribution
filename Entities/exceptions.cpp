#include "exceptions.h"
#include "string"

LengthMismatchError::LengthMismatchError(string msg) : SCHCError(msg) {}
