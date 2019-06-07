//
// Created by guy-pc on 6/7/19.
//

#ifndef CONFIGURE_LINKEDLIST_H
#define CONFIGURE_LINKEDLIST_H
#include<cmath>
#include <ostream>
#include <cmath>
#include <assert.h>
#include <iostream>

template <class T>
class linkedList {
    struct Node {
        T data;
        Node* next;
    public:
        Node(T data) : next(nullptr){
            this->data = *new T(data);
        }

        T& operator*() { return data; }

    };

    Node* head;
    int size;

public:

    linkedList() : head(nullptr), size(0) {}

    explicit linkedList(T data) : size(1) {
        head = new Node(data);
    }

    ~linkedList(){
        Node* ptr = head;
        while(ptr!= nullptr){
            Node* del = ptr;
            ptr=ptr->next;
            delete del;
        }
    }

    int getSize () { return size; }

    class Iterator {

        Node* current;

        Node* operator*() { return current; }

    public:

        Iterator(Node* head): current(head) {}

        T& getData(){ return current->data; }

        bool operator==(const Iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const Iterator &rhs) const {
            return !(current == rhs.current);
        }

        Iterator& operator++(){
            current=current->next;
            return *this;
        }

        Iterator operator++(int){
            Iterator result = *this;
            ++*this;
            return result;
        }
    };

    class NotFound : public std::exception {
        virtual const char *what() const throw() {
            return "Not Found!";
        }
    };

    T* Find (int key) {
        Node* it = head;
        while (it && it->key != key){
            it = it->next;
        }
        if (it) return it->data;
        else throw NotFound();
    }

    Iterator insert (T data) {
        Node *node = new Node(data);
        node->next = head;
        head = node;
        size++;
        return node;
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }


    friend std::ostream& operator<<(std::ostream &os, linkedList &list) {
        Iterator it(list.head);
        os << "head-> ";
        for(it = list.begin(); it!=list.end() ; ++it){
            os << (it.getData()) << " -> ";
        }
        os << "NULL";
        return os;
    }

};

#endif //CONFIGURE_LINKEDLIST_H
