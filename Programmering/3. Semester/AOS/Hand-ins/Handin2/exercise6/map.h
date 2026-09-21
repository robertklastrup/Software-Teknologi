#include <vector>
#include <utility>
#include <stdexcept>
#include <iostream>


template<typename Key, typename Value>
class Vector_map{
    std:: vector<std::pair<Key,Value>> vec;

public:

    int size(){
        return vec.size();
    }

    bool empty(){
        return vec.size() == 0;
    }

    void insert(Key key, Value value){

        for(int i = 0; i < vec.size(); i++){
            if(vec[i].first == key){ 
                vec[i].second = value; 
                return;
            }
        }
        vec.emplace_back(key, value);
    }


    Value find(Key key){
        if(empty()){throw std::out_of_range("Vector empty"); }
 
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].first == key){
                return vec[i].second;
            }
        }
        throw std::out_of_range("Key not found");
    }


    void remove(Key key){
        if(empty()){throw std::out_of_range("Vector empty"); }
 
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].first == key){
                vec.erase(vec.begin()+i);
                return;
            }
        }
    }

    bool contains(Key key){
        if(empty()){throw std::out_of_range("Vector empty"); }
 
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].first == key){
                return true;
            }
        }
        return false;    
    }

    void print(){
        if(empty()){throw std::out_of_range("Vector empty"); }
 
        for(int i = 0; i < vec.size(); i++){
            std:: cout << "[" << i+1 << "] Key: " << vec[i].first << ", Value: " << vec[i].second << "\n";
        } 
    }
};

