#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Build your Guest class here
class Guest{
    public:
        string name;
        int age;

    Guest(string n, int a){
        name = n;
        age = a;
    }
    void describe(){
        cout << name << " (" << age << ")" << endl;
    }

};

// Build your Room class here
class Room{
    public:
        int roomNumber;
        double pricePerNight;
        bool isOccupied;

    Room(int r, double p){
        roomNumber = r;
        pricePerNight = p;
        isOccupied = false;
    }
    void describe(){
        if (isOccupied == false){
            cout << "Room " << roomNumber << ": " << pricePerNight << " - Available" << endl;
        }
        else{
            cout << "Room " << roomNumber << ": " << pricePerNight << " - Occupied" << endl;
        }
    }
    void occupy(){
        isOccupied = true;
    }
    void vacate(){
        isOccupied = false;
    }

};

// Build your Hotel class here
class Hotel{
    public:
        string hotelName;
        vector <Room> rooms;
        vector <Guest> guests;
    
    Hotel (string h){
        hotelName = h;
    }
    void addRoom(Room r){
        rooms.push_back(r);
    }
    void addGuest(Guest g){
        guests.push_back(g);
    }
    Room findAvailableRoom(){
        for (int i = 0; i < rooms.size(); i++){
            if (rooms[i].isOccupied == false){
                return (rooms [i]);
            }
        }
    }
    double getTotalRevenue(){
        double sum = 0.0;
        for (int i = 0; i < rooms.size() ; i++){
            if (rooms[i].isOccupied == true){
                sum = sum + rooms[i].pricePerNight;
            }
        }
        return (sum);
    }
    void describe (){
        cout << "Hotel: " << hotelName << endl;
        cout << "------------------" << endl;
        for (int i = 0; i < rooms.size();i++){
            rooms[i].describe();
        }
        for (int i = 0; i < guests.size();i++){
            guests[i].describe();
        }
    }




};

int main() {
    // Create a Hotel
    Hotel h1 ("Rob The Code Goats Hotel");
    // Add at least 3 rooms
    Room r1 (101, 808.69);
    Room r2 (102, 700.67);
    Room r3 (103, 420.69);
    Room r4 (104, 69.69);

    h1.addRoom (r1);
    h1.addRoom (r2);
    h1.addRoom (r3);
    h1.addRoom (r4);

    // Add at least 3 guests
    Guest g1 ("Robert", 22);
    Guest g2 ("Malthe", 24);
    Guest g3 ("Moein", 13);
    Guest g4 ("Kevin", 23);
    Guest g5 ("Carl-Emil", 22);

    h1.addGuest(g1);
    h1.addGuest(g2);
    h1.addGuest(g3);
    h1.addGuest(g4);
    h1.addGuest(g5);

    // Occupy some rooms
    h1.rooms[0].occupy();
    h1.rooms[1].occupy();
    h1.rooms[3].occupy();

    // Call describe()
    h1.describe();

    // Print total revenue
    cout << "------------------" << endl;
    cout << h1.getTotalRevenue() << endl;

    cout << "------------------" << endl;
    Room available = h1.findAvailableRoom();
    available.describe();
}