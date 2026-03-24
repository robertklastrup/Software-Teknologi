#include <iostream>


class cat {
    private:
        std::string name_;
        int height_;
        int weight_;

    public:
        cat(const std::string& name, int height, int weight);
        double body_mass_index() const;
        std::string to_string() const;
};

class cat_array {
    private:
        cat**array_;
        int head_;
        int size_;
        int re_alloc_size;

    public:
        cat_array(int initial_size, int re_alloc_size_){
            size_ = initial_size;
            head_ = 0;
            re_alloc_size = re_alloc_size_;
            array_ = new cat*[initial_size]{};
        }

        ~cat_array() {
                for (int i = 0; i < head_; i++) {
                delete array_[i];
            }
            delete[] array_;       
        }

        void add (std::string name, int height, int weight){
            if (head_ == size_) {
                cat** new_array = new cat*[size_ + re_alloc_size]{};

                for (int i = 0; i < size_; i++) {
                    new_array[i] = array_[i];
                }

                delete[] array_;
                array_ = new_array;
                size_ = size_ + re_alloc_size;
            }
            array_[head_] = new cat(name, height, weight);
            head_++;
        }

        int get_size() const{
            return head_;
        }
    
        int get_array_size() const{
            return size_;
        }

};


        

int main (){

    cat cat1("Misser", 30, 5);
    std::cout << cat1.to_string() << std::endl;
    std::cout << "BMI: " << cat1.body_mass_index() << std::endl;

    return 0;
}