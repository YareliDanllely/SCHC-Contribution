#ifndef SCHC_CONTRIBUTION_EXCEPTIONS_H
#define SCHC_CONTRIBUTION_EXCEPTIONS_H
#include <exception>
#include <string>
using namespace std;

/**
 * Base class for other exceptions
 */
class SCHCError : public exception {

public:
    string message;

    SCHCError(string msg) : message(msg) {}

    string what(){
        return message;
    }

};

/**
 * Raised when the value of any SCHC field, object or structure
 * doesn't match its expected size
 */
class LengthMismatchError : public SCHCError {
public:
    explicit LengthMismatchError(const string &msg);
};


/**
 * Raised when any timer (SCHC sender or receiver) expires
 */
class  SCHCTimeoutError : public SCHCError {
public:
    explicit SCHCTimeoutError(const string &msg);
};


/**
 * Raised when a Rule ID cannot be selected
 * according to the SCHC Profile
 */
class RuleSelectionError : public SCHCError {
public:
    explicit RuleSelectionError(const string &msg);

};

/**
 * Raised when a SCHC Sender-Abort message is sent or received
 */
class SenderAbortError : public SCHCError {
public:
    explicit SenderAbortError(const string &msg);
};

/*
 * Raised when a SCHC Receiver-Abort message is sent or received
 */
class ReceiveAbortError : public SCHCError {
public:
    explicit ReceiveAbortError(const string &msg);
};

/**
 * Raised when the behavior of the SCHC Sender or Receiver
 * does not match the behavior specified by the profile
 */
class BadProfileError : public SCHCError {
public:
    explicit BadProfileError(const string &msg);
};

/**
 * Raised when the network is assumed to be unable to transmit data
 */
class NetworkDownError : public  SCHCError {
public:
    explicit NetworkDownError(const string &msg);
};

#endif //SCHC_CONTRIBUTION_EXCEPTIONS_H
