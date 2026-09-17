#include <iostream>

template <typename Object>
class List{
    private:
        struct Node{
            Object value;
            Node* next;
        };
        Node* head;

    public:
        List() : head(nullptr){}

        void push_front(Object value){
            head = new Node {value, head};
        }

        void print(){
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->value << ", ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        void push_back(Object value){
            if(head == nullptr){
                head = new Node {value, head};
            }
            else{
                Node* current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = new Node {value, nullptr};
            }
        }
};

int main(){
    List<int> list;

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    list.print();

    list.push_back(4);

}