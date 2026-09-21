#pragma once

#include "list.h"
#include <iostream>

template <typename Object>
class Linkedlist : public List<Object>{
private:
    struct Node{
	    Object  data;
	    Node   *next;
	};

	int   theSize;
	Node *head;
	Node *tail;

	Node* find_second_last_node(){
		if (head == nullptr)
			return nullptr;
		Node *last = head;
		while (last->next != tail) {
			last = last->next;
		}
		return last;
	}

public:
	~Linkedlist(){
		clear();
		delete head;
		delete tail;
	}

	Linkedlist(){
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->next = nullptr;
	}

	int size(){
        return theSize;
    }
	bool empty(){
		return head->next == tail;
	};
	void clear(){
		Node *current = head->next;   // start ved første RIGTIGE node (ikke sentinel-head)
		while (current != tail) {     // stop ved sentinel-tail
			Node *next = current->next;  // gem next FØR vi sletter
			delete current;
			current = next;
		}
		head->next = tail;
		theSize = 0;
	}

	void push_front(const Object x){
		Node *p = new Node;
		p->data = x;
		p->next = head->next;
		head->next = p;
		theSize++;
    }

	void push_back(const Object x){
    	if (empty()) { 
			push_front(x);
			return;
		}
		Node *b = new Node;
		b->data = x;

		Node *temp = head;
		while(temp->next != tail){
			temp = temp->next;
		}	
		temp->next = b;
		b->next = tail;
		theSize++;
	}

	void push_middle(int pos, const Object x){
		if(pos >= theSize){
			throw std::out_of_range("Position is bigger than the size of the linkedlist");
		}

		Node *p = new Node;
		p->data = x;
		Node *temp = head->next;
		int count = 1;
		while(count < pos){
			temp = temp->next;
			count++;
		}
		p->next = temp->next;
		temp->next = p;
		theSize++;
	}


	Object pop_front(){
		if(empty()){
			throw std::out_of_range("Linkedlist empty\n");
		}

		Node *temp = head->next;
		head->next = temp->next;
		Object x = temp->data;
		delete temp;
		theSize--;
		return x;
	}

    

	Object pop_back(){
		if(empty()){
			throw std::out_of_range("Linkedlist empty\n");
		}
		Node *Last = find_second_last_node();
		Node *prev = head;
		while(prev->next != Last){
			prev = prev->next;
		}
		Object x = Last->data;
		prev->next = tail;
		delete Last;
		theSize--;
		return x;
    }

	Object pop_middle(int pos){
		if(pos <= 0 || pos >= theSize){
			throw std::out_of_range("Invalid position for pop_middle");
		}
			Node *temp = head->next;
			int count = 0;
			while(count < pos-1){
				temp = temp->next;
				count++;
			}
			
			Node *pop = temp->next;
			Object x = pop->data;
			temp->next = pop->next;

			delete pop;
			theSize--;
			return x;
		}

	Object find(const Object x){
		if(head->next==tail){
			throw std::out_of_range("Linkedlist empty\n");
		}

		Node *temp = head->next;
		while(temp != tail && temp->data != x){
			temp = temp->next;
		}
    	if(temp == tail){
        	throw std::out_of_range("Element not found");
    	}
		return temp->data;
	}

	void print(){
		if(empty()){
			throw std::out_of_range("Linkedlist empty\n");
		}
		Node *temp = head;
		std:: cout << "head->";
		while(temp->next != tail){
			temp = temp->next;
			std:: cout << "[" << temp->data << "]->";
		}
		std:: cout << "tail\n";
	}

	void reverse(){
		if(empty()){
			throw std::out_of_range("Linkedlist empty\n");
		}
		Node* current = head->next;
		Node* prev = tail;
		while(current != tail){
			Node *next = current->next;   
			current->next = prev;        
			prev = current;                  
			current = next;                   
		}
		head->next = prev;

	}
};