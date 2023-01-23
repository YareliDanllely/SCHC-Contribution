#include "exceptions.h"
#include "string"

LengthMismatchError::LengthMismatchError(const string &msg) : SCHCError(msg) {}

SCHCTimeoutError::SCHCTimeoutError(const string &msg) : SCHCError(msg) {}

RuleSelectionError::RuleSelectionError(const string &msg) : SCHCError(msg) {}

SenderAbortError::SenderAbortError(const string &msg) : SCHCError(msg) {}

ReceiveAbortError::ReceiveAbortError(const string &msg) : SCHCError(msg) {}

BadProfileError::BadProfileError(const string &msg) : SCHCError(msg) {}

NetworkDownError::NetworkDownError(const string &msg) : SCHCError(msg) {}
