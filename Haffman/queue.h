#pragma once
#include "elem.h"
template<class T>
class Elem {
public:
    Elem<T>* next;
    T* value;
    Elem(T* elem_value, Elem* elem_next) {
        value = elem_value;
        next = elem_next;
    }
};

template<class T>
class queue {
private:
    size_t size;
    Elem<T>* begin, * end;
public:
    queue() {
        size = 0;
        begin = nullptr;
        end = nullptr;
    }

    ~queue() {
        clear();
    }

    Node* front() {
        return begin->value;
    }

    Node* back() {
        return end->value;
    }

    bool isEmpty() {
        if (size == 0) return true;
        else return false;
    }

    size_t getSize() {
        return size;
    }

    void push(Node* value) {
        Elem* temp = new Elem(value, nullptr);
        if (isEmpty()) begin = temp;
        else end->next = temp;
        end = temp;
        size++;
    }

    void pop() {
        Elem* temp = begin;
        begin = begin->next;
        delete temp;
        size--;
    }

    void clear() {
        while (!isEmpty()) pop();
    }
};