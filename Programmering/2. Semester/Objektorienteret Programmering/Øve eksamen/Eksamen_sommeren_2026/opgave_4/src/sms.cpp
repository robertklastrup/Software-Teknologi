#include "sms.h"
#include <string>

sms::sms(const std::string &message, const std::string &receiver, const std::string &sender)
    : message_(message), receiver_mobile_(receiver), sender_mobile_(sender) {
}

std::string sms::send() const{
    std::string e = message_ + sender_mobile_ + " to " + receiver_mobile_;
    return e;
}