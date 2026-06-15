#include "Formatter.h"
#include "PrefixFormatter.h"
#include "Report.h"
#include "UpperCaseFormatter.h"
#include <iostream>


int main (){
    Report r ("hello world");
    PrefixFormatter p ("[Info]");
    UpperCaseFormatter u;

    r.add(&p);
    r.add(&u);

    std::cout << r.process() << std::endl;
}   