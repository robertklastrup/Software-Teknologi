#include <iostream>
#include <vector>
using namespace std;

// Person-klasse med ssn og navn:
class Person {
    friend ostream& operator<<(ostream& os, const Person& p);

    private:
        int ssn_;
        string name_;
    public:
        // sætter ssn og navn:
        Person(int s, const string& n) : ssn_(s), name_(n) {}
};

// overload: giver << ny betydning for Person (print ssn + navn):
ostream& operator<<(ostream& os, const Person& p) {
    os << "Ssn:" << p.ssn_ << " Name:" << p.name_;
    return os;
}

int main() {
    // vector med 10 ens Person-objekter:
    vector<Person> persons(10, Person(1, "John Doe"));

    // printer alle personer med index-loop:
    for (int i = 0; i < persons.size(); i++) {
        cout << persons[i];
        if (i < persons.size() - 1) cout << "\n";
    }
}
