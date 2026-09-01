#include "email.h"

email::email(const std::string &message, const std::string &receiver, const std::string &sender)
    : message_(message), receiver_email_(receiver), sender_email_(sender) {
}

std::string email::send() const {
    std::string e = message_ + sender_email_ + " to " + receiver_email_;
    return e;
}