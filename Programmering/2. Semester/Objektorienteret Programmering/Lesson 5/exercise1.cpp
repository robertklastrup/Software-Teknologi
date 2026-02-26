#include <iostream>



class int_array {

    private:
        int size_;
        int head_;
        int re_alloc_size_;
        int* array_;
        
    public:

    int_array (int initialSize, int re_alloc_size){
        size_ = initialSize;
        head_ = 0;
        re_alloc_size_ = re_alloc_size;
        array_ = new int[initialSize]{};
    }

    ~int_array(){
        delete[] array_;
    }

    void push_back (int value){
        if (head_ == size_){
            int* new_array = new int[size_ + re_alloc_size_]{};

            for (int i = 0; i < size_ ; i++){
                new_array[i] = array_[i];
            };

            delete[] array_;
            array_ = new_array;
            size_ = size_ + re_alloc_size_;
        }
        array_[head_] = value;
        head_++;
    }
    
    std::string to_string () const{
        std::string result;

        for (int i = 0; i < head_ ; i++){
            result += std::to_string(array_[i]);
            result +=" ";
        }

        return result;
    }

    
    int get_size() const{
        return head_;
    }
    
    int get_array_size() const{
        return size_;
    }
};


int main (){
    
    int_array mit_array(5,3);

    mit_array.push_back (14);

    mit_array.push_back (23);

    mit_array.push_back (45);

    mit_array.push_back (66);

    mit_array.push_back (67);

    mit_array.push_back (81);

    mit_array.push_back (96);

    std::cout << mit_array.to_string() << '\n';
    return 0;
}