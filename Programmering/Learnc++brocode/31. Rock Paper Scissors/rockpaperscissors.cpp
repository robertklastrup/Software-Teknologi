#include    <iostream>
#include    <ctime>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main() {
    char player;
    char computer;

    player = getUserChoice();
    cout << "Dit valg er: ";
    showChoice(player);

    computer = getComputerChoice();
    cout << "Computerens valg er: ";
    showChoice(computer);

    chooseWinner(player, computer);

    return 0;
}


char getUserChoice(){
    char player;

    cout << "Sten saks papir!" << '\n';
    do {
        cout << "Vælg en af disse muligheder: \n";
        cout << "**************************************\n";
        
        cout << "r for sten" << '\n';
        cout << "p for papir" << '\n';
        cout << "s for saks" << '\n';
        cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice(){
    srand (time (0));
    int num = rand() % 3 + 1;
    switch (num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
        //vi behøver ikke break da vi returnerer direkte.
    }

    return 0;
}

void showChoice(char choice){

    switch (choice){
        case 'r': cout << "Sten" << '\n';
            break;
        case 'p': cout << "Papir" << '\n';
            break;
        case 's': cout << "Saks" << '\n';
            break;
    }

    
}

void chooseWinner(char player, char computer){

    switch (player){
        case 'r':
            if (computer == 'r'){
                cout << "Uafgjort!" << '\n';
            }
            else if (computer == 'p'){
                cout << "Computer vinder!" << '\n';
            }
            else if (computer == 's'){
                cout << "Du vinder!" << '\n';
            }
            break;
        case 'p':
            if (computer == 'r'){
                cout << "Du vinder!" << '\n';
            }
            else if (computer == 'p'){
                cout << "Uafgjort!" << '\n';
            }
            else if (computer == 's'){
                cout << "Computer vinder!" << '\n';
            }
            break;
        case 's':
            if (computer == 'r'){
                cout << "Computer vinder!" << '\n';
            }
            else if (computer == 'p'){
                cout << "Du vinder!" << '\n';
            }
            else if (computer == 's'){
                cout << "Uafgjort!" << '\n';
            }
            break;
    }

    
}