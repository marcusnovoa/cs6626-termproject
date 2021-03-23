/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 22, 2021
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

class CList;

//-----------------------------------------------------------------------------
class Cell { // Dependent class. Holds a Player and points to another Cell.
    friend class CList;
    private:
        Player* data;
        Cell* next;

    Cell(string nm, ColorEnum c, Cell* nx){data = new Player(nm, c);next = nx;}
    ~Cell(){cout << data->getName() << " deleted.\n"; delete data;}
};

//-----------------------------------------------------------------------------
class CList {
public:
private:
    int counter = 0;
    Cell* head = NULL;
    Cell* tail = NULL;
    Cell* curr = NULL;      // Tracks the current Cell
    Cell* prevCurr = NULL;  // Tracks the Cell prior to current Cell

public:
    CList() = default; // Initialize list to empty
    ~CList(); // Delete all cells in list
    int count(){return counter;}
    bool empty() const {return counter == 0;}
    ostream& print(ostream& out) const;
    void addItem(Player* p);
    void init(){curr = head; prevCurr = tail;}
    Player* next();
    void remove();
};

inline ostream& operator <<( ostream& out, CList& cl ) {
	return cl.print(out);
}

#endif /* CLIST_HPP_ */
