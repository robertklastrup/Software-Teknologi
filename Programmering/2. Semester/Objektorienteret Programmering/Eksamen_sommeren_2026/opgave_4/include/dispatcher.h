#pragma once
#include "message.h"

class dispatcher {
    std::vector<message *> messages_;
    public:
        void add_message(message* mes);
        void send_all();
};
