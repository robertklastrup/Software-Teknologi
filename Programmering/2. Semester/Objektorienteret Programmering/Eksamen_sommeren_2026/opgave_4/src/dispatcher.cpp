#include "dispatcher.h"
#include <iostream>


void dispatcher::add_message(message* mes){
    messages_.push_back(mes);
}

void dispatcher::send_all(){
    std::string send;
    for (int i = 0; i < messages_.size(); i++){
        send = send + " " + messages_[i]->send() + "\n";
    }
    std::cout << send << std::endl;
    messages_.clear();
}