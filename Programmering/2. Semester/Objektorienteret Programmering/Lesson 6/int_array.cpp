#include "int_array.h"

int_array::int_array(int initial_size, int re_alloc_size) :
        size_(initial_size), head_(0), re_alloc_size_(re_alloc_size) {
    array_ = new int[size_]{};
}




void int_array::push_back(int value) {
    if (head_ == size_) {
        int *ptr = new int[size_ + re_alloc_size_];
        for (auto i = 0; i < size_; i++) {
            ptr[i] = array_[i];
        }
        size_ += re_alloc_size_;
        delete[] array_;
        array_ = ptr;
    }
    array_[head_++] = value;
}

int_array :: ~int_array(){
    for(auto i = 0; i < head_; i++){
        delete array_[i];
    }
    delete[] array_;
}


int_array :: int_array(const int_array &to_copy) : size_(to_copy.size_), head_(to_copy.head_), re_alloc_size_(to_copy.re_alloc_size_) {
    array_ = new int[size_]{};
    for (auto i = 0; i < head_; i++) {
        array_[i] = to_copy.array_[i];
    }
}
//deep copy assignment operator


int_array& operator=(const int_array &right_side){
    if(&right_side != this){
        for(auto i = 0 ; i < size_ ; i++){
            delete array_[i];
        }
        delete[] array_;
        array_ = new ;
    }

}

std::string int_array::to_string() const {
    std::string res;
    res.append("Head:");
    res.append(std::to_string(head_));
    res.append("\n");
    res.append("Size:");
    res.append(std::to_string(size_));
    res.append("\n");
    res.append("ReAllocSize:");
    res.append(std::to_string(size_));
    res.append("\n");
    for (auto i = 0; i < size_; i++) {
        res.append(std::to_string(array_[i]));
        res.append(" ");
    }
    return res;
}

[[nodiscard]] int int_array::get_size() const {
    return head_;
}

[[nodiscard]] int int_array::get_array_size() const {
    return size_;
}

[[nodiscard]] int int_array::get_re_alloc_size() const {
    return re_alloc_size_;
}