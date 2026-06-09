#include "opg5.h"



int main (){
    Student s1 ("Robert", 22, syv);
    Student s2 ("Anna", 23, tolv);
    Student s3 ("Benjamin", 23, ti);
    Student s4 ("Kevin", 24, to);

    s1.isValid();
    s2.isValid();
    s3.isValid();
    s4.isValid();

    gennemsnit({syv, tolv, ti, to}, 2);
}