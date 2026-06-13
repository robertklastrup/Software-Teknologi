#include <iostream>

using namespace std;

#include <iostream>

using namespace std;


struct player {
    string PlayerName;
    int level;
    int experience;
    int lives;

    player(string p, int l, int e, int li){
        PlayerName = p;
        level = l;
        experience = e;
        lives = li;
    }
};

struct weapon{
    string Name;
    int Damage;
    double Weight;

    weapon(string n, int d, double w){
        Name = n;
        Damage = d;
        Weight = w;
    }

    void describe(){
        cout << Name << endl << "Damage: " << Damage << " Weight: " << Weight << endl;
    }
};


int main (){
    player p1 ("Kevin", 10, 90, 3);
    player p2 ("Robert", 10, 90, 3);

    weapon w1 ("Blade of the ruined king", 120, 45);
    weapon w2 ("Yoda's Lightsaber", 170, 15);
    weapon w3 ("Thors Hammer", 350, 100);

    w1.describe();
    w2.describe();
    w3.describe();

}