/*
 * Created by Marcus Novoa & Brandon Olah
 * Last Updated: Mar 29, 2021
 *
 */
#include "Column.hpp"

const int Column::numOfSquares[13] = {
    0, 0, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3    // Column lengths
};

Column::Column(int colNumber) : number(colNumber), state(available) {};

ostream&
Column::print(ostream& out) const {
    out << "Column: " << setw(2) << number << " ";
    out << "State: " << columnStates[state] << " ";

    for (int n = 1; n <= numOfSquares[number]; ++n) {
    	out << "| ";
    	for(int c = 0; c < MARKER_COLORS_LEN; ++c) {
            if ( markers[c] <= 0 )
            	out << '-';
            else if(n == markers[c])
            	out << markerColors[c];
            else
            	out << '-';
    	}
    	out << " ";
    }
    out << "|" << endl;
	return out;
};

const bool
Column::startTower(Player* p) {
	if ( markers[p->color()] <= 0 ) { // If player has no marker in the column
	    markers[0] = 1;             // Place a tower at position 1
	    return true;
	}
	else {
	    markers[0] = markers[p->color()] + 1;   // Place tower 1 space after marker
	    if(markers[0] == numOfSquares[number]) state = pending;
	    return true;
	}
	return false;
};

const bool
Column::move() {
	if ( markers[0] < numOfSquares[number] ) markers[0]++;
	else return false;
	if ( markers[0] == numOfSquares[number] ) state = pending;
	return true;
};

void
Column::stop(Player* pp) {
    markers[pp->color()] = markers[0];   // Set the tower to a colored tile
    markers[0] = 0;                      // Remove the tower
    if ( state == pending )              // If the column state is pending
        state = captured;                // Set the state to captured
    pp->wonColumn(number);               // Player wins column number
};
