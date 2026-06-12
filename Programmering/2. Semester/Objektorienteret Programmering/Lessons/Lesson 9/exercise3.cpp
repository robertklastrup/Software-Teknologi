#include <iostream>
using namespace std;


#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Person-klasse med copy-konstruktør:
class Person{
    friend ostream &operator<<(ostream &, const Person &);

    public:
        // sætter ssn og navn:
        Person (int ssn, const string &name) : ssn_(ssn), name_(name) {}

        // kopierer eksisterende Person-objekt:
        Person (const Person &to_copy) : ssn_(to_copy.ssn_), name_(to_copy.name_){
            cout << "Copy Ctor called" << '\n';
        }
        int ssn_;
        string name_;
};

// overload: giver << ny betydning for Person (print ssn + navn):
ostream &operator << (ostream &os, const Person &Person){
    os << "Ssn: " << Person.ssn_ << " Name: " << Person.name_;
    return os;
}


int main() {
    // deque: vector med hurtig indsæt begge ender:
    deque<Person> persons;

    // indsætter 3 personer forrest (nyeste kommer først):
    persons.emplace_front(1, "Jeff Doe");
    persons.emplace_front(2, "Jeff Doe");
    persons.emplace_front(3, "Jeff Doe");

    // printer alle personer i deque:
    for (const auto& p : persons) {
        cout << p << '\n';
    }
}
