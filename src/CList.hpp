/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 25, 2021
 * 
 */
#ifndef CLIST_HPP_
#define CLIST_HPP_

#include "enums.hpp"
#include <iostream>
#include "Player.hpp"
#include <string>
#include "tools.hpp"

using namespace std;

template <class T> class CList;

//-----------------------------------------------------------------------------
template <class T> class Cell { // Dependent class. Points to another Cell.
    friend class CList<T>;
    private:
        T data;
        Cell<T>* next;

    Cell(T in, Cell* nx){data = in;next = nx;}
    ~Cell(){cout << data->getName() << " deleted.\n"; delete data;}
};

//-----------------------------------------------------------------------------
template <class T> class CList {
public:
private:
    int counter = 0;
    Cell<T>* head = NULL;
    Cell<T>* tail = NULL;
    Cell<T>* curr = NULL;      // Tracks the current Cell
    Cell<T>* prevCurr = NULL;  // Tracks the Cell prior to current Cell

public:
    CList() = default; // Initialize list to empty
    ~CList() {
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
        cout << "Deleting CList.\n";
    }
    int count(){return counter;}
    bool empty() const {return counter == 0;}
    ostream& print(ostream& out) const;
    void addItem(T in);
    void init(){curr = head; prevCurr = tail;}
    T next();
    void remove();
};

template <class T>
inline ostream& operator <<( ostream& out, CList<T>& cl ) {
	return cl.print(out);
}

template <class T>
void
CList<T>::addItem(T in) {
    if (empty()) {
        head = new Cell<T>(in, head);
        tail = head;
        cout << "Head (First Cell):\n";
        cout << "\tPlayer Name:  " << in->getName() << "\n";
        cout << "\tPlayer Color: " << colors[in->color()] << "\n";
    } else {
        tail->next = new Cell<T>(in, head);
        tail = tail->next;  // New tail
        tail->next = head;  // Point back to head from tail
        cout << "New Tail:\n";
        cout << "\tPlayer Name:  " << in->getName() << "\n";
        cout << "\tPlayer Color: " << colors[in->color()] << "\n";
    }
    counter++;  // Increment counter
}

template <class T>
T
CList<T>::next() {
    if (curr->next != curr) {
        if (curr == prevCurr) {
            curr = curr->next;
        } else {
            curr = curr->next;
            prevCurr = prevCurr->next;
        }
        cout << "New Current Player:\n";
    } else
        cout << "Current Player:\n";
    cout << "\tPlayer Name:  " << curr->data->getName() << "\n";
    cout << "\tPlayer Color: " << colors[curr->data->color()] << "\n";
    return curr->data;
}

template <class T>
ostream&
CList<T>::print(ostream& out) const {
    if (empty()) {
        out << "The CList is empty...\n";
        return out;
    }
    Cell<T>* temp = head;
    int tempCount = 0;
    while (temp->next != NULL && tempCount < counter) {
        out << "Player " << tempCount+1 << ":\n";
        out << "\tPlayer Name:  " << temp->data->getName() << "\n";
        out << "\tPlayer Color: " << colors[temp->data->color()] << "\n";
        temp = temp->next;
        tempCount++;
    }
    out << "\nHead Pointer:    " << head->data->getName() << "\n";
    out << "Prev. Pointer:   " << prevCurr->data->getName() << "\n";
    out << "Current Pointer: " << curr->data->getName() << "\n";
    out << "Tail Pointer:    " << tail->data->getName();
    return out;
}

template <class T>
void
CList<T>::remove() {
    if (curr == head)
        head = curr->next;
    else if (curr == tail)
        tail = prevCurr;
    Cell<T>* temp = curr;
    curr = curr->next;
    prevCurr->next = curr;
    delete temp;
    counter--;

    // Check for single Cell or empty list
    if (counter == 0) {
        head = NULL;
        tail = NULL;
        curr = NULL;
        prevCurr = NULL;
    } else if (counter == 1) {
        curr = head;
        prevCurr = head;
        tail = head;
    }
}

#endif /* CLIST_HPP_ */
