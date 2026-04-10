#include <iostream>
#include <vector>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& os, const Person& p);

    private:
        int ssn_;
        string name_;
    public:
        Person(int s, const string& n) : ssn_(s), name_(n) {}
};
ostream& operator<<(ostream& os, const Person& p) {
    os << "Ssn:" << p.ssn_ << " Name:" << p.name_;
    return os;
}

int main() {
    vector<Person> persons(10, Person(1, "John Doe"));

    for (int i = 0; i < persons.size(); i++) {
        cout << persons[i];
        if (i < persons.size() - 1) cout << "\n";
    }
}