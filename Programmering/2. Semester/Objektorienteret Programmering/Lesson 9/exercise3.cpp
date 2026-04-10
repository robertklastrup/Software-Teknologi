#include <iostream>
using namespace std;


#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Person{
    friend ostream &operator<<(ostream &, const Person &);

    public:
        Person (int ssn, const string &name) : ssn_(ssn), name_(name) {}

        Person (const Person &to_copy) : ssn_(to_copy.ssn_), name_(to_copy.name_){
            cout << "Copy Ctor called" << '\n';
        }
        int ssn_;
        string name_;   
};

ostream &operator << (ostream &os, const Person &Person){
    os << "Ssn: " << Person.ssn_ << " Name: " << Person.name_;
    return os;
}


int main() {
   
    deque<Person> persons;

    persons.emplace_front(1, "Jeff Doe");
    persons.emplace_front(2, "Jeff Doe");
    persons.emplace_front(3, "Jeff Doe");

    for (const auto& p : persons) {
        cout << p << '\n';
    }
}
