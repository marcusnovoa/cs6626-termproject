/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Feb 13, 2021
 *
 */
#ifndef COLUMN_HPP_
#define COLUMN_HPP_

#include "enums.hpp"
#include <iostream>
#include "Player.hpp"

#define MARKER_COLORS_LEN 5 // Number of available marker colors

using namespace std;

class Column {
public:
    Column(int colNumber);
    ~Column(){delete [] markers;};
    ColumnState getState(){return state;};
//    ostream& getNumOfSquares(ostream& out) const;
    ostream& print(ostream& out) const;
    static const ostream& printBanner(ostream& out);
    bool startTower(Player* p);
    bool move();
    void stop(Player* p);
    void bust() {};

private:
    static const int numOfSquares[13];  // Number of squares in every column
    int number;                         // The column number
    ColumnState state;                  // State: available, pending, captured
    int* markers;                       // Column contents regarding markers

};

inline ostream& operator <<( ostream& out, Column& c ) {
	return c.print(out);
}

#endif /* COLUMN_HPP_ */
