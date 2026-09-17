#include <iostream>


struct Node{
    int value;
    Node* next;
};


Node* push_front(Node* head, int value){
    Node* newHead = new Node{value, head};
    return (newHead);
}

Node* push_back(Node* head, int value){
    Node* newHead = nullptr;
    if (head == nullptr){
        newHead = new Node {value, head};
    }
    else {
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = new Node {value, nullptr};
        return head;
    }
    return (newHead);
}

Node* insert_at(Node* head, int pos, int value) {
    Node* newHead = nullptr;
    Node* current = head;

    if (pos == 0){
        head = push_front(head, value);
        return head;
    }
    else{
        for(int i = 0; i < pos - 1; i++){
            current = current->next;
        }
        Node* rest = current->next;
        current->next = new Node {value, rest};
        return head;
    }
    return (newHead);
}

Node* delete_front(Node* head){
    Node* newHead = nullptr;
    if(head == nullptr){
        return newHead;
    }
    else{
        Node* next = head->next;
        delete head;
        return next;
    }
    return newHead;
}

Node* delete_end(Node* head){
    Node* current = head;
    Node* prev = nullptr;
    if(head == nullptr){
        return prev;
    }
    else{
        while(current->next != nullptr){
            prev = current;
            current = current->next;
        }
        delete current;

        if(prev == nullptr){
            return prev;
        }
        else{
            prev->next = nullptr;
            return head;
        }
        return head;

    }
}

Node* delete_at(Node* head, int pos){
    Node* current = head;
    Node* prev = nullptr;

    if(pos == 0){
        head = delete_front(head);
        return head;
    }
    else{
        for (int i = 0; i < pos; i++){
            prev = current;
            current = current->next;
        }
        Node* toDelete = prev->next;
        prev->next = current->next;
        delete toDelete;
        return head;
    }
    return prev;
}

bool contains(Node* head, int value){
    Node* current = head;

    if(head == nullptr){
        return false;
    }
    while(current->value != value){
        current = current->next;
        if (current == nullptr){
            return false;
        }
    }
    if (current->value == value){
        return true;
    }
    else{
        return false;
    }
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr){
        Node* next = current->next;
        current ->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


int main (){
    Node* head = nullptr;           //Vigtigt!: start med en nullptr, som vi kan overskrive
    head = push_front(head, 3);     //Start med sidste tal først, da det ellers bliver forkert rækkefølge
    head = push_front(head, 2);
    head = push_front(head, 1);
    head = push_back(head, 4);      //Nu sætter vi en ny node bagerst i listen.
    head = push_back(head, 5);
    head = push_back(head, 6);
    head = insert_at(head, 2, 7);
    head = insert_at(head, 5, 7);
    head = insert_at(head, 4, 7);
    head = delete_front(head);
    head = delete_end(head);
    head = delete_at(head, 5);
    


    Node* current = head;           //Vi laver en Node pointer som hedder current, for at kunne lave et loop
    while (current != nullptr) {    //Stopper når vi rammer en nullpointer, som bliver efter vores sidste value
        std::cout << current->value << ", ";
        current = current->next;
    }
    std::cout << std::endl;
    if(contains(head, 2) == true){
        std::cout << "The list contains 2" << std::endl;
    }
    else{
        std::cout << "2 could not be found in the list" << std::endl;
    }

    head = reverse(head);
    current = head;
    while (current != nullptr) {
        std::cout << current->value << ", ";
        current = current->next;
    }
    std::cout << std::endl;
}