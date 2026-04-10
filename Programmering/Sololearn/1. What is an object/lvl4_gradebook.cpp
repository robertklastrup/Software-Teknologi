#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Build your class here
class Student{
    public:
        string student;
        double average;
        vector <double> grades;
    
    Student(string n){
        student = n;
    }

    void addGrade(double grade){
        grades.push_back(grade);
    }

    double getAverage (){
        double sum = 0;
        for (int i = 0; i < grades.size(); i++){
            sum = sum + grades[i];
        }
        return (sum / grades.size());
    }

    void describe (){
        cout << "Student: " << student << endl;
        cout << "Average grade: " << getAverage() << endl;
    }

};



int main() {
    // Create a Student object
    Student a("Robert");
    // Add at least 4 grades
    a.addGrade(7);
    a.addGrade(4);
    a.addGrade(12);
    a.addGrade(2);

    // Call describe()
    a.describe();
}