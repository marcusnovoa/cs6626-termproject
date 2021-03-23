/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 22, 2021
 * 
 */
#include "CList.hpp"

CList::~CList() {
    while (head != NULL) {
        curr = head;
        head = head->next;
        delete curr;
    }
    cout << "Deleting CList.\n";
}

void
CList::addItem(Player* p) {
    if (empty()) {
        head = new Cell(p->getName(), p->color(), head);
        tail = head;
        cout << "Head (First Cell):\n";
        cout << "\tPlayer Name:  " << p->getName() << "\n";
        cout << "\tPlayer Color: " << colors[p->color()] << "\n";
    } else {
        tail->next = new Cell(p->getName(), p->color(), head);
        tail = tail->next;  // New tail
        tail->next = head;  // Point back to head from tail
        cout << "New Tail:\n";
        cout << "\tPlayer Name:  " << p->getName() << "\n";
        cout << "\tPlayer Color: " << colors[p->color()] << "\n";
    }
    counter++;  // Increment counter
}

Player*
CList::next() {
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

ostream&
CList::print(ostream& out) const {
    if (empty()) {
        out << "The CList is empty...\n";
        return out;
    }
    Cell* temp = head;
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

void
CList::remove() {
    if (curr == head)
        head = curr->next;
    else if (curr == tail)
        tail = prevCurr;
    Cell* temp = curr;
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
