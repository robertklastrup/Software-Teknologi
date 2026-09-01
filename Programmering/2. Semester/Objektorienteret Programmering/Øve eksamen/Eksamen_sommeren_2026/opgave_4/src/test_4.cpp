#include "test_4.h"
#include "email.h"
#include "sms.h"
#include "dispatcher.h"
#include <iostream>

void test_send_email() {
    email e ("Sending email hello from ", "Michel", "Robert");
    std::cout << e.send() << std::endl;

}

void test_send_sms() {
    sms s ("Sending sms hello from ", "Michel", "Robert");
    std::cout << s.send() << std::endl;
}

void test_dispatcher() {
    dispatcher d;
    sms s1 ("Sending sms hello from ", "Michel", "Robert");
    sms s2 ("Have a nice day (sms) from ", "Michel", "Robert");
    email e1 ("Sending email hello from ", "Michel", "Robert");
    email e2 ("Have a nice day (email) from ", "Michel", "Robert");
    
    d.add_message(&s1);
    d.add_message(&s2);
    d.add_message(&e1);
    d.add_message(&e2);

    d.send_all();

    d.send_all();
}
