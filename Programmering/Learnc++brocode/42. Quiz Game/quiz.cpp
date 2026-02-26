#include    <iostream>
#include   <array>
#include   <string>
#include  <cmath>

using namespace std;




int main () 
{
    string questions[] = { "1. Hvilket år blev Robert født?", 
                           "2. Hvad er hovedstaden i Danmark?", 
                           "3. Hvad er 5 + 7?", 
                           "4. Er jorden flad?"};
        
    

    string options [][4] = {{"a. 1999", "b. 1980", "c. 2003", "d. 2002"},
                            {"a. Aarhus", "b. Odense", "c. København", "d. Aalborg"},
                            {"a. 10", "b. 11", "c. 12", "d. 13"},
                            {"a. Ja", "b. Nej", "c. Måske", "d. Ved ikke"}};
    
    char answers[] = {'c', 'c', 'c', 'b'}; 
    
    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score;

    //iteration:
    for(int i = 0; i < size; i++) {
        cout << "*************************" << endl;
        cout << questions[i] << endl;
        cout << "*************************" << endl;

        
        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
            cout << options[i][j] << endl;
            
        }
        cin >> guess;
        guess = tolower(guess);

        //hvis gættet er det samme som vores svar:
        if(guess == answers[i]) {
            cout << "Korrekt!" << endl;
            score++;
        } else {
            cout << "Forkert!" << endl;
            cout << "Det rigtige svar var: " << answers[i] << endl;
        }
    }

    cout << "*************************" <<  endl;
    cout << "*        RESULTAT        *" << endl;
    cout << "*************************" <<  endl;
    cout << "KORREKTE SVAR: " << score << endl;
    cout << "ANTAL SPØRGSMÅL: " << size << endl;
    cout << "DIN SCORE: " << (score / (double)size) * 100 << "%" << endl;

    return 0;
}