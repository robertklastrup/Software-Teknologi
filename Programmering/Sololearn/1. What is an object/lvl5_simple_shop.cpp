#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Build your Product class here
class Product{
    public:
        string name;
        double price;

    Product(string n, double p){
        name = n;
        price = p;
    }
    void describe (){
        cout << name << ": " << price << endl;
    }
};

// Build your Shop class here
class Shop {
    public:
        string shopName;
        vector <Product> products;
    Shop (string sN){
        shopName = sN;
    }
    void addProduct(Product x){
        products.push_back(x);
    }
    Product findCheapest(){
        int cheapestIndex = 0;
        for (int i = 0; i < products.size(); i++ ){
            if (products[i].price < products[cheapestIndex].price){
                cheapestIndex = i;
            }
        }
        return (products[cheapestIndex]);
    }
    void describe(){
        cout << "Shop: " << shopName << endl;
        cout << "-----------------" << endl;
        for (int i = 0; i < products.size(); i++){
            products[i].describe();
        }
        cout << "-----------------" << endl;
    }
};


int main() {
    // Create a Shop
    Shop R ("Roberts Shop");
    
    // Add at least 4 products
    Product p1 ("Æble", 2.5);
    Product p2 ("Pære", 2.1);
    Product p3 ("Banan", 1.2);
    Product p4 ("Kiwi", 8.3);

    R.addProduct(p1);
    R.addProduct(p2);
    R.addProduct(p3);
    R.addProduct(p4);

    // Call describe() on the shop
    R.describe();
    // Find and describe() the cheapest product
    Product cheapest = R.findCheapest();
    cheapest.describe();
}