#include <iostream>


class cat {
    public:
        cat(const std::string& name, int height, int weight);
        double body_mass_index() const;
        std::string to_string() const;

    private:
        std::string name_;
        int height_;
        int weight_;
        cat**array 

};
        

int main (){

    cat cat1("Misser", 30, 5);
    std::cout << cat1.to_string() << std::endl;
    std::cout << "BMI: " << cat1.body_mass_index() << std::endl;

    return 0;
}