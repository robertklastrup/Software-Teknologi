#include <iostream>
using namespace std;


class int_array{
    private:
        int size_;
        int head_;
        int re_alloc_size_;
        int* array_;
    public:
        int_array(int i, int re) : size_(i), head_(0), re_alloc_size_(re){
            array_ = new int [i]{};
        }
        ~int_array(){
            delete[] array_;
        }
        void push_back (int v){
            if(head_ == size_){
                int* new_array = new int [size_ + re_alloc_size_];
                    for (int i = 0; i < size_; i++){
                        new_array[i] = array_[i];
                    }
                size_ = size_ + re_alloc_size_;
                delete[] array_;
                array_ = new_array;
            }
            array_[head_] = v;
            head_ = head_ + 1;
        }


        int get_size() const{
            return (head_);
        }
        int get_array_size() const{
            return (size_);
        }
        string to_string() const{
            string result = "";
            
            for (int i = 0; i < head_; i++){
                if(i > 0){
                    result = result + " ";
                }
                result = result + std::to_string(array_[i]);
            }
            return (result);
        }

};

int main(){
    int_array a1 (3,2);
    a1.push_back(5);
    a1.push_back(3);
    a1.push_back(20);
    a1.push_back(16);
    a1.push_back(12);

    cout << a1.to_string() << endl;
    cout << a1.get_size() << endl;
    cout << a1.get_array_size() << endl;

}